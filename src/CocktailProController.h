//@(#) CocktailProController.h

#ifndef COCKTAILPROCONTROLLER_H_H
#define COCKTAILPROCONTROLLER_H_H

#include "ObserverWaage.h"
#include "Waage.h"
#include "Dosierstation.h"
#include "Entleerer.h"
#include "MischbaresRezeptbuch.h"
#include "Mischer.h"
#include "Stampfer.h"
#include "UserInterface.h"
#include <string>
#include <vector>

using namespace std;

//Input Output UserInterface. Konsolenapplikation
class UserInterface;

//Legt Komponenten (Dosierstation, Stampfer, ..) an und koordiniert sie durch die Rezeptschritte
class CocktailProController {
public:
	CocktailProController();

	CocktailProController(UserInterface* userInterface);

	string mischbareRezepteToString();

	void mischeRezept(int index);

private:
	vector<Dosierstation> dosierstation;

	Entleerer entleerer;

	MischbaresRezeptbuch mischbaresRezeptbuch;

	Mischer mischer;

	Stampfer stampfer;

	UserInterface* userInterface;

	Waage waage;

	void init();
};

#endif
