//
//  Rio_Vista.hpp
//  iPad-Verify
//
//  Created by Erik Argueta on 7/5/22.
//

#ifndef Rio_Vista_h
#define Rio_Vista_h

#include <fstream>
#include <string>

class RioVista {
public:
	RioVista();
	
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

#endif /* Rio_Vista_h */
