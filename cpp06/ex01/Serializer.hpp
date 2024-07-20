#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // For uintptr_t in C++98
#include "Data.hpp"

class Serializer
{
	private:
	    Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
	public:
	    static uintptr_t serialize(Data* ptr);
	    static Data* deserialize(uintptr_t raw);
		~Serializer();
};

#endif