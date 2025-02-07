#pragma once

#include "../factory.hpp"

class Person : public Factory<Person, int> {
public:
	virtual ~Person() = default;
	virtual void sayGoodbye() = 0;
};

template <typename T>
class PersonProductBase : public Person::Registrar<T> {
public:
	~PersonProductBase() {
		std::cout << Person::Registrar<T>::GetRegistrarClassName() << " died." << std::endl;
	}
};
