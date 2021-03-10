#pragma once

#include "Izraz.h"
#include "Operator.h"
#include "Operand.h"

class GenPost {
public:
	GenPost(const GenPost &) = delete;

	GenPost & operator=(const GenPost &) = delete;
	Izraz * operator()(Izraz *) const;

	static GenPost * GetGenPost();
protected:
private:
	GenPost();
	static GenPost * genPost;
};

