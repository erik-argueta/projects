//
//  Cortada.hpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/30/22.
//

#ifndef Cortada_h
#define Cortada_h

#include <fstream>
#include <string>

class Cortada {
public:
	Cortada();
	
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

#endif /* Cortada_hpp */
