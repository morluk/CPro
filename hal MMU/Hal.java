import java.util.*; //Vector, Scanner
import java.util.logging.ConsoleHandler;
import java.util.logging.FileHandler;
import java.util.logging.Handler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;
import java.io.*; //File, BufferedReader

/**
 * HAL Prozessor
 * hat 2 MMU fuer programmspeicher (2k) und register (4k). Wortbreite 16Bit. 
 * Jetzige Variante laeuft nicht ueber HalOS. Noch wird bei DUMPPROG und DUMPREG ueber stdout ausgeben. CheckBuffer wird Fehler melden. 
 * String und int Buffer bzw 2facher stdOut Buffer waeren noetig. Problem: Bufferabfrage
 * @author moritz
 *
 */

public class Hal extends Thread {
	private Harddisk hd = new Harddisk();
	private List<TextSeite> programmspeicher = new ArrayList<TextSeite>(2);
	private List<DataSeite> register = new ArrayList<DataSeite>(4);
	private int akkumulator;
	private String sourceFile;
	private Vector<Buffer> ioUnits = new Vector<Buffer>();
	private static Logger logger = Logger.getLogger("SeitenfehlerLogger");
	private static FileHandler fh;
	private int AnzSeitenfehlerData = 0;
	private int AnzSeitenfehlerText = 0;
	//Da Programm nummeriert ist und relative Spruenge machen kann. Befehle sind im Textsegment nicht benachbart. Wg Zeilennummerierung.
	private Map<Integer, Integer> effectivePC = new HashMap<Integer, Integer>();

	public void setIoUnits(Buffer ioUnit, int pos) {
		// Buffer existiert noch nicht
		while (ioUnits.size() <= pos) {
			ioUnits.addElement(null);
		}
		ioUnits.set(pos, ioUnit);
	}

	private boolean isIoUnitSet(int pos) {
		if (pos < ioUnits.size()) {
			if (ioUnits.get(pos) == null) {
				return false;
			} else {
				return true;
			}
		} else {
			return false;
		}
	}

	/**
	 * prueft ob im HAL Programm nur gesetzte Buffer angesprochen werden. eventl
	 * verbessern, dass bei Einlesen direkt geprueft wird!!!!! Nicht ueber
	 * ganzes Array laufen
	 */
	public boolean checkBuffer() {
		boolean result = true;
		for (int i = 0; i < hd.getTextSeitenCount(); i++) {
			for (Command currCommand : hd.getTextSeite(i)) {
				if (currCommand != null) {
					if (currCommand.instruction.equals("IN")
							|| currCommand.instruction.equals("OUT")) {
						if (!isIoUnitSet(currCommand.parameter)) {
							result = false;
						}
					}
				}
			}
		}
		return result;
	}

	/**
	 * MMU fuer Register(DataSegment) ACHTUNG: WEGSCHREIBEN. NICHT LÖSCHEN!!!!
	 * 
	 * @param virtualAdr
	 * @return is physical Adress
	 */
	private int getPhysAdrOfDataSeg(int virtualAdr) {
		int seitenNr = virtualAdr / 1024;
		int physAdr = -1;
		for (int i = 0; i < register.size(); i++) {
			if (register.get(i).seiteninfo.seitenNr == seitenNr) {
				// Wenn Seite vorhanden physAdr = SeitenNr + Offset
				physAdr = (i * 1024) + (virtualAdr % 1024);
				break;
			}
		}
		// Wenn Seite nicht gefunden wurde loesche erste und lade neue Seite als
		// Letze (FIFO)
		if (physAdr == -1) {
			if (register.get(0).seiteninfo.modifiedBit == true) {
				hd.setDataSeite(register.get(0).seite, register.get(0).seiteninfo.seitenNr); //wahrscheinlich unnoetig da Refferenz. Noch wird nirgends MBit gesetzt
			}
			register.remove(0);
			register.add(new DataSeite(hd.getDataSeite(virtualAdr / 1024)));
			// setze SeitenInfo Bits
			register.get(register.size() - 1).seiteninfo.seitenNr = virtualAdr / 1024;
			physAdr = (register.size() - 1) * 1024 + (virtualAdr % 1024);
			// Log
			AnzSeitenfehlerData++;
			logger.log(Level.INFO, "Seitenfehler (Data) Nr: " + AnzSeitenfehlerData
					+ " bei Adr: " + virtualAdr);
		}
		return physAdr;
	}

