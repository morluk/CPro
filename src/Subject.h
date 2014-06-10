//@(#) SubjectWaage.h

#ifndef SUBJECTWAAGE_H_H
#define SUBJECTWAAGE_H_H

#include <vector>
#include "Observer.h"

using namespace std;

//Abstraktes Subjekt des Observer Patterns.
class Subject {

public:
	void attach(Observer* client);

	void detach(Observer* client);

	void notify();

	Subject();

	~Subject();

protected:
	vector<Observer*> observerWaage;

};

#endif
