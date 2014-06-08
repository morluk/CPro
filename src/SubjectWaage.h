//@(#) SubjectWaage.h

#ifndef SUBJECTWAAGE_H_H
#define SUBJECTWAAGE_H_H

#include <vector>
#include "ObserverWaage.h"

using namespace std;

//Abstraktes Subjekt des Observer Patterns.
//TODO class umbenennen in Subject
class SubjectWaage {

public:
	void attach(ObserverWaage* client);

	void detach(ObserverWaage* client);

	void notify();

	SubjectWaage();

	~SubjectWaage();

protected:
	vector<ObserverWaage*> observerWaage;

};

#endif
