//@(#) Simulation.cpp

#include "Simulation.h"

void Simulation::gewichtReduzieren() {
	this->waage->decrement(25);
	usleep(TIMESTEP);
}

void Simulation::gewichtErhoehen(Art art) {
	switch (art) {
	case fluessig:
		this->waage->increment(1);
		usleep(TIMESTEP / 4);
		break;
	case fest:
		this->waage->increment(10);
		usleep(TIMESTEP);
		break;
	case eis:
		this->waage->increment(20);
		usleep(TIMESTEP);
		break;
	}
}

void Simulation::setWaage(Waage* waage) {
	this->waage = waage;
}

Simulation::Simulation() {
	this->waage = 0;
	this->waageLaeuft = false;
}

