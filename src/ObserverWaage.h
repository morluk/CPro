//@(#) ObserverWaage.h

#ifndef OBSERVERWAAGE_H_H
#define OBSERVERWAAGE_H_H

//Abstrakter Observer des Observer Patterns
class ObserverWaage
{
	
public:
	//
	ObserverWaage();
	//
	virtual void update() = 0;
	//
	virtual ~ObserverWaage();
	
};

#endif