	/**
	 * MMU fuer programmspeicher(TextSegment)
	 * 
	 * @param virtualAdr
	 * @return is physical Adress
	 */
	private int getPhysAdrOfTextSeg(int virtualAdr) {
		int seitenNr = virtualAdr / 1024;
		int physAdr = -1;
		for (int i = 0; i < programmspeicher.size(); i++) {
			if (programmspeicher.get(i).seiteninfo.seitenNr == seitenNr) {
				// Wenn Seite vorhanden physAdr = SeitenNr + Offset
				physAdr = (i * 1024) + (virtualAdr % 1024);
				break;
			}
		}
		// Wenn Seite nicht gefunden wurde loesche erste und lade neue Seite als
		// Letze (FIFO)
		if (physAdr == -1) {
			programmspeicher.remove(0);
			programmspeicher.add(new TextSeite(hd
					.getTextSeite(virtualAdr / 1024)));
			// setze SeitenInfo Bits
			programmspeicher.get(programmspeicher.size() - 1).seiteninfo.seitenNr = virtualAdr / 1024;
			physAdr = (programmspeicher.size() - 1) * 1024 + (virtualAdr%1024);
			// Log
			AnzSeitenfehlerText++;
			logger.log(Level.INFO, "Seitenfehler (Text) Nr: " + AnzSeitenfehlerText
					+ " bei Adr: " + virtualAdr);
		}
		return physAdr;
	}

