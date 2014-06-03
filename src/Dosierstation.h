//@(#) Dosierstation.h

#ifndef DOSIERSTATION_H_H
#define DOSIERSTATION_H_H

#include "ObserverWaage.h"
#include "Waage.h"
#include "Art.h"
#include "Simulation.h"

//Oeffnet das Ventil. Schliesst das Ventil, sobald das Gewicht des Mischbehaelters der uebergebenen Grammzahl entspricht. Stoesst Simulation an.
class Dosierstation: ObserverWaage {

public:
	Dosierstation();

	Dosierstation(Art art);

	void fuelleAb(int menge);

	void setSimulation(const Simulation* simulation);

	void setWaage(const Waage* waage);

	virtual ~Dosierstation();

	virtual void update();

private:
	Art art;

	int gewichtWaage;

	Simulation* simulation;

	bool ventil;

	Waage* waage;

};

#endif
