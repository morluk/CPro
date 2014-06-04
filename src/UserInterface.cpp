//@(#) UserInterface.cpp

#include "UserInterface.h"

void UserInterface::update() {
	//TODO: implement
	cout << this->waage->getAbsolutGewicht() << endl;
}

void UserInterface::setWaage(Waage* waage) {
	this->waage = waage;
}

UserInterface::UserInterface() {
	this->waage = 0;
	this->cocktailProController = new CocktailProController(this);

	//TODO: dies ist nur ein test
	this->cocktailProController->mischeRezept(0);
}

void UserInterface::showMenu() {
	//TODO: implement
}

UserInterface::~UserInterface() {

}

