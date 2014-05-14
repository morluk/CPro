//@(#) UserInterface.h

#ifndef USERINTERFACE_H_H
#define USERINTERFACE_H_H

#include "ObserverWaage.h"
#include "Waage.h"
#include "CocktailProController.h"

class CocktailProController;

//Input Output UserInterface. Konsolenapplikation
class UserInterface : ObserverWaage
{
public:
	//
	void setWaage(const Waage* waage);
	//
	void showMenu();
	//
	void update();
	//
	UserInterface();
	//
	virtual ~UserInterface();
	
private:
	//
	CocktailProController* cocktailProController;
	
	//
    Waage* waage;
	
};

#endif
