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

void Entleerer::setWaage(const Waage* waage) {

}

Simulation* Entleerer::getSimulation() {
	return 0;
}

void Entleerer::entleereBecher() {

}

void Entleerer::update() {

}

Entleerer::~Entleerer() {

}
