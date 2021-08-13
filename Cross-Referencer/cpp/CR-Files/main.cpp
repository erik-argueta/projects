// Title: Cross-Referencing Automation
// Author: Erik Argueta
// Description: Using an input file, cross-references between two different
//	sequence of serial numbers
// Date: 7/26/21

#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;

void welcome();
int directions();
void openStreams(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file);
void closeStreams(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file);
void crossRef(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, int& inputSize);
int enterSize(int& inputSize);
void loopProgram(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, int& inputSize, bool& endProgram);
void debugger(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, int& inputSize);


int main() {
	bool endProgram = false;
	int inputSize;
	ifstream input_file, ehsX, ehsB, state;
	ofstream output_file;
	
	openStreams(input_file, ehsX, ehsB, state, output_file);
	
	//loopProgram(input_file, output_file, inputSize, endProgram);
	
	enterSize(inputSize);
	//crossRef(input_file, ehsX, ehsB, state, output_file, inputSize);
	debugger(input_file, ehsX, ehsB, state, inputSize);
	closeStreams(input_file, ehsX, ehsB, state, output_file);
	
	return 0;
}

void welcome() {
	cout << "Welcome! This program aims to aid in helping to cross-reference serial numbers and determine which iPads are funded by which program!\n";
	cout << "Please adhere to the directions and only enter the appropriate type of information.\n";
	cout << "If you have any questions, please contact Erik Argueta via eargueta@emcsd.org\n\n\n";
}

int directions() {
	int OS;
	string userName;
	cout << "Before proceeding, please enter the number representing the Operating System you are currently using.\n\n";
	cout << "(1) Windows\n(2)MacOS\n\n";

	// Windows
	if (OS == 1) {
		cout << "Please enter the name of your User Profile: ";
		cin >> userName;

		ifstream input_file;
		input_file.open("C:/Users/" + userName + "/Documents/EHS-Match/INPUT.txt");
	}
	return 0;
}

void crossRef(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, int& inputSize) {
	string inSerial;
	const int BASICSIZE{ 48 };
	const int XSIZE{ 51 };
	const int STATESIZE { 59 };
	
	for (int indexa{ 0 }; indexa < inputSize; indexa++) {
		bool xCheck = false;
		bool bCheck = false;
		bool sCheck = false;
		in_file >> inSerial;
		
		// EHS-X
		ehsX.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-X-List.txt");
		for (int indexb{0}; indexb < XSIZE; indexb++) {
			string xSN;
			getline(ehsX, xSN);
			if (inSerial == xSN) {
				cout << "EHS-X\n";
				out_file << inSerial << " == " << xSN << " EHS-X\n";
				xCheck = true;
			}
		}
		ehsX.close();
		
		// STATE
		state.open("/Users/erik-argueta/Desktop/EHS-Match/State.txt");
		for (int indexc{0}; indexc < STATESIZE; indexc++) {
			string stateSN;
			getline(state, stateSN);
			if (inSerial == stateSN) {
				cout << "State\n";
				out_file << inSerial << " == " << stateSN << " State\n";
				sCheck = true;
			}
		}
		state.close();
		
		// EHS-BASIC
		ehsB.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-Basic-List.txt");
		for (int indexd{0}; indexd < BASICSIZE; indexd++) {
			string basicSN;
			getline(ehsB, basicSN);
			if (inSerial == basicSN) {
				cout << "Basic\n";
				out_file << inSerial << " == " << basicSN << " Basic\n";
				bCheck = true;
			}
		}
		ehsB.close();
		
		// Determines if Fed
		if (xCheck == false && bCheck == false && sCheck == false) {
			cout << inSerial << " Federal\n";
			out_file << inSerial << " Federal\n";
		}
	}
}

int enterSize(int& inputSize) {
	cout << "How many Serial Numbers are in your input file? ";
	cin >> inputSize;
	return inputSize;
}

