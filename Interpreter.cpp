#include <iostream>
#include <string>
#include <sstream>
#include "Interpreter.h"
#include "Relation.h"
#include "Predicate.h"
using namespace std;

Relation Interpreter::evaluateQuery(Predicate queryPredicate) {
	Relation currentRelation = database[queryPredicate.getID()];
	Scheme projectColumns;
	vector<string> columnNames;
	for (size_t i = 0; i < queryPredicate.getParameter().size(); ++i) {
		string currentParameter = queryPredicate.getParameter().at(i);
		if (isConstant(currentParameter)) {
			currentRelation = currentRelation.select(i, currentParameter);
		}
		else {
			projectColumns.push_back(currentRelation.getAttribute().at(i));
			columnNames.push_back(currentParameter);

			if (i > 0) {
				for (size_t j = i - 1; j >= 0; --j) {
					if (queryPredicate.getParameter().at(i) == queryPredicate.getParameter().at(j)) {
						projectColumns.pop_back();
						columnNames.pop_back();
						currentRelation = currentRelation.select(j, i);
						break;
					}
					if (j == 0) { break; }
				}
			}
		}
	}

	if (projectColumns.size() > 0) {
		currentRelation = currentRelation.project(projectColumns);
	}

	if (columnNames.size() > 0) {
		for (size_t i = 0; i < currentRelation.getAttribute().size(); ++i) {
			currentRelation = currentRelation.rename(currentRelation.getAttribute().at(i), columnNames.at(i));
		}
	}
	return currentRelation;
}

bool Interpreter::isConstant(string param) {
	if (param.at(0) == '\'') {
		return true;
	}
	else {
		return false;
	}
}

string Interpreter::toString() {
	ostringstream oss;
	Predicate currentQuery;
	Relation currentRelation;
	for (size_t i = 0; i < datalog.getQuery().size(); ++i) {
		currentQuery = datalog.getQuery().at(i);
		oss << datalog.getQuery().at(i) << "? ";
		map<string, Relation>::iterator iter;
		for (iter = database.begin(); iter != database.end(); ++iter) {
			if (iter->first == currentQuery.getID()) {
				currentRelation = iter->second;
			}
		}
		if (evaluateQuery(currentQuery).getData().empty()) {
			oss << "No" << endl;
		}
		else if (evaluateQuery(currentQuery).getAttribute() == currentRelation.getAttribute()) {
			oss << "Yes(" << evaluateQuery(currentQuery).getData().size() << ")" << endl;
		}
		else {
			oss << "Yes(" << evaluateQuery(currentQuery).getData().size() << ")" << endl;
			oss << evaluateQuery(currentQuery).toStirng();
		}
	}
	return oss.str();
}