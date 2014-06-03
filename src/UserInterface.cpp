//@(#) UserInterface.cpp

#include "UserInterface.h"

void UserInterface::update() {

}

void UserInterface::setWaage(const Waage* waage) {

}

UserInterface::UserInterface() {
	this->cocktailProController = new CocktailProController(this);
	this->waage = 0;
}

void UserInterface::showMenu() {

}

UserInterface::~UserInterface() {

}

