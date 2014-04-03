/********************************************************************************/
/*                  Einlesen einer Datei                           				*/
/********************************************************************************/
/*
 * erstellt am: 26.08.2006 
 * ueberarbeitet am 04.01.2012
 * Ralf Hahn
 */
 
#include <fstream>
#include <string>
#include <cstdlib> // fuer exit() unter Linux
#include <list>
#include <iostream>
using namespace std;

// oeffnet eine Datei, schreibt den Text in die uebergebene String-Liste,
// liefert die Anzahl der gelesenen Zeilen zurueck  
int einlesen(list<string>* lines, string FileName)
{
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


/* ************** Only for Test ******************** */

#include <iostream>
#include <string>
#include <list>
using namespace std;

int main ()
{
	const string FileName="zutaten.txt";

	list<string> lines; // hier kommen die Zeilen aus der Datei rein
	lines.clear();

	int LineNo = einlesen(&lines, FileName); // Datei einlesen !
	
	/* Ausgabe zur Ueberpruefung */
	
	cout << "******************\n";
	
		cout << "Zeilen: " << LineNo << "\n";
		list<string>::iterator j;  // Iterator vorwärts
		for(j=lines.begin(); j != lines.end(); j++) { 
			cout << *j << endl;   
		};
	cout << "******************\n";
   return 0;
}

