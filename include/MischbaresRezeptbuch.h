//@(#) MischbaresRezeptbuch.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Rezeptbuch.h"
#include <vector>

using namespace std;

//Ermittelt aus Rezeptbuch und vorhandenen Dosierstationen die tatsaechlich mischbaren Rezepte
class MischbaresRezeptbuch
{
	
public:
	//
	vector<Rezept*> getMischbareRezepte() const;
	//
	Rezept getMischbaresRezept(int index);
	//
	MischbaresRezeptbuch();
	
private:
	//
	vector<Rezept*> mischbareRezepte;
	
	//
	Rezeptbuch rezeptbuch;
	
	
};

#endif
