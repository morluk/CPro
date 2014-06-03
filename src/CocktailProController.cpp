//@(#) CocktailProController.cpp

#include "CocktailProController.h"

void CocktailProController::mischeRezept(int index) {

}

string CocktailProController::mischbareRezepteToString() {
	return string();
}

CocktailProController::CocktailProController(UserInterface* userInterface) {
	this->userInterface = userInterface;
	this->init();
}

void CocktailProController::init() {

}

CocktailProController::CocktailProController() {
	this->userInterface = 0;
	this->init();
}
