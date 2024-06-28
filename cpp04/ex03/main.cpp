#include "AMateria.hpp"
#include"ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>


int main()
{
    IMateriaSource* src = new MateriaSource();
    ICharacter* bob = new Character("bob");
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(0, *bob);


    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(1, *bob);


    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(2, *bob);

    me->unequip(2);
    me->use(2, *bob);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(2, *bob);


    delete src;
    delete me;
    delete bob;

    return 0;
}