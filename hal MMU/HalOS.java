import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Vector;

/**
 * In configFile muessen die Prozessoren mit 0 beginnend aufsteigend nummeriert sein!
 * keine Spruenge in der Nummerierung.
 * Es sind beliebig viele HAL Interpreter mit beliebig vielen IO Buffern moeglich.
 * Es kann jeder mit jedem kommunizieren.
 * @author moritz
 *
 */

public class HalOS {
	private List<Hal> prozessoren;
	private Vector<Buffer> buffer;
	private Buffer stdout, stdin;
	
	/**
	 * boot() wird aufgerufen
	 * @param configFile
	 */
	public HalOS(String configFile) {
		prozessoren = new ArrayList<Hal>();
		buffer = new Vector<Buffer>();
		stdout = new Buffer(10);
		stdin = new Buffer(10);
		this.boot(configFile);
	}
	
	public Buffer getStdout() {
		return stdout;
	}

	public Buffer getStdin() {
		return stdin;
	}

	/**
	 * Liest ConfigFile und initialisiert HALs und zugehoerige Buffer
	 * und verbindet diese entsprechend
	 * @param configFile
	 */
	private void boot(String configFile) {
		//read configFile
		File inputFile = new File(configFile);

		BufferedReader in;
		try {
			in = new BufferedReader(new FileReader(inputFile)); // zeichenweise
			String line;

			while ((line = in.readLine()) != null) {
				//liest Prozessoren
				//liest Ueberschrift weg
				if (line.equals("HAL - Prozessoren:")) {
					line = in.readLine();
					while (!line.equals("HAL - Verbindungen:")) {
						String[] lineSplitted = line.split(" ");
						prozessoren.add(new Hal(lineSplitted[0], lineSplitted[1]));
						line = in.readLine();
					}
				}
				//liest IO Verbindungen
				//liest Ueberschrift weg
				//Buffer fuer stdin
				else if (line.contains("x:x > ")) {
					buffer.add(new Buffer(10));
					String[] lineSplittedOnce = line.split(">");
					String[] lineHalNN = lineSplittedOnce[1].split(":");
					int halN = Integer.parseInt(lineHalNN[0].trim());
					int halBuffer = Integer.parseInt(lineHalNN[1].trim());
					prozessoren.get(halN).setIoUnits(buffer.lastElement(), halBuffer);
					stdin = buffer.lastElement();
				}
				//Buffer fuer stdout
				else if (line.contains(" > x:x")) {
					buffer.add(new Buffer(10));
					String[] lineSplittedOnce = line.split(">");
					String[] lineHalN = lineSplittedOnce[0].split(":");
					int halN = Integer.parseInt(lineHalN[0].trim());
					int halBuffer = Integer.parseInt(lineHalN[1].trim());
					prozessoren.get(halN).setIoUnits(buffer.lastElement(), halBuffer);
					stdout = buffer.lastElement();
				}
				//InterprozessorenBuffer
				else {
				buffer.add(new Buffer(10));
				String[] lineSplittedOnce = line.split(">");
				String[] lineHalN = lineSplittedOnce[0].split(":");
				String[] lineHalNN = lineSplittedOnce[1].split(":");
 				int halN = Integer.parseInt(lineHalN[0].trim());
				int halNplus1 = Integer.parseInt(lineHalNN[0].trim());
				int halNBuffer = Integer.parseInt(lineHalN[1].trim());
				int halNplus1Buffer = Integer.parseInt(lineHalNN[1].trim());
				prozessoren.get(halN).setIoUnits(buffer.lastElement(), halNBuffer);
				prozessoren.get(halNplus1).setIoUnits(buffer.lastElement(), halNplus1Buffer);
				}
			}

			in.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		if (!this.checkProzessorenIO()) {
			System.err.println("Fehler bei Bufferpruefung!");
			System.exit(1);
		}
	}
	
	private boolean checkProzessorenIO() {
		boolean result = true;
		//ueber alle Prozessoren
		for (Hal currHal : prozessoren) {
			if (!currHal.checkBuffer()) {
				result = false;
			}
		}
		return result;
	}
	
	/**
	 * ruft start() der einzelnen Prozessoren Threads auf
	 */
	void runOS() {
		for (int i = 0; i < prozessoren.size(); i++) {
			prozessoren.get(i).start();
		}
	}
	
	boolean anyoneAlive() {
		boolean result = false;
		for (int i=0; i < prozessoren.size(); i++) {
			result = result || prozessoren.get(i).isAlive();
		}
		return result;
	}
	
	public static void main(String[] args) {
		// pruefe Programmaufruf
		if (args.length != 1) {
			System.err.println("usage: halOS sourceFile");
		}
		Scanner in;
		in = new Scanner(System.in);
		HalOS myOS = new HalOS(args[0]);
		myOS.runOS();
		int number = 0;
		while (myOS.anyoneAlive()) {			
			System.out.println("Initiale Eingabe fuer HalOS Berechnung:");
			number = in.nextInt();
			myOS.getStdin().put(number);
			System.out.println("Initiale Eingabe fuer HalOS Berechnung:");
			number = in.nextInt();
			myOS.getStdin().put(number);
			System.out.println(myOS.getStdout().get());
		}
		in.close();
	}

}
