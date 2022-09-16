//
//  Columbia.hpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/30/22.
//

#ifndef Columbia_h
#define Columbia_h

#include <fstream>
#include <string>

class Columbia {
public:
	Columbia();
	
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
#endif /* Columbia_hpp */
