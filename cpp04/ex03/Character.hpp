#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter
{
private:
    std::string name;
    AMateria *materia[4];
public:
    Character();
    ~Character();
    Character(const Character &Character);
    Character &operator=(const Character &Character);
    Character(std::string const &name);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif