//@(#) UserInterface.h

#ifndef USERINTERFACE_H_H
#define USERINTERFACE_H_H

#include "ObserverWaage.h"
#include "Waage.h"
#include "CocktailProController.h"
#include "Entleerer.h"
#include <fstream>
#include <iostream>
#include <sstream>

//Legt Komponenten (Dosierstation, Stampfer, ..) an und koordiniert sie durch die Rezeptschritte
class CocktailProController;

//Input Output UserInterface. Konsolenapplikation
class UserInterface: public Observer {
public:
	void setWaage(Waage* waage);

	void showMenu();

	void update();

	UserInterface();

	virtual ~UserInterface();

	void setCocktailProController(CocktailProController* cocktailProController);

	void showString(string str) {
		cout << str;
		cout.flush();
	}

private:
	CocktailProController* cocktailProController;

	Waage* waage;

};

#endif
