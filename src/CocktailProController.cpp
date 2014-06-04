//@(#) CocktailProController.cpp

#include "CocktailProController.h"

void CocktailProController::mischeRezept(int index) {
	//TODO: implement (das ist nur ein test)
	dosierstationen.at(0)->fuelleAb(100);
}

string CocktailProController::mischbareRezepteToString() {
	//TODO: implement
	return "";
}

CocktailProController::CocktailProController(UserInterface* userInterface) {
	this->userInterface = userInterface;
	this->init();
}

void CocktailProController::init() {
	Simulation* simulation = this->entleerer.initSimulation();
	list<string> zutaten = this->mischbaresRezeptbuch.getZutatenListe();
	for (list<string>::iterator it = zutaten.begin(); it != zutaten.end();
			++it) {

		//TODO: art richtig auswaehlen, momentan immer fluessig
		Dosierstation* dosierstation = new Dosierstation(fluessig, *it);
		//---------------------------------------------------------------

		dosierstation->setWaage(&this->waage);
		dosierstation->setSimulation(simulation);
		this->waage.attach(dosierstation);
		this->dosierstationen.push_back(dosierstation);
	}

	this->entleerer.setWaage(&this->waage);
	this->userInterface->setWaage(&this->waage);
	simulation->setWaage(&this->waage);

	this->waage.attach(userInterface);
	this->waage.attach(&this->entleerer);
}

CocktailProController::CocktailProController() {
	this->userInterface = 0;
	this->init();
}
