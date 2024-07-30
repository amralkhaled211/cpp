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


//int main()
// {
//     std::cout << std::endl << "---- LEARNING MATERIA -----" << std::endl << std::endl;

//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     std::cout << std::endl << "---- CREATE MATERIA ----" << std::endl << std::endl;

//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     std::cout << "LEAKLEAKLEAKLEAK" << std::endl;
//     tmp = src->createMateria("ice");
//     std::cout << "value of tmp: " << tmp << std::endl;
//     me->equip(tmp);
//     // tmp = src->createMateria("cure");
//     // std::cout << "value of tmp: " << tmp << std::endl;
//     // me->equip(tmp);

//     std::cout << std::endl << "---- CHARACTER USING MATERIA" << std::endl << std::endl;

//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     me->use(3, *bob);
//     me->use(4, *bob);
//     me->use(5, *bob);
//     me->use(6, *bob);

//     // std::cout << std::endl << "---- UNEQUIP MATERIA ----" << std::endl << std::endl;

//     // me->unequip(1);

//     std::cout << std::endl << "---- DELETING ... ----" << std::endl << std::endl;

//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }