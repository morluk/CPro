//@(#) Dosierstation.cpp

#include "Dosierstation.h"

void Dosierstation::setWaage(const Waage* waage) {

}

void Dosierstation::setSimulation(const Simulation* simulation) {

}

void Dosierstation::fuelleAb(int menge) {

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

}