void loopProgram(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, int& inputSize, bool& endProgram) {
	char ans;
	welcome();
	while (!endProgram) {
		enterSize(inputSize);
		//crossRef(in_file, out_file, inputSize);
		closeStreams(in_file, ehsX, ehsB, state, out_file);
		cout << "Do you want to end the program? [Y/N]: ";
		cin >> ans;
		if (ans == 'Y' || ans == 'y') { endProgram = true; cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; }
		else if (ans == 'N' || ans == 'n') { endProgram = false;}
		else { cout << "Please enter Y or N.\n\n"; }
	}
}

void openStreams(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file) {
	in_file.open("/Users/erik-argueta/Desktop/EHS-Match/INPUT.txt");
	if (in_file.fail()) { cout << "INPUT Failed to open\n"; }
	else { cout << "INPUT file opened successfully.\n"; }
	
	out_file.open("/Users/erik-argueta/Desktop/EHS-Match/OUTPUT.txt");
	if (out_file.fail()) { cout << "output file failed to open.\n"; }
	else { cout << "output file opened successfully.\n"; }
	
	
	cout << endl << endl << endl << endl;
}

void closeStreams(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file) {
	in_file.close();
	ehsX.close();
	ehsB.close();
	state.close();
	out_file.close();
}

void debugger(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, int& inputSize) {
	ofstream debugger;
	debugger.open("/Users/erik-argueta/Desktop/EHS-Match/DEBUGGER.txt");
	string inSerial;
	const int BASICSIZE{ 48 };
	const int XSIZE{ 51 };
	const int STATESIZE { 59 };
	
	for (int indexa{ 0 }; indexa < inputSize; indexa++) {
		bool xCheck = false;
		bool bCheck = false;
		bool sCheck = false;
		in_file >> inSerial;
		
		debugger << endl;
		for (int border { 0 }; border < inSerial.size(); border++) { debugger << "="; }
		debugger << "||" << inSerial << "||";
		for (int border { 0 }; border < inSerial.size(); border++) { debugger << "="; }
		debugger << endl;
		
		// EHS-X
		debugger << "\n=================\n";
		debugger << "|| EHS-X CHECK ||\n";
		debugger << "=================\n";
		ehsX.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-X-List.txt");
		for (int indexb{0}; indexb < XSIZE; indexb++) {
			string xSN;
			getline(ehsX, xSN);
			debugger << inSerial << " == " << xSN << "\n";
			if (inSerial == xSN) {
				debugger << inSerial << " == " << xSN << " EHS-X\tMATCH\n";
				xCheck = true;
			}
		}
		ehsX.close();
		
		// STATE
		debugger << "\n=====================\n";
		debugger << "|| EHS-STATE CHECK ||\n";
		debugger << "=====================\n";
		state.open("/Users/erik-argueta/Desktop/EHS-Match/State.txt");
		for (int indexc{0}; indexc < STATESIZE; indexc++) {
			string stateSN;
			getline(state, stateSN);
			debugger << inSerial << " == " << stateSN << "\n";
			if (inSerial == stateSN) {
				debugger << inSerial << " == " << stateSN << " State\tMATCH\n";
				sCheck = true;
			}
		}
		state.close();
		
		// EHS-BASIC
		debugger << "\n=====================\n";
		debugger << "|| EHS-BASIC CHECK ||\n";
		debugger << "=====================\n";
		ehsB.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-Basic-List.txt");
		for (int indexd{0}; indexd < BASICSIZE; indexd++) {
			string basicSN;
			getline(ehsB, basicSN);
			debugger << inSerial << " == " << basicSN << "\n";
			if (inSerial == basicSN) {
				debugger << inSerial << " == " << basicSN << " Basic\tMATCH\n";
				bCheck = true;
			}
		}
		ehsB.close();
		
		// Determines if Fed
		if (xCheck == false && bCheck == false && sCheck == false) {
			debugger << "\n===========\n";
			debugger << "||FEDERAL||\n";
			debugger << "===========\n";
			debugger << inSerial << " Federal\n";
		}
	}
}
