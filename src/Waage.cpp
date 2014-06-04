//@(#) Waage.cpp

#include "Waage.h"

Waage::Waage() {
	absolutGewicht = 0;
	deltaGewicht = 0;
}

void Waage::decrement() {
	absolutGewicht--;
	deltaGewicht--;
	notify();
}

void Waage::notify() {
	for (unsigned int i = 0; i < observerWaage.size(); i++) {
		observerWaage.at(i)->update();
	}
}

int Waage::getAbsolutGewicht() const {
	return absolutGewicht;
}

void Waage::increment(int step) {
	absolutGewicht += step;
	deltaGewicht += step;
	notify();
}

void Waage::resetDeltaGewicht() {
	deltaGewicht = 0;
}

int Waage::getDeltaGewicht() const {
	return deltaGewicht;
}

void Waage::attach(ObserverWaage* client) {
	observerWaage.push_back(client);
}

void Waage::detach(ObserverWaage* client) {
	for (unsigned int i = 0; i < observerWaage.size(); i++) {
		if (observerWaage.at(i) == client) {
			observerWaage.erase(observerWaage.begin() + i);
		}
	}
}
