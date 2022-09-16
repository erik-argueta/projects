//
//  New_Lex.hpp
//  iPad-Verify
//
//  Created by Erik Argueta on 6/30/22.
//

#ifndef New_Lex_h
#define New_Lex_h

#include <fstream>
#include <string>

class NewLexington {
public:
	NewLexington();
	
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

#endif /* New_Lex_hpp */
