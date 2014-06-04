//@(#) Entleerer.cpp

#include "Entleerer.h"

Entleerer::Entleerer() {
	this->simulation = 0;
	this->ventilOpen = false;
	this->gewichtWaage = 0;
	this->waage = 0;
}

Simulation* Entleerer::initSimulation() {
	this->simulation = new Simulation();
	return this->simulation;
}

void Entleerer::setWaage(Waage* waage) {
	this->waage = waage;
}

Simulation* Entleerer::getSimulation() {
	return this->simulation;
}

void Entleerer::entleereBecher() {
	this->ventilOpen = true;
	while (gewichtWaage > 0) {
		simulation->gewichtReduzieren();
	}
	this->ventilOpen = false;
}

void Entleerer::update() {
	this->gewichtWaage = this->waage->getAbsolutGewicht();
}

Entleerer::~Entleerer() {

}
