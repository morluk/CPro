//@(#) Mischer.h

#ifndef MISCHER_H_H
#define MISCHER_H_H

#include <iostream>
#include <unistd.h>

using namespace std;

//Mischt fuer eine vorgegebene Zeit
class Mischer {

public:
	Mischer();

	void mix(int dauer);
};

#endif
