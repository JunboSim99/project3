#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Parser.h"
#include "Scanner.h"
#include "Relation.h"
#include "Scheme.h"
#include "Tuple.h"
#include "Interpreter.h"

using namespace std;

int main(int argc, char * argv[]) {

	//Test case for project, select and rename

	//Project alpha
	//Scheme scheme1;
	//scheme1.push_back("Cat");
	//scheme1.push_back("Dog");
	//scheme1.push_back("Fish");
	//Relation relation1("Alpha", scheme1);
	//Tuple tuple1;
	//tuple1.push_back("2");
	//tuple1.push_back("3");
	//tuple1.push_back("2");
	//Tuple tuple2;
	//tuple2.push_back("3");
	//tuple2.push_back("3");
	//tuple2.push_back("2");
	//Tuple tuple3;
	//tuple3.push_back("6");
	//tuple3.push_back("7");
	//tuple3.push_back("4");
	//Tuple tuple4;
	//tuple4.push_back("1");
	//tuple4.push_back("4");
	//tuple4.push_back("1");
	//Tuple tuple5;
	//tuple5.push_back("1");
	//tuple5.push_back("2");
	//tuple5.push_back("5");

	//relation1.addTuple(tuple1);
	//relation1.addTuple(tuple2);
	//relation1.addTuple(tuple3);
	//relation1.addTuple(tuple4);
	//relation1.addTuple(tuple5);
	//cout << relation1.toStirng() << endl;

	//Relation projectRelation = relation1;
	//Scheme projectScheme;
	//projectScheme.push_back("Fish");
	//projectScheme.push_back("Dog");
	//projectRelation = projectRelation.project(projectScheme);
	//cout << projectRelation.toStirng();

	//Project beta
	//Scheme scheme1;
	//scheme1.push_back("Cat");
	//scheme1.push_back("Fish");
	//scheme1.push_back("Bird");
	//scheme1.push_back("Bunny");
	//Relation relation1("Alpha", scheme1);
	//Tuple tuple1;
	//tuple1.push_back("1");
	//tuple1.push_back("5");
	//tuple1.push_back("2");
	//tuple1.push_back("4");
	//Tuple tuple2;
	//tuple2.push_back("3");
	//tuple2.push_back("4");
	//tuple2.push_back("2");
	//tuple2.push_back("4");
	//Tuple tuple3;
	//tuple3.push_back("4");
	//tuple3.push_back("3");
	//tuple3.push_back("2"); 
	//tuple3.push_back("7");
	//Tuple tuple4;
	//tuple4.push_back("1");
	//tuple4.push_back("5");
	//tuple4.push_back("8");
	//tuple4.push_back("3");
	//Tuple tuple5;
	//tuple5.push_back("6");
	//tuple5.push_back("4");
	//tuple5.push_back("9");
	//tuple5.push_back("2");

	//relation1.addTuple(tuple1);
	//relation1.addTuple(tuple2);
	//relation1.addTuple(tuple3);
	//relation1.addTuple(tuple4);
	//relation1.addTuple(tuple5);
	//cout << relation1.toStirng() << endl;
	//
	//Relation projectRelation1 = relation1;
	//Scheme projectScheme1;
	//projectScheme1.push_back("Bunny");
	//projectRelation1 = projectRelation1.project(projectScheme1);
	//cout << projectRelation1.toStirng() << endl;

	//Relation projectRelation2 = relation1;
	//Scheme projectScheme2;
	//projectScheme2.push_back("Bunny");
	//projectScheme2.push_back("Bird");
	//projectScheme2.push_back("Cat");
	//projectRelation2 = projectRelation2.project(projectScheme2);
	//cout << projectRelation2.toStirng();



	//Rename test 1
	//Scheme scheme1;
	//scheme1.push_back("First Name");
	//scheme1.push_back("Last Name");
	//scheme1.push_back("ID");
	//Relation relation1("Student", scheme1);
	//Tuple tuple1;
	//tuple1.push_back("Harry");
	//tuple1.push_back("Kane");
	//tuple1.push_back("101");
	//Tuple tuple2;
	//tuple2.push_back("Kyle");
	//tuple2.push_back("Walker");
	//tuple2.push_back("102");
	//Tuple tuple3;
	//tuple3.push_back("Lionel");
	//tuple3.push_back("Messi");
	//tuple3.push_back("103");
	//relation1.addTuple(tuple1);
	//relation1.addTuple(tuple2);
	//relation1.addTuple(tuple3);
	//cout << relation1.toStirng() << endl;
	//Relation renamedRelation1 = relation1;
	//renamedRelation1 = renamedRelation1.rename("First Name", "NickName");
	//cout << renamedRelation1.toStirng();

	//Rename test 2
	//Scheme scheme1;
	//scheme1.push_back("Name");
	//scheme1.push_back("Number");
	//scheme1.push_back("Age");
	//Relation relation1("Roster for Real Madrid", scheme1);
	//Tuple tuple1;
	//tuple1.push_back("Eden Hazard");
	//tuple1.push_back("7");
	//tuple1.push_back("28");
	//Tuple tuple2;
	//tuple2.push_back("Karim Benzema");
	//tuple2.push_back("9");
	//tuple2.push_back("31");
	//Tuple tuple3;
	//tuple3.push_back("Gareth Bale");
	//tuple3.push_back("11");
	//tuple3.push_back("30");
	//relation1.addTuple(tuple1);
	//relation1.addTuple(tuple2);
	//relation1.addTuple(tuple3);
	//cout << relation1.toStirng() << endl;
	//Relation renamedRelation1 = relation1;
	//renamedRelation1 = renamedRelation1.rename("Age", "Goals");
	//renamedRelation1 = renamedRelation1.rename("Number", "Age");
	//cout << renamedRelation1.toStirng();

	//select type1 test1
	/*Scheme scheme1;
	scheme1.push_back("Name");
	scheme1.push_back("Number");
	scheme1.push_back("Age");
	Relation relation1("Roster for Real Madrid", scheme1);
	Tuple tuple1;
	tuple1.push_back("Eden Hazard");
	tuple1.push_back("7");
	tuple1.push_back("28");
	Tuple tuple2;
	tuple2.push_back("Karim Benzema");
	tuple2.push_back("9");
	tuple2.push_back("31");
	Tuple tuple3;
	tuple3.push_back("Gareth Bale");
	tuple3.push_back("11");
	tuple3.push_back("30");
	relation1.addTuple(tuple1);
	relation1.addTuple(tuple2);
	relation1.addTuple(tuple3);
	cout << relation1.toStirng() << endl;
	Relation selectRelation1 = relation1;
	selectRelation1 = selectRelation1.select(0, "Karim Benzema");
	cout << selectRelation1.toStirng();*/

	//select type1 test2
	/*Scheme scheme1;
	scheme1.push_back("Name");
	scheme1.push_back("Number");
	scheme1.push_back("Age");
	Relation relation1("Roster for Real Madrid", scheme1);
	Tuple tuple1;
	tuple1.push_back("Eden Hazard");
	tuple1.push_back("7");
	tuple1.push_back("28");
	Tuple tuple2;
	tuple2.push_back("Karim Benzema");
	tuple2.push_back("9");
	tuple2.push_back("31");
	Tuple tuple3;
	tuple3.push_back("Gareth Bale");
	tuple3.push_back("11");
	tuple3.push_back("30");
	relation1.addTuple(tuple1);
	relation1.addTuple(tuple2);
	relation1.addTuple(tuple3);
	cout << relation1.toStirng() << endl;
	Relation selectRelation1 = relation1;
	selectRelation1 = selectRelation1.select(2, "Harry Kane");
	cout << selectRelation1.toStirng();*/

	//Select type 2 test 1
	//Scheme scheme1;
	//scheme1.push_back("Name");
	//scheme1.push_back("Number");
	//scheme1.push_back("Age");
	//Relation relation1("Roster for Real Madrid", scheme1);
	//Tuple tuple1;
	//tuple1.push_back("Eden Hazard");
	//tuple1.push_back("7");
	//tuple1.push_back("7");
	//Tuple tuple2;
	//tuple2.push_back("Karim Benzema");
	//tuple2.push_back("9");
	//tuple2.push_back("9");
	//Tuple tuple3;
	//tuple3.push_back("Eden Hazard");
	//tuple3.push_back("9");
	//tuple3.push_back("28");
	//relation1.addTuple(tuple1);
	//relation1.addTuple(tuple2);
	//relation1.addTuple(tuple3);
	//cout << relation1.toStirng() << endl;
	//Relation selectRelation1 = relation1;
	//selectRelation1 = selectRelation1.select(1, 2);
	//cout << selectRelation1.toStirng();

	//Select type 2 test 2
	//Scheme scheme1;
	//scheme1.push_back("Name");
	//scheme1.push_back("Number");
	//scheme1.push_back("Age");
	//Relation relation1("Roster for Real Madrid", scheme1);
	//Tuple tuple1;
	//tuple1.push_back("Eden Hazard");
	//tuple1.push_back("28");
	//tuple1.push_back("28");
	//Tuple tuple2;
	//tuple2.push_back("Isco");
	//tuple2.push_back("28");
	//tuple2.push_back("28");
	//Tuple tuple3;
	//tuple3.push_back("Karim Benzema");
	//tuple3.push_back("28");
	//tuple3.push_back("28");
	//relation1.addTuple(tuple1);
	//relation1.addTuple(tuple2);
	//relation1.addTuple(tuple3);
	//cout << relation1.toStirng() << endl;
	//Relation selectRelation1 = relation1;
	//selectRelation1 = selectRelation1.select(1, 2);
	//cout << selectRelation1.toStirng();

	//Actual main
	ifstream input;
	input.open("test_case6.txt");
	Scanner myScanner("test_case6.txt"); //change it to argv[1]
	myScanner.tokenize();
	Parser myParser(myScanner.getTokens());
	myParser.parse();
	Interpreter myInt(myParser.getDatalog());                  
	cout << myInt.toString();

	return 0;
}