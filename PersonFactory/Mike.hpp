#pragma once
#include "Person.hpp"

class Mike : public PersonProductBase<Mike> {
public:
	Mike(int age);

	void sayGoodbye() override;
};
