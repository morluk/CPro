//@(#) MischbaresRezeptbuch.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Rezeptbuch.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

//Ermittelt aus Rezeptbuch und vorhandenen Dosierstationen die tatsaechlich mischbaren Rezepte
class MischbaresRezeptbuch: public Rezeptbuch {

public:
	//Liefert die Anzahl der verfügbaren Rezepte. 
	virtual int getAnzahlRezepte() {
		return mischbareRezepte.size();
	}

	//Liefert das i-te Rezept aus der Liste (Werte von 0..n-1).
	//Ansonsten NULL.
	virtual Rezept* getRezept(unsigned int i);

	//Löscht das i-te Rezept. Liefert bei Erfolg true, sonst false. 
	virtual bool deleteRezept(unsigned int i);

	MischbaresRezeptbuch();

	list<string> getZutatenListe();

private:
	//ermittelt aus Rezeptbuch die mischbaren Rezepte
	void calculateMischbareRezepte();

	//durchlaeuft ZutatenListe und gibt zurueck ob Zutat vorhanden ist
	bool istZutatVorhanden(string zutat);

	// oeffnet eine Datei, schreibt den Text in die uebergebene String-Liste,
	// liefert die Anzahl der gelesenen Zeilen zurueck
	int readZutatenListe(list<string>* lines, string FileName);

	vector<Rezept*> mischbareRezepte;

	list<string> zutaten;
};

#endif
