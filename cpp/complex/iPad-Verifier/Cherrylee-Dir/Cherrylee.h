//
//  Cherrylee.hpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/30/22.
//

#ifndef Cherrylee_h
#define Cherrylee_h

#include <fstream>
#include <string>

class Cherrylee {
public:
	Cherrylee();
	
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

#endif /* Cherrylee_hpp */
