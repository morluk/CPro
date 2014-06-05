//@(#) Stampfer.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include <iostream>
#include <unistd.h>
#include "Simulation.h"
#include "UserInterface.h"

using namespace std;

class UserInterface;

//Stampft fuer eine bestimmte Zeit
class Stampfer {

public:
	void stampfe(int dauer);

	Stampfer(UserInterface* userInterface);

	Stampfer();

private:
	UserInterface* userInterface;
};

#endif
