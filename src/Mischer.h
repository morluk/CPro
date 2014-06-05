//@(#) Mischer.h

#ifndef MISCHER_H_H
#define MISCHER_H_H

#include "UserInterface.h"
#include <iostream>
#include <unistd.h>

using namespace std;

class UserInterface;

//Mischt fuer eine vorgegebene Zeit
class Mischer {

public:
	Mischer();

	Mischer(UserInterface* userInterface);

	void mix(int dauer);

private:
	UserInterface* userInterface;
};

#endif
