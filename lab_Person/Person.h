#pragma once
#include<iostream>
#include<string>
using namespace std;
enum gen { male, female };
class Person
{
private:
	const int ID;
	static int nextID;
	const gen gender;
	string name;
	Person* mother;
	Person* father;
	bool killed;
public:
	Person(const string& aName, const gen& aGender, Person* aMother = nullptr, Person* aFather = nullptr);
	void setName(const string& aName);
	void setFather(Person* aFather);
	string getName()const;
	string getGender()const;
	string getMotherName() const;
	string getFatherName() const;
	int getID()const;
	void printInfo(ostream& os);
	string checkRelatives(Person* pers)const;
	Person* giveBirth(const string& aName, const gen& aGender, Person* aFather = nullptr);
	bool isKilled()const;
	void kill();
};

