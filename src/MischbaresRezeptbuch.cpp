//@(#) MischbaresRezeptbuch.cpp


#include "MischbaresRezeptbuch.h"
//
MischbaresRezeptbuch::MischbaresRezeptbuch()
{
	const string FileName="zutaten.txt";
//	zutaten = list<string>();
	readZutatenListe(&zutaten, FileName);

	calculateMischbareRezepte();
}

/*Liefert das i-te Rezept aus der Liste (Werte von 0..n-1).
 *Ansonsten NULL.
 */
Rezept* MischbaresRezeptbuch::getRezept(unsigned int i)
{
	if (i >= 0 || i < mischbareRezepte.size()) {
		return mischbareRezepte[i];
	} else {
		return NULL;
	}

}

bool MischbaresRezeptbuch::istZutatVorhanden(string zutat) {
	bool istVorhanden = false;
	string stampfen = "Stampfen";
	string mischen = "Mischen";
	for (std::list<string>::iterator it=zutaten.begin(); it != zutaten.end(); ++it) {
		if (*it == zutat || zutat == stampfen || zutat == mischen) {
			istVorhanden = true;
			break;
		}
	}
	return istVorhanden;
}

// oeffnet eine Datei, schreibt den Text in die uebergebene String-Liste,
// liefert die Anzahl der gelesenen Zeilen zurueck
int MischbaresRezeptbuch::readZutatenListe(list<string>* lines, string FileName) {
	// Stream anlegen
		ifstream in;

		try {
		// Datei oeffnen
			in.open(FileName.c_str(), ios::in); // c_str wandelt den String in char[]
												 // das braucht fstream

			if( !in ) {// File konnte nicht geoeffnet werden
				string my_exception = "File not found: " + FileName;
				throw my_exception;
			}

			/* Daten lesen und in Liste eintragen */
			string zeile;
			while(getline(in, zeile)){
				   lines->push_back(zeile);
			}

			/* Datei wieder schliessen */
			in.close();

			/* und Groesse der Liste als Anzahl der Zeilen zurueck */
			return(lines->size());
		}
		catch (string exc){
			cerr << exc << endl;
			exit(1);
		}
}

void MischbaresRezeptbuch::calculateMischbareRezepte() {
	for (int i = 0; i < rezeptbuch.getAnzahlRezepte(); ++i) {
		bool rezeptMischbar = true;
		for (int j = 0; j < rezeptbuch.getRezept(i)->getAnzahlRezeptschritte(); ++j) {
			string aktZutat = rezeptbuch.getRezept(i)->getRezeptSchritt(j)->getZutat();
			if (!istZutatVorhanden(aktZutat)) {
				rezeptMischbar = false;
				break;
			}
		}
		if (rezeptMischbar) {
			mischbareRezepte.push_back(rezeptbuch.getRezept(i));
		}
	}
}

bool MischbaresRezeptbuch::deleteRezept(unsigned int i) {
	if (i >= 0 || i < mischbareRezepte.size()) {
			mischbareRezepte.erase(mischbareRezepte.begin()+i);
			return true;
		} else {
			return false;
		}
}
