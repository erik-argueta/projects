//
//		Here, we create a program that helps visualize rain chance percentage
//
//		Idea: User dictates the area's size, and then enters the
//			chance of rain over the area
//
//		Maybe incorporate OOP
//
#include <iostream>
#include <ctime>
#include <random>
#include "simulation.h"
using namespace std;

void welcome();
void menu();

int main() {
	welcome();
	menu();
	return 0;
}


void welcome() {
	cout << "Hello! Welcome to RainSim!\n";
	cout << "Please select an option by entering the number corresponding to it";
}

void menu() {
	bool exit = false;
	int selection;
	while (!exit) {
		cout << "\n\n1) Begin\n"
		<< "2) Description\n"
		<< "3) Credits\n"
		<< "4) Exit\n\n";
		std::cout << "> ";
		cin >> selection;
		
		if (selection == 1) {
			Simulation* sim1 = new Simulation;
			sim1->setDimensions();
			sim1->setChances();
			sim1->confirmation();
			sim1->print();
			sim1->~Simulation();
			delete sim1;
		}
		if (selection == 2) {
			Simulation* getDesc = new Simulation;
			getDesc->printDescription();
			getDesc->~Simulation();
			delete getDesc;
		}
		
		if (selection == 3) {
			Simulation* credits = new Simulation();
			credits->printCredits();
			credits->~Simulation();
			delete credits;
		}
		
		if (selection == 4) {
			cout << "Thank you for trying RainSim!\nGoodbye!!!\n\n";
			exit = true;
		}
	}
}
