//@(#) Dosierstation.cpp

#include "Dosierstation.h"

void Dosierstation::setWaage(Waage* waage) {
	this->waage = waage;
}

void Dosierstation::setSimulation(Simulation* simulation) {
	this->simulation = simulation;
}

void Dosierstation::fuelleAb(int menge) {
	this->ventil = true;
	while (gewichtWaage < menge) {
		simulation->gewichtErhoehen(fluessig);
	}
	this->ventil = false;
}

Dosierstation::Dosierstation(Art art, string name) {
	this->art = art;
	this->ventil = false;
	this->waage = 0;
	this->gewichtWaage = 0;
	this->simulation = 0;
	this->name = name;
}

Dosierstation::Dosierstation() {
	this->art = fluessig;
	this->ventil = false;
	this->waage = 0;
	this->gewichtWaage = 0;
	this->simulation = 0;
}

Dosierstation::~Dosierstation() {

}

void Dosierstation::update() {
	this->gewichtWaage = this->waage->getDeltaGewicht();
}
