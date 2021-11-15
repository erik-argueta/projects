/*
 * Erik Argueta
 * Attempt at making a voting system
 * Date: May 25, 2021
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Poll-Information.h"
using namespace std;

int main() {
	string name;
	Polling poll(name);
	
	//poll.displayWelcome();
	//poll.displayTable();
	//poll.displayQuestions();
	poll.runQuestions();
	poll.displayResults();
	
	return 0;
}
