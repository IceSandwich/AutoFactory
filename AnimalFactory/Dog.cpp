#include <iostream>
#include "Dog.hpp"

Dog::Dog() {
	std::cout << "constructor " << GetRegistrarClassName() << std::endl;
}

Dog::~Dog() {
	std::cout << "deconstrctor " << GetRegistrarClassName() << std::endl;
}

void Dog::sayHello() {
	std::cout << "calling " << GetRegistrarClassName() << " sayHello" << std::endl;
}
