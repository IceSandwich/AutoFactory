#pragma once

#include "Animal.hpp"

class Cat : public Animal::Registrar<Cat> {
public:
	Cat();
	~Cat();
	void sayHello() override;
};

