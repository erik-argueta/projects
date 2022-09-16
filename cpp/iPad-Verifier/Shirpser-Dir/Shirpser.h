//
//  Shirpser.hpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/30/22.
//

#ifndef Shirpser_h
#define Shirpser_h

#include <fstream>
#include <string>

class Shirpser {
public:
	Shirpser();
	
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

#endif /* Shirpser_hpp */
