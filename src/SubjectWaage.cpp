//@(#) SubjectWaage.cpp

#include "SubjectWaage.h"

SubjectWaage::SubjectWaage() {

}

SubjectWaage::~SubjectWaage() {

}

void SubjectWaage::attach(ObserverWaage* client) {
	observerWaage.push_back(client);
}

void SubjectWaage::detach(ObserverWaage* client) {
	for (unsigned int i = 0; i < observerWaage.size(); i++) {
			if (observerWaage.at(i) == client) {
				observerWaage.erase(observerWaage.begin() + i);
			}
		}
}

void SubjectWaage::notify() {
	for (unsigned int i = 0; i < observerWaage.size(); i++) {
			observerWaage.at(i)->update();
		}
}
