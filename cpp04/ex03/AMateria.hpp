
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
protected:
    std::string Atype;
public:
    AMateria();
    virtual ~AMateria();
    AMateria(const AMateria &AMateria);
    AMateria &operator=(const AMateria &AMateria);
    AMateria(std::string const & type);


    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    
};

#endif