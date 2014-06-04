//@(#) Stampfer.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include <iostream>
#include <unistd.h>

using namespace std;

//Stampft fuer eine bestimmte Zeit
class Stampfer {

public:
	void stampfe(int dauer);

	Stampfer();
};

#endif
