//@(#) MischbaresRezeptbuch.cpp


#include "MischbaresRezeptbuch.h"
//
MischbaresRezeptbuch::MischbaresRezeptbuch()
{
	
}

//
vector<Rezept*> MischbaresRezeptbuch::getMischbareRezepte() const
{
	return mischbareRezepte;
}

//
Rezept MischbaresRezeptbuch::getMischbaresRezept(int index)
{
	return Rezept();
}

