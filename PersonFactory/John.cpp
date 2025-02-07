#include "John.hpp"

inline John::John(int age) {
	std::cout << GetRegistrarClassName() << " is " << age << " years old." << std::endl;
}

void John::sayGoodbye() {
	std::cout << GetRegistrarClassName() << " say goodbye to you." << std::endl;
}
