//@(#) MischbaresRezeptbuch.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "string.h"
#include "Rezeptbuch.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

//Ermittelt aus Rezeptbuch und vorhandenen Dosierstationen die tatsaechlich mischbaren Rezepte
class MischbaresRezeptbuch: public Rezeptbuch
{
	
public:
	//Liefert die Anzahl der verfügbaren Rezepte. 
	virtual int getAnzahlRezepte() {
		return mischbareRezepte.size();
	}

	//Liefert das i-te Rezept aus der Liste (Werte von 0..n-1).
	//Ansonsten NULL.
	// 
	virtual Rezept * getRezept(unsigned int i);

	//Löscht das i-te Rezept. Liefert bei Erfolg true, sonst false. 
	virtual bool deleteRezept(unsigned int i);

	//
	MischbaresRezeptbuch();
	
private:
	//ermittelt aus Rezeptbuch die mischbaren Rezepte
	void calculateMischbareRezepte();

	//durchlaeuft ZutatenListe und gibt zurueck ob Zutat vorhanden ist
	bool istZutatVorhanden(std::string zutat);

	// oeffnet eine Datei, schreibt den Text in die uebergebene String-Liste,
	// liefert die Anzahl der gelesenen Zeilen zurueck
	int readZutatenListe(std::list<std::string> * lines, std::string FileName);

	//
	std::vector<Rezept *> mischbareRezepte;
	
	//
	std::list<std::string> zutaten;
};

#endif
