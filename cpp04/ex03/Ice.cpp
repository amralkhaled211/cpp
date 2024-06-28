#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
    
}

Ice::Ice(const Ice &ice): AMateria(ice)
{
    
}

Ice &Ice::operator=(const Ice &ice)
{
    if (this == &ice)
        return *this;
    AMateria::operator=(ice);
    return *this;
}

Ice::~Ice()
{
    
}

AMateria* Ice::clone() const
{
    AMateria *Ice_clone;
    try
    {
        Ice_clone = new Ice(*this);
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
    return Ice_clone;
}


void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}