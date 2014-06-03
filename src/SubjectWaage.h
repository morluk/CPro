//@(#) SubjectWaage.h

#ifndef SUBJECTWAAGE_H_H
#define SUBJECTWAAGE_H_H

#include <vector>
#include "ObserverWaage.h"

using namespace std;

//Abstraktes Subjekt des Observer Patterns.
class SubjectWaage {

public:
	virtual void attach(const ObserverWaage* client) = 0;

	virtual void detach(const ObserverWaage* client) = 0;

	virtual void notify() = 0;

	SubjectWaage();

	virtual ~SubjectWaage();

private:
	vector<ObserverWaage*> observerWaage;

};

#endif
