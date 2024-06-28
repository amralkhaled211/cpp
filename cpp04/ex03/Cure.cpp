#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure")
{
    
}

Cure::Cure(const Cure &cure): AMateria(cure)
{
    
}

Cure::~Cure()
{
    
}

Cure &Cure::operator=(const Cure &cure)
{
    if (this == &cure)
        return *this;
    AMateria::operator=(cure);
    return *this;
}

AMateria* Cure::clone() const
{
    AMateria *Cure_clone;

    try
    {
        Cure_clone = new Cure(*this);
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
    return Cure_clone;
}


void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
