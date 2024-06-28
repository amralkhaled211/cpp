#include "AMateria.hpp"


AMateria::AMateria()
{

}

AMateria::AMateria(std::string const & type): Atype(type)
{
    
}

AMateria::AMateria(const AMateria &AMateria)
{
    this->Atype = AMateria.Atype;
}


AMateria::~AMateria()
{

}

AMateria &AMateria::operator=(const AMateria &AMateria)
{
    if (this == &AMateria)
        return *this;
    this->Atype = AMateria.Atype;
    return *this;
}


std::string const & AMateria::getType() const
{
    return this->Atype;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}