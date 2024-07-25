#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept> 

template <typename T>

class Array
{
private:
	T* m_data;
	size_t m_size;
	
public:
	Array(size_t size = 0);
	Array(const Array& other);
	~Array();
	Array& operator=(const Array& other);
	
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	size_t size() const;
	//void resize(size_t newSize);
};

#include "Array.tpp"
#endif 