#include "Character.hpp"

Character::Character()
{
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i])
            delete materia[i];
    }
}

Character::Character(const Character &Character) : ICharacter(Character)
{
    *this = Character;
}

Character &Character::operator=(const Character &other)
{
    // Check for self-assignment
    if (this == &other)
        return *this;

    // Copy the name
    this->name = other.name;

    // Delete existing materia and clone from other
    for (int i = 0; i < 4; i++)
    {
        if (this->materia[i])
        {
            delete this->materia[i];
            this->materia[i] = NULL; // Avoid dangling pointer
        }
        if (other.materia[i])
            this->materia[i] = other.materia[i]->clone();
    }
    return *this;
}

Character::Character(std::string const &name) :  name(name)
{
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++) // Look for the first empty slot
    {
        if (materia[i] == NULL)
        {
            materia[i] = m; // Equip the materia in the first empty slot found
            return; // Exit after equipping
        }
    }
    std::cout << "Inventory is full" << std::endl; // If no empty slot was found
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        delete materia[idx]; // Delete the materia in the specified slot
        materia[idx] = NULL; // Set the specified slot to NULL to indicate it's empty
        std::cout << "Unequipped materia " << idx << std::endl;
    }
    else
    {
        std::cout << "Invalid index" << std::endl;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->materia[idx])
        this->materia[idx]->use(target);
    else
        std::cout << "Invalid index" << std::endl;
}