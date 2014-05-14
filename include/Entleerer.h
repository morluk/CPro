//@(#) Entleerer.h

#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include "Waage.h"
#include "Simulation.h"

//Oeffnet das Ventil des Mischbehaelters. Schliesst das Ventil, sobald das Gewicht des Mischbehaelters 0 ist.
class Entleerer: ObserverWaage
{
	
public:
	//
	void entleereBecher();
	//
	Entleerer();
	//
	Simulation* getSimulation();
	//
	Simulation* initSimulation();
	//
	void setWaage(const Waage* waage);
	//
	void update();
	//
	virtual ~Entleerer();
	
private:
	//
	int gewichtWaage;
	
	//
	Simulation * simulation;
	
	//
	bool ventilOpen;
	
	//
	Waage * waage;
	
	
};

#endif
