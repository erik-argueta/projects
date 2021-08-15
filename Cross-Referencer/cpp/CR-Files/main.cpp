// Title: Cross-Referencing Automation
// Author: Erik Argueta
// Description: Using an input file, cross-references between two different
//	sequence of serial numbers
// Date: 7/26/21



/*


	08/14/21
	Work has become so convoluted, it is better to implement Class. 
	Current Issue:
		I need to make the program close and open the streams in order to cross-reference 
		more than once. Therefore, I need to implement a class because copying and pasting inString and etc makes the code look messy and complicated.
		It will also make for review of classes as I can't do that at the moment.


*/

#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;

void welcome();
void directions(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, ofstream& debug_file, string& inString, string& xString, string& stateString, string& basicString, string& outString, string& debugString);
void openStreams(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, ofstream& debug_file, string& inString, string& xString, string& stateString, string& basicString, string& outString, string& debugString);
void closeStreams(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, ofstream& debug_file);
void crossRef(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, int& inputSize);
int enterSize(int& inputSize);
void loopProgram(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, int& inputSize, bool& endProgram);
void debugger(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, int& inputSize, ofstream& debug_file);


int main() {
	bool endProgram = false;
	int inputSize;
	ifstream input_file, ehsX, ehsB, state;
	ofstream output_file, debugger_file;
	string inString, xString, stateString, basicString, outString, debugString;

	welcome();
	directions(input_file, ehsX, ehsB, state, output_file, debugger_file, inString, xString, stateString, basicString, outString, debugString);
	enterSize(inputSize);

	debugger(input_file, ehsX, ehsB, state, inputSize, debugger_file);

	//openStreams(input_file, ehsX, ehsB, state, output_file);
	//loopProgram(input_file, output_file, inputSize, endProgram);
	//crossRef(input_file, ehsX, ehsB, state, output_file, inputSize);
	//closeStreams(input_file, ehsX, ehsB, state, output_file, debugger_file);
	
	return 0;
}

void welcome() {
	cout << "Welcome! This program aims to aid in helping to cross-reference serial numbers and determine which iPads are funded by which program!\n";
	cout << "Please adhere to the directions and only enter the appropriate type of information.\n";
	cout << "If you have any questions, please contact Erik Argueta via eargueta@emcsd.org\n\n\n";
}

void directions(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, ofstream& debug_file, string& inString, string& xString, string& stateString, string& basicString, string& outString, string& debugString) {
	int OS;
	string userName;
	
	cout << "Before proceeding, please enter the number representing the Operating System you are currently using.\n\n";
	cout << "(1) Windows\n(2) MacOS\n\n";
	//cout << "Enter the Number: ";
	cin >> OS;

	// Windows
	if (OS == 1) {
		cout << "Please enter the name of your User Profile: ";
		cin >> userName;

		// Input
		in_file.open("C:/Users/Josue/Documents/EHS-Match/INPUT.txt");
		inString = "C:/Users/Josue/Documents/EHS-Match/INPUT.txt";
		// EHS-X
		ehsX.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/EHS-X-List.txt");
		xString = "C:/Users/Josue/Desktop/Cross-Referencer-Project/EHS-X-List.txt";
		// State
		state.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/State.txt");
		stateString = "C:/Users/Josue/Desktop/Cross-Referencer-Project/State.txt";
		// EHS-Basic
		ehsB.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/EHS-Basic-List.txt");
		basicString = "C:/Users/Josue/Desktop/Cross-Referencer-Project/EHS-Basic-List.txt";
		// Output
		out_file.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/OUTPUT.txt");
		outString = "C:/Users/Josue/Desktop/Cross-Referencer-Project/OUTPUT.txt";
		// Debug
		debug_file.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/DEBUGGER.txt");
		debugString = "C:/Users/Josue/Desktop/Cross-Referencer-Project/DEBUGGER.txt";
	}

	// Should be MacOS
	else if (OS == 2) {
		// Input
		in_file.open("/Users/" + userName + "/Desktop/EHS-Match/INPUT.txt");
		// EHS-X
		ehsX.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-X-List.txt");
		// State
		state.open("/Users/erik-argueta/Desktop/EHS-Match/State.txt");
		// EHS-Basic
		ehsB.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-Basic-List.txt");
		// Output
		out_file.open("/Users/erik-argueta/Desktop/EHS-Match/OUTPUT.txt");
		// Debug
		debug_file.open("/Users/erik-argueta/Desktop/EHS-Match/DEBUGGER.txt");
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

void openStreams(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, ofstream& debug_file, string& inString, string& xString, string& stateString, string& basicString, string& outString, string& debugString) {
	
	in_file.open(inString);
	ehsX.open(xString);
	ehsB.open(basicString);
	state.open(stateString);
	out_file.open(outString);
	debug_file.open(debugString);
}

void closeStreams(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, ofstream& out_file, ofstream& debug_file) {
	in_file.close();
	ehsX.close();
	ehsB.close();
	state.close();
	out_file.close();
	debug_file.close();
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
		//ehsX.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-X-List.txt");
		ehsX.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/EHS-X-List");
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
		//state.open("/Users/erik-argueta/Desktop/EHS-Match/State.txt");
		state.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/State.txt");
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
		//ehsB.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-Basic-List.txt");
		ehsB.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/EHS-Basic-List.txt");
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

void debugger(ifstream& in_file, ifstream& ehsX, ifstream& ehsB, ifstream& state, int& inputSize, ofstream& debug_file) {

	//debugger.open("/Users/erik-argueta/Desktop/EHS-Match/DEBUGGER.txt");
	//debugger.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/DEBUGGER.txt");
	string inSerial;
	const int BASICSIZE{ 48 };
	const int XSIZE{ 51 };
	const int STATESIZE { 59 };
	
	for (int indexa{ 0 }; indexa < inputSize; indexa++) {
		bool xCheck = false;
		bool bCheck = false;
		bool sCheck = false;
		in_file >> inSerial;
		
		debug_file << endl;
		for (int border { 0 }; border < inSerial.size(); border++) { debug_file << "="; }
		debug_file << "||" << inSerial << "||";
		for (int border { 0 }; border < inSerial.size(); border++) { debug_file << "="; }
		debug_file << endl;
		
		// EHS-X
		debug_file << "\n=================\n";
		debug_file << "|| EHS-X CHECK ||\n";
		debug_file << "=================\n";
		//ehsX.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-X-List.txt");
		//ehsX.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/EHS-X-List");

		for (int indexb{0}; indexb < XSIZE; indexb++) {
			string xSN;
			getline(ehsX, xSN);
			debug_file << inSerial << " == " << xSN << "\n";
			if (inSerial == xSN) {
				debug_file << inSerial << " == " << xSN << " EHS-X\tMATCH\n";
				xCheck = true;
			}
		}
		ehsX.close();
		
		// STATE
		debug_file << "\n=====================\n";
		debug_file << "|| EHS-STATE CHECK ||\n";
		debug_file << "=====================\n";
		//state.open("/Users/erik-argueta/Desktop/EHS-Match/State.txt");
		//state.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/State.txt");
		for (int indexc{0}; indexc < STATESIZE; indexc++) {
			string stateSN;
			getline(state, stateSN);
			debug_file << inSerial << " == " << stateSN << "\n";
			if (inSerial == stateSN) {
				debug_file << inSerial << " == " << stateSN << " State\tMATCH\n";
				sCheck = true;
			}
		}
		state.close();
		
		// EHS-BASIC
		debug_file << "\n=====================\n";
		debug_file << "|| EHS-BASIC CHECK ||\n";
		debug_file << "=====================\n";
		//ehsB.open("/Users/erik-argueta/Desktop/EHS-Match/EHS-Basic-List.txt");
		//ehsB.open("C:/Users/Josue/Desktop/Cross-Referencer-Project/EHS-Basic-List.txt");
		for (int indexd{0}; indexd < BASICSIZE; indexd++) {
			string basicSN;
			getline(ehsB, basicSN);
			debug_file << inSerial << " == " << basicSN << "\n";
			if (inSerial == basicSN) {
				debug_file << inSerial << " == " << basicSN << " Basic\tMATCH\n";
				bCheck = true;
			}
		}
		ehsB.close();
		
		// Determines if Fed
		if (xCheck == false && bCheck == false && sCheck == false) {
			debug_file << "\n===========\n";
			debug_file << "||FEDERAL||\n";
			debug_file << "===========\n";
			debug_file << inSerial << " Federal\n";
		}
	}
}
