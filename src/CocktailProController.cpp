//@(#) CocktailProController.cpp

#include "CocktailProController.h"

void CocktailProController::mischeRezept(int index) {

}

string CocktailProController::mischbareRezepteToString() {
	return string();
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
		Dosierstation dosierstation(fluessig, *it);
		dosierstation.setWaage(&this->waage);
		dosierstation.setSimulation(simulation);
		this->dosierstationen.push_back(dosierstation);
	}

	this->entleerer.setWaage(&this->waage);
	this->userInterface->setWaage(&this->waage);
	simulation->setWaage(&this->waage);

	//TODO: funktioniert nicht
	//this->waage.attach(userInterface);
}

CocktailProController::CocktailProController() {
	this->userInterface = 0;
	this->init();
}
