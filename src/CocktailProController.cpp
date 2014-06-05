//@(#) CocktailProController.cpp

#include "CocktailProController.h"

void CocktailProController::mischeRezept(int index) {
	Rezept* tempRezept = this->mischbaresRezeptbuch.getRezept(index);
	for (int i = 0; i < tempRezept->getAnzahlRezeptschritte(); i++) {
		if (tempRezept->getRezeptSchritt(i)->getZutat() == "Mischen") {
			this->userInterface->showString("\nMischer aktiviert\n");
			this->mischer->mix(tempRezept->getRezeptSchritt(i)->getMenge());
			this->userInterface->showString("\nMischer deaktiviert\n");
		} else if (tempRezept->getRezeptSchritt(i)->getZutat() == "Stampfen") {
			this->userInterface->showString("\nStampfer aktiviert\n");
			this->stampfer.stampfe(tempRezept->getRezeptSchritt(i)->getMenge());
			this->userInterface->showString("\nStampfer deaktiviert\n");
		} else {
			//finde Dosierstation zu Zutat
			int j;
			for (unsigned j = 0; j < this->dosierstationen.size(); j++) {
				if (dosierstationen[j]->getName()
						== tempRezept->getRezeptSchritt(i)->getZutat())
					break;
			}
			//fuelle ab
			this->userInterface->showString("\nVentil " + dosierstationen[j]->getName() + " geoeffnet\n");
			dosierstationen[j]->fuelleAb(
					tempRezept->getRezeptSchritt(i)->getMenge());
			std::stringstream ss;
			std::string s;
			ss << this->waage.getDeltaGewicht();
			ss >> s;
			this->userInterface->showString("Gesamtgewicht: " + s + " mg\n");
			this->userInterface->showString("Ventil " + dosierstationen[j]->getName() + " geschlossen\n");
		}
		this->waage.resetDeltaGewicht();
	}
	this->userInterface->showString("\nIhr Cocktail wird ausgegeben ...\n");
	this->entleerer.entleereBecher();
	this->userInterface->showString("\nIhr Cocktail ist fertig\n");
	this->waage.resetAbsolutGewicht();
	this->waage.resetDeltaGewicht();
	this->userInterface->showString("\nMischbehaelter wurde gereinigt.\n");
}


//liefert RezeptString mit ; getrennt und in Reihenfolge 0-i
string CocktailProController::mischbareRezepteToString() {
	string mischbareRezepteString;
	for (int i=0; i<this->mischbaresRezeptbuch.getAnzahlRezepte(); i++) {
		mischbareRezepteString += this->mischbaresRezeptbuch.getRezept(i)->getName() + ";";
	}
	return mischbareRezepteString;
}

CocktailProController::CocktailProController(UserInterface* userInterface) {
	this->userInterface = userInterface;
	this->init();
	this->mischer = new Mischer(userInterface);
}

void CocktailProController::init() {
	this->userInterface->showString("\nVerbindung zu Display hergestellt.\nRezeptbuch initialisiert.\nVerbindung zu Mischer hergestellt.\n"
				"Verbindung zu Mischbehaelter hergestellt.\nVerbindung zu Stampfer hergestellt.\n");
	Simulation* simulation = this->entleerer.initSimulation();
	list<string> zutaten = this->mischbaresRezeptbuch.getZutatenListe();
	for (list<string>::iterator it = zutaten.begin(); it != zutaten.end();
			++it) {

		//TODO: Artauswahl noch nicht getestet
		Dosierstation* dosierstation;
		if ((*it).find("stuecke")!=string::npos || (*it).find("Zucker")!=string::npos) {
			//fest
			dosierstation = new Dosierstation(fest, *it);
		}
		else if ((*it).find("Eis")!=string::npos) {
			//Eis
			dosierstation = new Dosierstation(eis, *it);
		} else {
			//fluessig
			dosierstation = new Dosierstation(fluessig, *it);
		}


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

	this->userInterface->showString("\nVerbindung zu Waage hergestellt\n");
}

CocktailProController::CocktailProController() {
	this->userInterface = 0;
	this->mischer = 0;
	this->init();
}
