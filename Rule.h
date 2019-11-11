#ifndef RULE_H_
#define RULE_H_
#include <string>
#include <iostream>
#include <vector>
#include "Predicate.h"

using namespace std;
class Rule {

public:
	Rule() {}
	Rule(Predicate myPredicate) : headPredicate(myPredicate) {}
	Rule(Predicate myPredicate, vector <Predicate> myPredicateList) : headPredicate(myPredicate),
		predicateList(myPredicateList) {}
	string toString();
	friend ostream& operator<<(ostream& os, Rule r);
	void addPredicate(Predicate pred);

private:

	Predicate headPredicate;
	vector <Predicate> predicateList;

};

#endif

