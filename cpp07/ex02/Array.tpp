
template <typename T>

Array<T>::Array(size_t size) : m_size(size), m_data(new T[size])
{
	std::memset(m_data, 0, size * sizeof(T));
	std::cout << "Array of size " << size << " created." << std::endl;
}

template <typename T>

Array<T>::Array(const Array& other) : m_size(other.m_size), m_data(new T[other.m_size])
{
	std::memcpy(m_data, other.m_data, other.m_size * sizeof(T));
	std::cout << "Array of size " << m_size << " copied." << std::endl;
}

template <typename T>

Array<T>::~Array()
{
	delete[] m_data;
	std::cout << "Array of size " << m_size << " destroyed." << std::endl;
}

template <typename T>

Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
	{
		return *this;
	}
	
	delete[] m_data;
	m_size = other.m_size;
	m_data = new T[other.m_size];
	std::memcpy(m_data, other.m_data, other.m_size * sizeof(T));
	std::cout << "Array of size " << m_size << " copied." << std::endl;
	
	return *this;
}


template <typename T>

T& Array<T>::operator[](size_t index)
{
	return m_data[index];
}

template <typename T>

const T& Array<T>::operator[](size_t index) const
{
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

