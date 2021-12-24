#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
int main()
{
	Person adam("adam", gen::male);
	Person eva("eva", female);
	eva.printInfo(cout);
	adam.printInfo(cout);
	Person child1 = *eva.giveBirth("son", gen::male, &adam);
	Person child2 = *eva.giveBirth("daughter", gen::male, &adam);
	child1.printInfo(cout);
	child2.printInfo(cout);
	Person danila("danila", male, &eva);
	danila.printInfo(cout);
	cout << child1.checkRelatives(&child2) << endl;
	cout << child1.checkRelatives(&danila) << endl;
	cout << child2.checkRelatives(&danila) << endl;
	adam.kill();
	adam.printInfo(cout);
	child1.printInfo(cout);
}
