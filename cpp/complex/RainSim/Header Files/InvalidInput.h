//
//  InvalidInput.h
//  general-workspace
//
//  Created by Erik Argueta on 12/12/21.
//

#ifndef InvalidInput_h
#define InvalidInput_h
#include "RuntimeException.h"
#include <string>
using namespace std;

class InvalidInput : public RuntimeException {
public:
	InvalidInput(const string& err) : RuntimeException(err) {}
};


#endif /* InvalidInput_h */
