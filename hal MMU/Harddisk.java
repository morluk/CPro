/**
 * Ist virtueller Speicher von HAL 
 * Groesse 2¹⁶ Adressen je Daten und ProgrammSegment unterteilt in 64 Seiten a 1k
 * @author moritz
 *
 */
public class Harddisk {
	private int dataSegment[][] = new int[64][1024]; // (Reg0-9 intern; Reg0 PC)
	private Command textSegment[][] = new Command[64][1024];
	
	Harddisk() {};
	
	public void addTextAt(Command command, int seite, int offset) {
		textSegment[seite][offset] = command;
	}
	
	public Command[] getTextSeite(int seite) {
		return textSegment[seite];
	}
	
	public void setTextSeite(Command[] seite, int seitenNr) {
		textSegment[seitenNr] = seite;
	}
	
	public int getTextSeitenCount() {
		return textSegment.length;
	}
	
	public void setDataValueAt(int value, int seite, int offset) {
		dataSegment[seite][offset] = value;
	}
	
	public int[] getDataSeite(int seite) {
		return dataSegment[seite];
	}
	
	public void setDataSeite(int[] seite, int seitenNr) {
		dataSegment[seitenNr] = seite;
	}
	
	public int getDataSeitenCount() {
		return dataSegment.length;
	}
	
	public static void main(String[] args) {
		Harddisk hd = new Harddisk();
		System.out.println(hd.getDataSeitenCount());
	}
}
