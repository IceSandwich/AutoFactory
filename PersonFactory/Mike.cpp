#include <iostream>
#include "Mike.hpp"

inline Mike::Mike(int age) {
	std::cout << GetRegistrarClassName() << " is " << age << " years old." << std::endl;
}

void Mike::sayGoodbye() {
	std::cout << "haha, mike say goodbye to u" << std::endl;
}
