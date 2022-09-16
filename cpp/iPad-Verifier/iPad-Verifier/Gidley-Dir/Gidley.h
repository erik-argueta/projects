//
//  Gidley.hpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/30/22.
//

#ifndef Gidley_h
#define Gidley_h

#include <fstream>
#include <string>

class Gidley {
public:
	Gidley();
	
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
#endif /* Gidley_hpp */
