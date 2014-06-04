//@(#) Waage.h

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "ObserverWaage.h"
#include "SubjectWaage.h"

//Wird kontrolliert von Simulation und ermittelt das Gewicht des Mischbehaelters. Ueber notify() werden die Observer angestoßen.
class Waage : public SubjectWaage {
public:
	void decrement();

	int getAbsolutGewicht() const;

	int getDeltaGewicht() const;

	void increment(int step);

	void notify();

	void resetDeltaGewicht();

	void resetAbsolutGewicht() {
		absolutGewicht = 0;
	}

	virtual void attach(ObserverWaage* client);

	virtual void detach(ObserverWaage* client);

	Waage();

private:
	int absolutGewicht;

	int deltaGewicht;
};

#endif
