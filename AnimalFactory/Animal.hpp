#pragma once

#include "../factory.hpp"

class Animal : public Factory<Animal> {
public:
	virtual ~Animal() = default;
	virtual void sayHello() = 0;
};

