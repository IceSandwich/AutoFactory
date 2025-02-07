#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
	std::cout << "invoke " << GetRegistrarClassName() << " constructor" << std::endl;
}

Cat::~Cat() {
	std::cout << "deconstrctor " << GetRegistrarClassName() << std::endl;
}

void Cat::sayHello() {
	std::cout << GetRegistrarClassName() << " say hello "  << std::endl;
}
