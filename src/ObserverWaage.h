//@(#) ObserverWaage.h

#ifndef OBSERVERWAAGE_H_H
#define OBSERVERWAAGE_H_H

//Abstrakter Observer des Observer Patterns
class Observer {

public:
	Observer();

	virtual void update() = 0;

	virtual ~Observer();
};

#endif
