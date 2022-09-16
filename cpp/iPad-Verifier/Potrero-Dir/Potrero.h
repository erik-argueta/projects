//
//  Potrero.hpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/30/22.
//

#ifndef Potrero_h
#define Potrero_h

#include <fstream>
#include <string>

class Potrero {
public:
	Potrero();
	
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


#endif /* Potrero_h */
