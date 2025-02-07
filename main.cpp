/**
 * @author gh Corgice @IceSandwich
 * @date Jun 2023
 * @license MIT
 */

#include <iostream>
#include "AnimalFactory/Animal.hpp"
#include "PersonFactory/Person.hpp"

int main() {
	Animal::PrintRegisteredClassName();

	Animal::Make("Dog")->sayHello();

	{
		auto cat = Animal::Make("Cat");
		cat->sayHello();
		cat->PrintRegisteredClassName();
	}

	Person::PrintRegisteredClassName();
	Person::Make("John", 32)->sayGoodbye();

	{
		auto mike = Person::Make("Mike", 64);
		mike->sayGoodbye();
		mike->PrintRegisteredClassName();
	}

	system("pause");
	return 0;
}
