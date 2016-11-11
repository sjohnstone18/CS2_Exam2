#include "Citizen.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Creates a new Citizen object with the passed in
//id, name, and favorite color
//Once a citizen is created, you can't change their id or name
//but you can change their favorite color
Citizen::Citizen() {
	id = 0;
	firstName = "no";
	lastName = "good";
	color = "bland";
	//this is made to allow the array to be made - used to allow the index function to work while incomplete
}


Citizen::Citizen(int id, string firstName, string lastName, string color) {
	Citizen::id = id;
	Citizen::firstName = firstName;
	Citizen::lastName = lastName;
	Citizen::color = color;
}

//Creates a new Citizen object by copying data from the
//passed in citizen
Citizen::Citizen(Citizen* citizen) {
	Citizen::id = citizen->getId();
	Citizen::firstName = citizen->getFirstName();
	Citizen::lastName = citizen->getLastName();
	Citizen::color = citizen->getFavoriteColor();
}

//Returns the first name of this citizen
string Citizen::getFirstName() {
	return firstName;
}

//Returns the last name of this citizen
string Citizen::getLastName() {
	return lastName;
}

//Returns the id for this citizen
int Citizen::getId() {
	return id;
}

//Returns the favorite color for this citizen
string Citizen::getFavoriteColor() {

	return color;

}

//Sets the favorite color for this citizen
void Citizen::setFavoriteColor(string color) {
	Citizen::color = color;
}