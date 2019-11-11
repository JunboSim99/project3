#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include "Relation.h"
using namespace std;

void Relation::addTuple(Tuple newTuple) {
	data.insert(newTuple);
}

string Relation::toStirng() {
	ostringstream oss;
	set<Tuple>::iterator itr;
	Tuple currentTuple;
	for (itr = data.begin(); itr != data.end(); ++itr) {
		currentTuple = *itr;
		oss << "  ";
		for (size_t i = 0; i < currentTuple.size(); i++) {
			/*for (size_t j = i + 1; j < currentTuple.size(); j++) {
				if (attributeList.at(i) == attributeList.at(j)) {
					this->project(attributeList);
				}
			}*/
			if (i == currentTuple.size() - 1) {
				oss << attributeList.at(i) << "=" << currentTuple.at(i);
			}
			else {
				oss << attributeList.at(i) << "=" << currentTuple.at(i) << ", ";
			}
		}
		oss << endl;
	}
	return oss.str();
}

Relation Relation::select(size_t column, string val) {

	Relation newRelation(this->relationName, this->attributeList);
	set<Tuple>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter) {
		if (iter->at(column) == val) {
			newRelation.addTuple(*iter);
		}
	}

	return newRelation;
}

Relation Relation::select(size_t column1, size_t column2) {

	Relation newRelation(this->relationName, this->attributeList);
	for (size_t i = 0; i < newRelation.attributeList.size(); ++i) {
		for (size_t j = i + 1; j < newRelation.attributeList.size(); ++j) {
			if (newRelation.attributeList.at(i) == newRelation.attributeList.at(j)) {
				newRelation.attributeList.erase(attributeList.begin()+j);
			}
		}
	}

	set<Tuple>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter) {
		if (iter->at(column1) == iter->at(column2)) {
			newRelation.addTuple(*iter);
		}
	}
	return newRelation;
}

Relation Relation::project(Scheme columns) {
	Relation newRelation(this->relationName, columns);
	set<Tuple>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter) {
		Tuple newTuple;
		for (size_t i = 0; i < columns.size(); ++i) {
			for (size_t j = 0; j < this->attributeList.size(); ++j) {
				if (columns.at(i) == this->attributeList.at(j)) {
					newTuple.push_back(iter->at(j));
				}
			}
		}
		newRelation.addTuple(newTuple);
	}
	return newRelation;
}

Relation Relation::rename(string oldName, string newName) {
	Relation newRelation(this->relationName, this->attributeList);
	set<Tuple>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter) {
		newRelation.addTuple(*iter);
	}
	for (size_t i = 0; i < attributeList.size(); ++i) {
		if (newRelation.attributeList.at(i) == oldName) {
			newRelation.attributeList.at(i) = newName;
			break;
		}
	}
	return newRelation;
}

set<Tuple> Relation::getData() {
	return data;
}

Scheme Relation::getAttribute() {
	return attributeList;
}