
#include "City.h"
#include "Citizen.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// BONUS POINTS
//Brandon, Semenuk, Antoine Bizet, Carson Storch, Kurt Sorge, Kyle Strait are RED BULL Rampage 2016 winners 
//The other 4 are Apple Engineers
//
//
//



//Creates a new city with the given name
//When the city is created you need to restore
//it's population from a file.
//Hint: You will want to make the file name
//be based on the name of the city.
City::City(string cityName) {
	City::cityName = cityName;
	ofstream fin;
	fileName = cityName + ".txt";
	fin.open(fileName);
	if (fin.fail()) {
		cout << "can't open file" << endl;
	}
	//This isn't working, not sure why.  ran out of time.  
	//fin >> City::cityName;
	//fin >> population;
	for (int i = 0; i < population; i++)
	{
		//fin >> cityCitizen[i];
	}


}

//This is the destructor for the city.  When
//this city is destroyed, save the population of
//the city to a file so that you can restore
//it in the constructor the next time that
//a city with this name is created.
City::~City() {
	ofstream fout;
	vector <Citizen*> pntr;
	for (int i = 0; i < population; i++) {
			//load pointer with citizens of class
			pntr.push_back(&cityCitizen[i]);
		
	}
	fout.open(fileName); // fail check
	if (fout.fail()) {
		cout << "error" << endl;
	}
	//out put everything to file.  
	fout << cityName << endl;
	fout << populationSize() << endl;
	for (int i = 0; i < cityCitizen.size(); i++) {
		
		fout << pntr[i];
	}
}

//Returns the city name
string City::getCityName() {
	return cityName;
}

//Returns the number of citizens in this city
int City::populationSize() {
	return population;
}

//Returns the citizen at the given index.
//not exactly what you wanted here, so I guessed. 
Citizen* City::getCitizenAtIndex(int index) {
		
			Citizen* pntr = &cityCitizen[index];
			return pntr;
}

//Adds a citizen to this city. You will need to
//make a copy of this citizen so that you make
//sure to keep it around for the life of the city.
void City::addCitizen(Citizen* citizen) {
		cityCitizen.push_back(citizen);
		population++;
}

//Returns the citizen with the given id.
Citizen* City::getCitizenWithId(int id) {
	Citizen* pntr;
	for (int i = 0; i < population; i++){
		//check ids
		if (cityCitizen[i].getId() == id) {
			Citizen* pntr = &cityCitizen[i];
			return pntr;

			}
		}
	}

//Returns a vector of citizens that all have
//the given color as their favorite color.
//For example, if color is “Blue” this will return all citizens
//for this city who’s favorite color is Blue.
vector<Citizen*> City::getCitizensForFavoriteColor(string color) {
	vector <Citizen*> pntr;
	for (int i = 0; i < population; i++) {
		//checking colors
		if (cityCitizen[i].getFavoriteColor() == color) {
					pntr.push_back(&cityCitizen[i]);
		}
	}
	return pntr;
}
