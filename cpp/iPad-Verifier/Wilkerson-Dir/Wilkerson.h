//
//  Wilkerson.hpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/30/22.
//

#ifndef Wilkerson_h
#define Wilkerson_h

#include <fstream>
#include <string>

class Wilkerson {
public:
	Wilkerson();
	
	void detectRun();
	void trackMissing();
	
private:
	std::string inItem{};
	std::string caseTag{};
	std::string iPadTag{};
	std::string iPadSN{};
	
	bool missing;
	bool detected;
};

#endif /* Wilkerson_hpp */
