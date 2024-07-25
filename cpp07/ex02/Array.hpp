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
	Array(size_t size = 0)
	{
		m_size = size;
		m_data = new T[size];
		std::memset(m_data, 0, size * sizeof(T));
	}
	Array(const Array& other)
	{
		m_size = other.m_size;
		m_data = new T[other.m_size];
		std::memcpy(m_data, other.m_data, other.m_size * sizeof(T));
	}
	~Array()
	{
		delete[] m_data;
	}
	Array& operator=(const Array& other)
	{
		if (this == &other)
		{
			return *this;
		}
		
		delete[] m_data;
		m_size = other.m_size;
		m_data = new T[other.m_size];
		std::memcpy(m_data, other.m_data, other.m_size * sizeof(T));
		
		return *this;
	}
	
	
	T& operator[](size_t index)
	{
		if (index >= m_size)
		{ // Assuming 'size' is the size of your array
        	throw std::out_of_range("Index out of bounds");
    	}
    	return m_data[index];
	}
	const T& operator[](size_t index) const
	{
		if (index >= m_size)
		{ // Assuming 'size' is the size of your array
        	throw std::out_of_range("Index out of bounds");
   		}
    	return m_data[index];
	}
	
	size_t size() const
	{
		return m_size;
	}
	
	//void resize(size_t newSize);
};

#endif 