//@(#) Simulation.h

#ifndef SIMULATION_H_H
#define SIMULATION_H_H

#include "Waage.h"
#include "Art.h"
#include <unistd.h>

//Simuliert Gewicht das auf die Waage gelegt wird und zaehlt das Attribut Gewicht hoch.
class Simulation {

public:
	void gewichtErhoehen(Art art);

	void gewichtReduzieren();

	void setWaage(Waage* waage);

	Simulation();

	void stop();

private:
	static const int TIMESTEP = 1000;

	Waage* waage;

	bool waageLaeuft;

};

#endif
