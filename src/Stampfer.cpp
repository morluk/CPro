//@(#) Stampfer.cpp

#include "Stampfer.h"

void Stampfer::stampfe(int dauer) {
	for (int i= 0; i<dauer; i++) {
		this->userInterface->showString("# ");
		usleep(Simulation::TIMESTEP / 2);
	}
}

Stampfer::Stampfer(UserInterface* userInterface) {
	this->userInterface = userInterface;
}

Stampfer::Stampfer() {
	this->userInterface = 0;
}
