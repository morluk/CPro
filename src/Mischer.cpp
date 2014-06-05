//@(#) Mischer.cpp

#include "Mischer.h"

Mischer::Mischer() {
	this->userInterface = 0;
}

Mischer::Mischer(UserInterface* userInterface) {
	this->userInterface = userInterface;
}

void Mischer::mix(int dauer) {
		for (int i= 0; i<dauer; i++) {
			this->userInterface->showString("# ");
			usleep(Simulation::TIMESTEP / 2);
		}
}

