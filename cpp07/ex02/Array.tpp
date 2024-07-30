#include "Array.hpp"
#include <stdexcept>
#include <algorithm>

template <typename T>
Array<T>::Array(size_t size) : m_data(size ? new T[size] : NULL), m_size(size)
{

}

template <typename T>
Array<T>::Array(const Array& other) : m_data(other.m_size ? new T[other.m_size] : NULL), m_size(other.m_size)
{
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
}

template <typename T>
Array<T>::~Array()
{
    delete[] m_data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
	{
        delete[] m_data;
        m_data = other.m_size ? new T[other.m_size] : NULL;
        m_size = other.m_size;
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= m_size)
	{
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= m_size)
	{
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return m_size;
}
// template <typename T>

// void Array<T>::resize(size_t newSize)
// {
// 	T* newData = new T[newSize];
// 	size_t minSize = (m_size > newSize) ? newSize : m_size;
	
// 	for (size_t i = 0; i < minSize; i++) {
// 		newData[i] = m_data[i];
// 	}
	
// 	delete[] m_data;
// 	m_data = newData;
// 	m_size = newSize;
// }

