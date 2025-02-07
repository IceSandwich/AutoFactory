#pragma once

#include "Animal.hpp"

class Dog : public Animal::Registrar<Dog> {
public:
	Dog();
	~Dog();
	void sayHello() override;
};
