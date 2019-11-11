#include <iostream>
#include <string>
#include <set>
#include "Tuple.h"
#include <sstream>
using namespace std;

string Tuple::toString(){
	ostringstream oss;
	for (size_t i = 0; i < this->size(); i++) {
		oss << this->at(i);
	}
	return oss.str();
}