	/**
	 * Konstruktor liest Programm aus filename ein. Checks Syntax. Hal extends
	 * thread
	 * 
	 * @param prozessorName
	 * @param filename
	 */
	public Hal(String prozessorName, String filename) { // Standard Konstruktor
		super(prozessorName);
		sourceFile = filename;
		// Programmspeichergroesse 2k
		programmspeicher.add(0, new TextSeite());
		programmspeicher.add(1, new TextSeite());
		// Registergroesse 4k
		register.add(0, new DataSeite());
		register.add(1, new DataSeite());
		register.add(2, new DataSeite());
		register.add(3, new DataSeite());
		// Logger
		//remove ConsoleHandler
		logger.setUseParentHandlers(false);
		Handler[] handlers = logger.getHandlers();
		for(Handler handler : handlers)
		{
		        if(handler.getClass() == ConsoleHandler.class)
		            logger.removeHandler(handler);
		}
		//add FileHandler
		try {
			fh = new FileHandler(
					"%t/SeitenFehlerLogFile.log", false);
		} catch (SecurityException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		logger.addHandler(fh);
		logger.setLevel(Level.INFO);
		SimpleFormatter formatter = new SimpleFormatter();
		fh.setFormatter(formatter);

		this.readFile();
	}

	public void run() {
		for (int i = 0; i < 10; i++) {
			hd.setDataValueAt(0, 0, i); // interne Reg(0-9) initial auf 0
		}
		// Programmausfuehrung
		while (interpretNextInstr() != -1)
			;
	}

	// Gibt 1 fuer ok, und -1 fuer Abbruch zurueck
	private int interpretNextInstr() {
		int physAdrParam = -1; // Initialisierung
		// hole naechsten Befehl
		int physAdrPC = this.getPhysAdrOfDataSeg(0);
		int valuePC = register.get(physAdrPC / 1024).seite[physAdrPC % 1024];
		int physAdrCurrInstr = this.getPhysAdrOfTextSeg(valuePC);
		Command currInstr = programmspeicher.get(physAdrCurrInstr / 1024).seite[physAdrCurrInstr % 1024];
		// PC ++
		register.get(physAdrPC / 1024).seite[physAdrPC % 1024] = ++valuePC;
		// bestimme Befehlstyp, bestimme ggf Operanden, fuehre Instruktion aus
		switch (currInstr.instruction) {
		case "START":
			break;
		case "STOP":
			return -1;
		case "OUT":
			System.out.println("Ausgabe auf Kanal " +currInstr.parameter + ": " + akkumulator);
//			ioUnits.get(currInstr.parameter).put(akkumulator);
			break;
		case "IN":
			System.out.println("Eingabe auf Kanal " + currInstr.parameter + ":");
			Scanner in;
			in = new Scanner(System.in);
			akkumulator = in.nextInt();
//			int number = ioUnits.get(currInstr.parameter).get();
//			akkumulator = number;
			break;
		case "LOAD":
			physAdrParam = this.getPhysAdrOfDataSeg(currInstr.parameter);
			akkumulator = register.get(physAdrParam / 1024).seite[physAdrParam % 1024];
			break;
		case "LOADNUM":
			akkumulator = currInstr.parameter;
			break;
		case "STORE":
			physAdrParam = this.getPhysAdrOfDataSeg(currInstr.parameter);
			register.get(physAdrParam / 1024).seite[physAdrParam % 1024] = akkumulator;
			break;
		case "JUMPNEG":
			if (akkumulator < 0) {
				register.get(physAdrPC / 1024).seite[physAdrPC % 1024] = currInstr.parameter;
			}
			break;
		case "JUMPPOS":
			if (akkumulator > 0) {
				register.get(physAdrPC / 1024).seite[physAdrPC % 1024] = currInstr.parameter;
			}
			break;
		case "JUMPNULL":
			if (akkumulator == 0) {
				register.get(physAdrPC / 1024).seite[physAdrPC % 1024] = currInstr.parameter;
			}
			break;
		case "JUMP":
			register.get(physAdrPC / 1024).seite[physAdrPC % 1024] = currInstr.parameter;
			break;
		case "ADD":
			physAdrParam = this.getPhysAdrOfDataSeg(currInstr.parameter);
			akkumulator += register.get(physAdrParam / 1024).seite[physAdrParam % 1024];
			break;
		case "ADDNUM":
			akkumulator += currInstr.parameter;
			break;
		case "SUB":
			physAdrParam = this.getPhysAdrOfDataSeg(currInstr.parameter);
			akkumulator -= register.get(physAdrParam / 1024).seite[physAdrParam % 1024];
			break;
		case "SUBNUM":
			akkumulator -= currInstr.parameter;
			break;
		case "MUL":
			physAdrParam = this.getPhysAdrOfDataSeg(currInstr.parameter);
			akkumulator *= register.get(physAdrParam / 1024).seite[physAdrParam % 1024];
			break;
		case "MULNUM":
			akkumulator *= currInstr.parameter;
			break;
		case "DIV":
			physAdrParam = this.getPhysAdrOfDataSeg(currInstr.parameter);
			akkumulator /= register.get(physAdrParam / 1024).seite[physAdrParam % 1024];
			break;
		case "DIVNUM":
			akkumulator /= currInstr.parameter;
			break;
		case "LOADIND":
			physAdrParam = this.getPhysAdrOfDataSeg(currInstr.parameter);
			int virtAdrRegister = register.get(physAdrParam / 1024).seite[physAdrParam % 1024];
			int physAdrRegister = this.getPhysAdrOfDataSeg(virtAdrRegister);
			akkumulator = register.get(physAdrRegister / 1024).seite[physAdrRegister % 1024];
			break;
		case "STOREIND":
			physAdrParam = this.getPhysAdrOfDataSeg(currInstr.parameter);
			int virtAdrRegisterSTR = register.get(physAdrParam / 1024).seite[physAdrParam % 1024];
			int physAdrRegisterSTR = this.getPhysAdrOfDataSeg(virtAdrRegisterSTR);
			register.get(physAdrRegisterSTR / 1024).seite[physAdrRegisterSTR % 1024] = akkumulator;
			break;
		case "DUMPREG":
			int physAdrSeite = -1;
			System.out.println("===DUMPREG Kanal 1===");
//			for (int i=0; i<(hd.getDataSeitenCount()*1024);i+=1024) {
//				physAdrSeite = this.getPhysAdrOfDataSeg(i);
//				for (int j=0; j<1024; j++) {
//					System.out.println((i+j) + " : " + register.get(physAdrSeite/1024).seite[j]);
////					ioUnits.get(1).put(register.get(physAdrSeite/1024).seite[j]);
//				}
//			}
			for (int i=0; i<register.size();i++) {
				for (int j=0; j<1024; j++) {
					System.out.println((i*1024+j) + " : " + register.get(i).seite[j]);
				}
			}
			break;
		case "DUMPPROG":
			int physAdrSeite1 = -1;
			System.out.println("===DUMPPROG Kanal 2===");
//			for (int i=0; i<(hd.getTextSeitenCount()*1024);i+=1024) {
//				physAdrSeite1 = this.getPhysAdrOfTextSeg(i);
//				for (int j=0; j<1024; j++) {
//					System.out.println((i+j) + " : " + programmspeicher.get(physAdrSeite1/1024).seite[j]);
////					ioUnits.get(2).put(programmspeicher.get(physAdrSeite/1024).seite[j]);
//				}
//			}
			for (int i=0; i<programmspeicher.size();i++) {
				for (int j=0; j<1024; j++) {
					System.out.println((i*1024+j) + " : " + programmspeicher.get(i).seite[j]);
				}
			}
			break;
		default:
			System.err.println("Ungueltiger Befehl: " + currInstr + "!");
			break;
		}
		return 1;
	}

	// prueft HAL Code auf gueltige Syntax und gibt 1 fuer ok, oder -1 fuer
	// nicht ok zurueck
	private int checkSyntax(Command currInstr) {
		// check START
		if (currInstr.instruction.equals("START") && currInstr.parameter == 0) {
			return 1;
		}
		// check STOP
		else if (currInstr.instruction.equals("STOP")
				&& currInstr.parameter == 0) {
			return 1;
		}
		// check DUMPREG
		else if (currInstr.instruction.equals("DUMPREG")
				&& currInstr.parameter == 0) {
			return 1;
		}
		// check DUMPPROG
		else if (currInstr.instruction.equals("DUMPPROG")
				&& currInstr.parameter == 0) {
			return 1;
		}
		// HAL Befehle mit Parameter
		switch (currInstr.instruction) {
		case "OUT":
		case "IN":
		case "LOAD":
		case "LOADNUM":
		case "STORE":
		case "JUMPNEG":
		case "JUMPPOS":
		case "JUMPNULL":
		case "JUMP":
		case "ADD":
		case "ADDNUM":
		case "SUB":
		case "SUBNUM":
		case "MUL":
		case "MULNUM":
		case "DIV":
		case "DIVNUM":
		case "LOADIND" :
		case "STOREIND" :
			if (currInstr.parameter >= 0) {
				// pruefe auf Negativen Opperand
				return 1;
			}
			break;

		default:
			return -1;
		}
		return -1;
	}

	// liest hal Programm in virtuellen Programmspeicher ein
	// checks Syntax vor Speichern
	private void readFile() {

		File inputFile = new File(sourceFile);

		BufferedReader in;
		try {
			in = new BufferedReader(new FileReader(inputFile)); // zeichenweise
			String line;
			int valuePC = 0;

			while ((line = in.readLine()) != null) {
				if (!line.startsWith("#")) {
					// Zeilen mit # sind Kommentare
					String[] lineSplitted = line.split(" ");
					Command command = new Command();
					int position = Integer.parseInt(lineSplitted[0]);
					command.instruction = lineSplitted[1];
					if (lineSplitted.length == 3) {
						command.parameter = Integer.parseInt(lineSplitted[2]);
					}
					// check Syntax
					int p;
					if ((p = this.checkSyntax(command)) < 0) {
						System.err
								.println("Ungueltige Syntax des HAL Programms bei Befehl "
										+ command + " !");
						System.exit(1);
					}
					effectivePC.put(position, valuePC);
					if (command.instruction.contains("JUMP")) {
						command.parameter = effectivePC.get(command.parameter);
					}
					hd.addTextAt(command, valuePC / 1024, valuePC % 1024);
					valuePC++;		
				}
			}

			in.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		// Lege hal Obj an und starte Programm
		Hal prozessor = new Hal("Thread1", "praktikum5.hal");
		prozessor.start();
	}
}

class Command {
	public String instruction;
	public int parameter;

	Command() {
		instruction = new String();
		parameter = 0;
	}

	public String toString() {
		return (String) instruction + " " + parameter;
	}
}

class SeitenInfo {
	public int seitenNr;
	public boolean presentBit;
	public boolean modifiedBit;
	public String schutzBit;
	public boolean referenziertBit;

	SeitenInfo() {
		seitenNr = -1;
		presentBit = false;
		modifiedBit = false;
		schutzBit = "rw";
		referenziertBit = false;
	}
}

class DataSeite {
	public SeitenInfo seiteninfo;
	public int[] seite;

	DataSeite() {
		seiteninfo = new SeitenInfo();
		seite = new int[1024];
	}

	DataSeite(int[] seite) {
		seiteninfo = new SeitenInfo();
		this.seite = seite;
	}
}

class TextSeite {
	public SeitenInfo seiteninfo;
	public Command[] seite;

	TextSeite() {
		seiteninfo = new SeitenInfo();
		seite = new Command[1024];
	}

	TextSeite(Command[] seite) {
		seiteninfo = new SeitenInfo();
		this.seite = seite;
	}
}
