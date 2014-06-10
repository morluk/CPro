//@(#) Dosierstation.h

#ifndef DOSIERSTATION_H_H
#define DOSIERSTATION_H_H

#include "Observer.h"
#include "Waage.h"
#include "Art.h"
#include "Simulation.h"
#include <string>

using namespace std;

//Oeffnet das Ventil. Schliesst das Ventil, sobald das Gewicht des Mischbehaelters der uebergebenen Grammzahl entspricht. Stoesst Simulation an.
class Dosierstation: public Observer {

public:
	Dosierstation();

	Dosierstation(Art art, string name);

	void fuelleAb(float menge);

	void setSimulation(Simulation* simulation);

	void setWaage(Waage* waage);

	virtual ~Dosierstation();

	virtual void update();

	string getName() {
		return this->name;
	}

	//Debug
	string getArt() {
		switch (art) {
		case fest:
			return "fest";
			break;
		case fluessig:
			return "fluessig";
			break;
		case eis:
			return "eis";
			break;
		default:
			return "nichts";
		}
	}

private:
	Art art;

	int gewichtWaage;

	Simulation* simulation;

	bool ventil;

	Waage* waage;

	string name;
};

#endif
