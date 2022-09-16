//
//  Columbia.cpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/30/22.
//

#include "Columbia.h"
#include <iostream>
using namespace std;

Columbia::Columbia() : detected(false), missing(true) {}


void Columbia::detectRun() {
	ifstream inputFile("/Users/erik-argueta/Desktop/iPad-Verify/Files/input-lists/input-list.txt");
	ofstream matchOutFile("/Users/erik-argueta/Desktop/iPad-Verify/Files/output-lists/Matching-Output.txt");
	while(inputFile) {
		ifstream classFile("/Users/erik-argueta/Desktop/iPad-Verify/Files/master-lists/columbia-master-ipad-list.txt");
		inputFile >> inItem;
		
		while(classFile) {
			classFile >> caseTag >> iPadTag >> iPadSN;
			
			if (inItem == caseTag || inItem == iPadTag || inItem == iPadSN) {
				detected = true;
				matchOutFile << inItem << "\t==\t" << caseTag << '\t' << iPadTag << '\t' << iPadSN << '\n';
				break;
			}
			else { continue; }
		}
		
		if(!detected && inItem != "") {
			matchOutFile << inItem << " did not find a match.\n";
			classFile.close();
		}
		detected = false;
		caseTag = ""; iPadTag = ""; iPadSN = "";
		inItem = "";
	}
	
	matchOutFile.close();
	inputFile.close();
}

void Columbia::trackMissing() {
	int missingBatch{-1}, total{-1};
	ifstream classFile("/Users/erik-argueta/Desktop/iPad-Verify/Files/master-lists/columbia-master-ipad-list.txt");
	ofstream missingIPads("/Users/erik-argueta/Desktop/iPad-Verify/Files/output-lists/Missing-iPads-Output.txt");
	while(classFile) {
		ifstream inputFile("/Users/erik-argueta/Desktop/iPad-Verify/Files/output-lists/Matching-Output.txt");
		classFile >> caseTag >> iPadTag >> iPadSN;
		total++;
		
		while(inputFile) {
			inputFile >> inItem;
			if (caseTag == inItem || iPadTag == inItem || iPadSN == inItem) {
				missing = false;
				break;
			}
		}
		
		if(missing && inItem != "") {
			missingBatch++;
			missingIPads << caseTag << ' ' << iPadTag << ' ' << iPadSN << "\n";
		}
		inItem = ""; caseTag = ""; iPadTag = ""; iPadSN = "";
		missing = true;
		inputFile.close();
		
	}
	
	missingIPads << "\n\nThere were " << missingBatch << " out of " << total << " iPads that were not collected.\n";
	
	missingIPads.close();
	classFile.close();
}
