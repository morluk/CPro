//@(#) SubjectWaage.cpp

#include "Subject.h"

Subject::Subject() {

}

Subject::~Subject() {

}

void Subject::attach(Observer* client) {
	observerWaage.push_back(client);
}

void Subject::detach(Observer* client) {
	for (unsigned int i = 0; i < observerWaage.size(); i++) {
		if (observerWaage.at(i) == client) {
			observerWaage.erase(observerWaage.begin() + i);
		}
	}
}

void Subject::notify() {
	for (unsigned int i = 0; i < observerWaage.size(); i++) {
		observerWaage.at(i)->update();
	}
}
