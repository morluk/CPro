//@(#) Simulation.cpp

#include "Simulation.h"

void Simulation::gewichtReduzieren() {
	this->waage->decrement();
	usleep(TIMESTEP);
}

void Simulation::gewichtErhoehen(Art art) {
	//TODO: richtiger wert fuer art
	switch (art) {
	case fluessig:
		this->waage->increment(10);
		break;
	case fest:
		this->waage->increment(10);
		break;
	case eis:
		this->waage->increment(10);
		break;
	}
	usleep(TIMESTEP);
}

void Simulation::setWaage(Waage* waage) {
	this->waage = waage;
}

void Simulation::stop() {
	//TODO: was sollte hier gemacht werden??
}

Simulation::Simulation() {
	this->waage = 0;
	this->waageLaeuft = false;
}

