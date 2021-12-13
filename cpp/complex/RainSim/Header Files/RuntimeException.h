//
//  RuntimeException.h
//  general-workspace
//
//  Created by Erik Argueta on 12/12/21.
//

#ifndef RuntimeException_h
#define RuntimeException_h
#include <string>
using namespace std;

class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};

#endif /* RuntimeException_h */
