//@(#) Waage.cpp

#include "Waage.h"

Waage::Waage() {
	absolutGewicht = 0;
	deltaGewicht = 0;
}

void Waage::decrement(float step) {
	while (step > 0) {
		if (absolutGewicht == 0) {
			step = 0;
		} else {
			absolutGewicht--;
			deltaGewicht--;
			step--;
		}
	}
	notify();
}

int Waage::getAbsolutGewicht() const {
	return absolutGewicht;
}

void Waage::increment(float step) {
	absolutGewicht += step;
	deltaGewicht += step;
	notify();
}

void Waage::resetDeltaGewicht() {
	deltaGewicht = 0;
	this->notify();
}

int Waage::getDeltaGewicht() const {
	return deltaGewicht;
}
