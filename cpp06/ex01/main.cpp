#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.value = 42;

    uintptr_t serialized = reinterpret_cast<uintptr_t>(&data);

    std::cout << "Serialized: " << serialized << std::endl;

    Data* deserialized = reinterpret_cast<Data*>(serialized);

    std::cout << "Data: " << deserialized->value << std::endl;

    return 0;
}

// int main()
// {
//     Data data;
//     data.value = 42;
//     data.value2 = 43;
//     data.value3 = 'a';

//     int *serialized = reinterpret_cast<int*>(&data);
//     std::cout << "Serialized: " << *serialized << std::endl;
//     serialized++;
//     std::cout << "Serialized: " << *serialized << std::endl;
//     serialized++;
//     std::cout << "Serialized: " << *serialized << std::endl;
//     char *serializedChar = reinterpret_cast<char*>(serialized);
//     std::cout << "Serialized: " << *serializedChar << std::endl;
//     return 0;
// }

