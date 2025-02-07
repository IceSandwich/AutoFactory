#pragma once
#include "Person.hpp"

class John : public PersonProductBase<John> {
public:
	John(int age);

	void sayGoodbye() override;
};
