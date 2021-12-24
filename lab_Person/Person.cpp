#include "Person.h"
int Person::nextID = 0;
string toString(const gen& aGen) {
	if (aGen == male) {
		return "male";
	}
	return "female";
}

void Person::setName(const string& aName)
{
	if (aName == "") {
		throw exception("You did not write the name");
	}
	name = aName;
}

void Person::setFather(Person * aFather)
{
	father = aFather;
}

Person::Person(const string& aName, const gen& aGender, Person * aMother, Person * aFather):ID(++nextID), gender(aGender)
{
	killed = false;
	if (aFather != nullptr && aFather->killed == true) {
		throw exception("Person can't be born after death of it's father");
	}
	if (aMother != nullptr && aMother->killed == true) {
		throw exception("Person can't be born after death of it's mother");
	}
	if (aName == "") {
		throw exception("Person must have a name");
	}
	if (ID > 2 && aMother == nullptr) {
		throw exception("This person must have mother");
	}
	if (ID == 1 && aMother == nullptr && (aName != "adam" || aGender != male)) {
		throw exception("First person must be adam & he must be a male");
	}
	if (ID == 2 && aMother == nullptr && (aName != "eva" || aGender != female)) {
		throw exception("Second person must be eva & he must be a female");
	}
	name = string(aName);
	if (aMother != nullptr) {
		mother = aMother;
	}
	if (aFather != nullptr) {
		father = aFather;
	}
}

string Person::getName()const
{
	return name;
}

string Person::getGender()const
{
	return toString(gender);
}

string Person::getMotherName() const
{
	if (mother == nullptr) {
		return "this person have not got mother";
	}
	return (mother->getName());
}

string Person::getFatherName() const
{
	if (father == nullptr) {
		return "this person have not got father";
	}
	return (father->getName());
}

int Person::getID()const
{
	return ID;
}

void Person::printInfo(ostream & os)
{
	os << "Name: " << this->getName() << endl;
	os << "Gender: " << this->getGender() << endl;
	os << "ID: " << this->getID() << endl;
	os << "Mother: " << this->getMotherName();
	if (mother != nullptr) {
		os << "ID: " << this->mother->getID();
	}
	os << endl;
	os << "Father: " << this->getFatherName();
	if (father != nullptr) {
		os << "ID: " << this->father->getID();
	} 
	os << endl;
	if (killed) {
		os << "Person is dead" << endl;
	}
	else {
		os << "Person is alive" << endl;
	}
}

string Person::checkRelatives(Person * pers) const
{
	string out;
	if ((this->mother == pers->mother) && (this->father == pers->father)) {
		out = this->getName() + " & " + pers->getName() + " have common father & mother";
	}
	if ((this->mother == pers->mother) && !(this->father == pers->father)) {
		out = this->getName() + " & " + pers->getName() + " have common only mother";
	}
	if (!(this->mother == pers->mother) && (this->father == pers->father)) {
		out = this->getName() + " & " + pers->getName() + " have common father";
	}
	return out;
}

Person* Person::giveBirth(const string& aName, const gen& aGender, Person * aFather)
{
	if (aFather != nullptr && aFather->killed == true) {
		throw exception("Person can't be born after death of it's father");
	}
	if (killed == true) {
		throw exception("Person can't be born after death of it's mother");
	}
	if (aName == "") {
		throw exception("Child must have a name");
	}
	if (this->gender == male) {
		throw exception("Mother must have gender female");
	}
	if (aFather->gender == female) {
		throw exception("Father must have gender male");
	}
	Person* child = new Person(aName, aGender, this, aFather);
	return child;
}

bool Person::isKilled() const
{
	return killed;
}

void Person::kill()
{
	killed = true;
	name += "(Dead)";
}


