/*
 Poll informatio containing:
	* tabular report with 5 topics down the left side and 10
		ratings acrocc the top, listing in each column
		the number of ratings received for each topic
	* right of each row, show the average of the ratings
		for that issue
	* which issue reveived the highest point total? Display both
		the issue and the point total
	* which issue received the lowest point total? Display both
		the issue and point total
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <array>

class Polling {
public:
	// 5 row by 10 column array of responses (in int)
	
	/*
	 
			R1	R2	R3	R4	R5	R6	R7	R8	R9	R10		AVERAGE
	 issue1
	 issue2
	 issue3
	 issue4
	 issue5
	 */
	
	Polling(const std::string& name) : userName(name) { };
	
	void displayWelcome() const {
		std::string userName;
		std::cout << "Welcome to Polling!";
		std::cout << "\nPlease enter your name: ";
		std::getline(std::cin, userName);
		
		std::cout << "Welcome " << userName << "!\n";
	}
	
	void runQuestions() {
		int response;
		std::cout << "Please answer the following questions according to importance,"
		<< "\n1 being least important and 10 being most important.";
		
		for (int index{0}; index < questions.size(); index++) {
			std::cout << "\n\nHow do you feel about: " << questions[index] << "?     ";
			std::cin >> response;
			answers[index] = response;
		}
		
	}
	
	void displayResults() {
		for (auto answer : answers) {
			std::cout << answer << "\n";
		}
		std::cout << std::endl;
	}
	
	void displayTable() {
		for (int index{0}; index < questions.size(); index++) {
			
		}
	}
	
	
	
	
private:
	//std::array<std::array<int, responses>, topics> results;
	std::string userName;
	std::array<int, 5> answers;
	std::array<std::string, 5> questions { "Q1", "Q2", "Q3", "Q4", "Q5" };
	std::array<std::array<int, 5>, 5> results;
	
};
