#include <iostream>
#include <cstdint>

#include <cstdint>

void* alignPointer(void* ptr, std::size_t alignment) {
    // Cast the pointer to uintptr_t for arithmetic operations
    uintptr_t address = reinterpret_cast<uintptr_t>(ptr);

    // Align the address to the specified alignment boundary
    address = (address + alignment - 1) & ~(alignment - 1);

    // Cast the aligned address back to a pointer
    return reinterpret_cast<void*>(address);
}

int main() {
    // Example usage of alignPointer
    char buffer[100];

    std::cout << "Original address: " << static_cast<void*>(buffer) << std::endl;

    void* alignedPtr = alignPointer(buffer, 16);
    std::cout << "Aligned address (16-byte): " << alignedPtr << std::endl;

    alignedPtr = alignPointer(buffer, 32);
    std::cout << "Aligned address (32-byte): " << alignedPtr << std::endl;

    return 0;
}

