//@(#) Waage.h

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "ObserverWaage.h"
#include "SubjectWaage.h"

//Wird kontrolliert von Simulation und ermittelt das Gewicht des Mischbehaelters. Ueber notify() werden die Observer angestoßen.
class Waage: public Subject {
public:
	void decrement(float step);

	int getAbsolutGewicht() const;

	int getDeltaGewicht() const;

	void increment(float step);

	void resetDeltaGewicht();

	void resetAbsolutGewicht() {
		absolutGewicht = 0;
	}

	Waage();

private:
	float absolutGewicht;

	float deltaGewicht;
};

#endif
