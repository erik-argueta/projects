//
//  simulation.cpp
//  general-workspace
//
//  Created by Erik Argueta on 12/6/21.
//

#include "Simulation.h"
#include <iostream>
#include <array>
#include <time.h>
#include <stdlib.h>
#include <random>

Simulation::Simulation() : length(0), height(0), chances(0) { }

Simulation::~Simulation() {
	length = NULL;
	height = NULL;
	chances = NULL;
}

void Simulation::printDescription() {
	std::cout << "\n\nWelcome! First, thank you for taking the time to check out this small project of mine!\n";
	std::cout << "It's not common knowledge when it comes to the chances of rain in weather reports.\nWhatever percentage is reported, that is the percent of the area/city that will have rainfall.\nSo, this program aims to help simulate how that looks!";
}

void Simulation::setDimensions() {
	bool lengthDone = false;
	bool heightDone = false;
	bool ready = false;
	std::string confirm;
	
	while (!ready) {
		std::cout << "\n\nHow many units long would you like the area to be? (1-50)";
		while (!lengthDone) {
			std::cout << "\n> ";
			std::cin >> length;
			
			if (length < 1 || length > 50) { std::cout << "\nPlease emter a number between 1 and 50."; }
			else if (length >= 1 && length <= 50) { lengthDone = true; }
		}
		
		std::cout << "\n\nHow many units tall would you like the area to be? (1-50)";
		while (!heightDone) {
			std::cout << "\n> ";
			std::cin >> height;
			
			if (height < 1 || height > 50) { std::cout << "\nPlease emter a number between 1 and 50."; }
			else if (height >= 1 && height <= 50) { heightDone = true; }
		}
		
		std::cout << "Here is your " << length << "x" << height << " plot of land:\n";
		
		for (int i = 0; i < (length*2)+3; i++) { std::cout <<"_"; }
		std::cout << "\n";
		for (int i = 0; i < height; i++) {
			std::cout << "| ";
			for (int j = 0; j < length; j++) {
				std::cout << ". ";
			}
			std::cout << "|" << std::endl;
		}
		for (int i = 0; i < (length*2)+3; i++) { std::cout <<"-"; }
		
		std::cout << "\nDo you want to confirm these settings? [Y/N]\n> ";
		std::cin >> confirm;
		
		if (confirm[0] == 'n' || confirm[0] == 'N') {
			lengthDone = false; heightDone = false;
		}
		else if (confirm[0] == 'y' || confirm[0] == 'Y') { ready = true; }
	}
	
}

void Simulation::setChances() {
	bool finish = false;
	std::string answer;
	while (!finish){
		std::cout << "\n\nWhat are the chances of rain? (just the number)\n> ";
		std::cin >> chances;
		
		std::cout << "\n\nThe chances of rain is " << chances << "%.";
		std::cout << "\nDo you want to confirm this setting? You cannot change it later [Y/N]\n> ";
		std::cin >> answer;
		if (answer[0] == 'y') { finish = true; }
	}
}

void Simulation::confirmation() {
	std::cout << "\n\n\nThe program will simulate an " << chances << "% chance of rain over an area of " << length << "x" << height << " units.";
}

void Simulation::printCredits() {
	std::cout << "\n\nPROGRAM AUTHOR: ERIK ARGUETA (GITHUB: erik-argueta)";
	std::cout << "\nCOMPILED ON: xCode";
}

void Simulation::print() {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 100);
	
	int spot;
	std::cout << std::endl;
	
	for (int i = 0; i < (length*2)+3; i++) { std::cout <<"_"; }
	
	std::cout << std:: endl;
	srand(static_cast<int>(time(NULL)));
	for (int i = 0; i < height; i++) {
		std::cout << "| ";
		for (int j = 0; j < length; j++) {
			//spot = distribution(generator);
			
			spot = 1+rand()%100;
			if (spot <= chances) { std::cout << "* "; }
			else { std::cout << ". "; }
		}
		std::cout << "|" << std::endl;
	}
	for (int i = 0; i < (length*2)+3; i++) { std::cout <<"-"; }
}
