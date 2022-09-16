//
//  main.cpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/27/22.
//

#include "Cortada-Dir/Cortada.h"
#include "Wilkerson-Dir/Wilkerson.h"
#include "Columbia-Dir/Columbia.h"
#include "New-Lex-Dir/New_Lex.h"
#include "Rio-Dir/Rio_Vista.h"
#include "Potrero-Dir/Potrero.h"
#include "Gidley-Dir/Gidley.h"
#include "Shirpser-Dir/Shirpser.h"
#include "Cherrylee-Dir/Cherrylee.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void detectInputs();
void missingIPads();
void mainMenu();
void menuSelection(int& selection);

int main() {
	mainMenu();
	
	return 0;
}

void detectInputs() {
	bool detected{false};
	string ogCaseTag{}, ogIpadTag{}, ogIPadSN{}, inputItem{};
	int detectedTotal{0}, nonDetectedTotal{0};
	
	ifstream masterFin("/Users/erik-argueta/Desktop/iPad-Verify/Files/master-lists/cortada-master-ipad-list.txt");
	ofstream fout("/Users/erik-argueta/Desktop/iPad-Verify/Files/output-lists/Matching-Output.txt");
	
	while (masterFin) {
		ifstream inputFin("/Users/erik-argueta/Desktop/iPad-Verify/Files/input-lists/input-list.txt");
		masterFin >> ogCaseTag >> ogIpadTag >> ogIPadSN;
		
		while (inputFin) {
			inputFin >> inputItem;
			if (inputItem == ogCaseTag || inputItem == ogIpadTag || inputItem == ogIPadSN) {
				detectedTotal++;
				fout << inputItem << "\t==\t" << ogCaseTag << "\t\t" << ogIpadTag << "\t\t" << ogIPadSN << " ---- DETECTED\n";
				detected = true;
				break;
			}
			// else { continue; }
		}
		if (!detected) { fout << inputItem << "\tWAS NOT DETECTED******\n"; nonDetectedTotal++;}
		inputFin.close();
	}
	
	fout << "\n\nTotal iPads Detected: " << detectedTotal << "\n";
	fout << "Total iPads NOT Detected: " << nonDetectedTotal << "\n\n";
	masterFin.close();
	fout.close();
}

void missingIPads() {
	ifstream masterFin("/Users/erik-argueta/Desktop/iPad-Verify/Files/master-lists/cortada-master-ipad-case.txt");
	ofstream fout("/Users/erik-argueta/Desktop/iPad-Verify/Files/output-lists/Missing-iPads-Output.txt");
	ifstream inputFin("/Users/erik-argueta/Desktop/iPad-Verify/Files/input-lists/input-cortada-list.txt");
	
	string masteriPad{}, inputIPad{}, masterCaseTag{}, masterIPadTag{}, masterSN{};
	int missingiPadsTotal{0};
	bool missing{true};
	
	
	while(masterFin) {
		masterFin >> masterCaseTag >> masterIPadTag >> masterSN;
		
		while(inputFin) {
			inputFin >> inputIPad;
			
			if (inputIPad == masterCaseTag || inputIPad == masterIPadTag || inputIPad == masterSN) {
				missing = false;
				break;
			}
			
			else { continue; }
		}
		
		if (missing) {
			missingiPadsTotal++;
			cout << masterCaseTag << "\t\t" << masterIPadTag << "\t\t" << masterSN << " IS MISSING\n";
			//missing = true;
			
		}
		inputFin.close();
	}
	
	cout << "Total iPads Missing: " << missingiPadsTotal << "\n";
}

void mainMenu() {
	int menuChoice{};
	cout << "Please select a school:\n";
	cout << "1) Cortada\n2) Wilkerson\n3) Cherrylee\n4) Gidley\n5) LeGore\n6) New Lexington\n7) Shirpser\n8) Columbia\n9) Rio Vista\n10) Potrero\n\n> ";
	cin >> menuChoice;
	
	menuSelection(menuChoice);
	
}

void menuSelection(int& selection) {
	if (selection == 1) {
		Cortada* cort = new Cortada();
		cort->detectRun();
		cort->trackMissing();
		delete cort;
	}
	
	if (selection == 2) {
		Wilkerson* wilk = new Wilkerson();
		wilk->detectRun();
		wilk->trackMissing();
		delete wilk;
	}
	
	if (selection == 3) {
		Cherrylee* cherry = new Cherrylee();
		cherry->detectRun();
		cherry->trackMissing();
		delete cherry;
		
	}
	
	if (selection == 4) {
		Gidley* gid = new Gidley();
		gid->detectRun();
		gid->trackMissing();
		delete gid;
	}
	
	if (selection == 5) {
		
	}
	
	if (selection == 6) {
		NewLexington* newlex = new NewLexington();
		newlex->detectRun();
		newlex->trackMissing();
		delete newlex;
	}
	
	if (selection == 7) {
		Shirpser* shirp = new Shirpser();
		shirp->detectRun();
		shirp->trackMissing();
		delete shirp;
	}
	
	if (selection == 8) {
		Columbia* Col = new Columbia();
		Col->detectRun();
		Col->trackMissing();
		delete Col;
	}
	
	if (selection == 9) {
		RioVista* rio = new RioVista();
		rio->detectRun();
		rio->trackMissing();
		delete rio;
	}
	
	if (selection == 10) {
		Potrero* potr = new Potrero();
		potr->detectRun();
		potr->trackMissing();
		delete potr;
	}
}
