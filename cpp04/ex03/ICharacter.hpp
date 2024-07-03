#ifndef ICARACTER_HPP
#define ICARACTER_HPP

#include <iostream>

class AMateria;

class ICharacter
{
	public:
		ICharacter();
		ICharacter(const ICharacter &copy);
		ICharacter & operator=(const ICharacter &copy);
		virtual ~ICharacter();
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif