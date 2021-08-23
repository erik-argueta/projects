//
//  main.cpp
//  SN-Verify
//
//  Created by Erik Argueta on 8/18/21.
//


/*
	Look for a way to effectively cross-reference and compile into 1 list.
 Seems like I may have to run once for each individual school, but that won't make it easy to compile all schools into 1 list.
 May need to use classes? Maybe I am overthinking it....
 
 Left off trying to put the pathnames into a string so I can open and close the streams at will. Debugger will not stop running. May need to restart to clean code
 
 */


#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;

void openLists(ifstream& masterList, ifstream& masterList2, ifstream& poolList);
void openSchools(ifstream& cherryS, ifstream& columbS, ifstream& cortaS, ifstream& ehsS, ifstream& gidS, ifstream& legS, ifstream& lomaS, ifstream& newlexS, ifstream& potS, ifstream& rioS, ifstream& shirpS, ifstream& wilkS);
void openOuts(ofstream& deb, ofstream& outp, ofstream& finalOutp, ofstream& missingL);
void debugger(ifstream& mast, ifstream& specialList, ofstream& debug, int& masterSize, int& listSize);
void closeStreams(ifstream& masterList, ifstream& masterList2, ifstream& poolList, ofstream& deb, ofstream& outp, ofstream& finalOutp, ofstream& missingL);


void checkSize(ifstream& oof);


int main(int argc, const char * argv[]) {
	bool noMatch = true;
	string snMaster;
	string snPool;
	string retStatus;
	string retStatus2;
	int missing{};
	
	// Establishing the streams
	ifstream master, master2, pool, output;
	ofstream debug, output1, missingList, finalOutput;
	
	// Open the Streams
	openLists(master, master2, pool);
	openOuts(debug, output1, finalOutput, missingList);
	
	for (int masterIndex{1}; masterIndex < 674; masterIndex++) {
		getline(master, snMaster);
		
		debug << "==============\n";
		debug << "| " << snMaster << " |\n";
		debug << "==============\n";
		for (int poolIndex{0}; poolIndex < 513; poolIndex++) {
			getline(pool, snPool);
			
			
			
			if (snMaster == snPool) {
				debug << snMaster << " == " << snPool << " MATCH==========\n";
				output1 << "Yes -- Erik" << "\n";
				noMatch = false;
				break;
			}
			if (snMaster == ".") {
				debug << "SKIP LINE" << "\n";
				output1 << "\n";
				break;
			}
			else {
				debug << snMaster << " == " << snPool << "\n";
			}
		}
		if (noMatch == true && snMaster != ".") {
			output1 << "\n";
			missing++;
			missingList << snMaster << "\n";
		}
		pool.close();
		pool.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Pool.txt");
		noMatch = true;
	}
	
	cout << "There are " << missing << " that have not been distributed by Erik or Daniel." << endl;
	
	return 0;
}


void openLists(ifstream& masterList, ifstream& masterList2, ifstream& poolList) {
	masterList.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Master.txt");
	masterList2.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Master-2.txt");
	poolList.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Pool.txt");
}

void openSchools(ifstream& cherryS, ifstream& columbS, ifstream& cortaS, ifstream& ehsS, ifstream& gidS, ifstream& legS, ifstream& lomaS, ifstream& newlexS, ifstream& potS, ifstream& rioS, ifstream& shirpS, ifstream& wilkS) {
	cherryS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/Cherrylee.txt");
	columbS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/Columbia.txt");
	cortaS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/Cortada.txt");
	ehsS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/EHS.txt");
	gidS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/Gidley.txt");
	legS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/LeGore.txt");
	lomaS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/Loma.txt");
	newlexS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/NewLexington.txt");
	potS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/Potrero.txt");
	rioS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/RioVista.txt");
	shirpS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/Shirpser.txt");
	wilkS.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Schools/Wilkerson.txt");
}

void openOuts(ofstream& deb, ofstream& outp1, ofstream& finalOutp, ofstream& missingL) {
	deb.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Debug.txt");
	outp1.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Output.txt");
	finalOutp.open("/Users/erik-argueta/Desktop/Turn-In-Verify/final-output.txt");
	missingL.open("/Users/erik-argueta/Desktop/Turn-In-Verify/missing-iPads.txt");
}

void checkSize(ifstream& oof) {
	int size{0};
	string item;
	
	
	while (oof >> item) { size++; }
	cout << size << endl;
}

void debugger(ifstream& mast, ifstream& specialList, ofstream& debug, int& masterSize, int& listSize) {
	string snMaster;
	
	for (int masterIndex{1}; masterSize; masterIndex++) {
		bool noMatch = true;
		getline(mast, snMaster);
		string snList;
		
		debug << "==============\n";
		debug << "| " << snMaster << " |\n";
		debug << "==============\n";
		for (int listIndex{0}; listIndex < listSize; listIndex++) {
			getline(specialList, snList);
			
			if (snMaster == snList) {
				debug << snMaster << " == " << snList << " MATCH==========\n";
				noMatch = false;
				break;
			}
			if (snMaster == ".") {
				debug << "SKIP LINE" << "\n";
				break;
			}
			else {
				debug << snMaster << " == " << snList << "\n";
				
			}
		}
		if (noMatch == true && snMaster != ".") {
			if (noMatch == true && snMaster != ".") {
				debug << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!BLANK SPACE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			}
		}
		//pool.close();
		//pool.open("/Users/erik-argueta/Desktop/Turn-In-Verify/Pool.txt");
		noMatch = true;
	}
}

void closeStreams(ifstream& masterList, ifstream& masterList2, ifstream& poolList, ofstream& deb, ofstream& outp, ofstream& finalOutp, ofstream& missingL) {
	masterList.close();
	masterList2.close();
	poolList.close();
	deb.close();
	outp.close();
	finalOutp.close();
	missingL.close();
}
