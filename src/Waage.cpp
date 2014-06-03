//@(#) Waage.cpp

#include "Waage.h"

Waage::Waage() {
	absolutGewicht = 0;
	deltaGewicht = 0;
}

void Waage::decrement() {

}

void Waage::notify() {

}

int Waage::getAbsolutGewicht() const {
	return absolutGewicht;
}

void Waage::increment(int step) {

}

void Waage::resetDeltaGewicht() {

}

int Waage::getDeltaGewicht() const {
	return deltaGewicht;
}

void Waage::attach(const ObserverWaage* client) {

}

void Waage::detach(const ObserverWaage* client) {

}
