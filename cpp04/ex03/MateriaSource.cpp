#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
    {
        if (this->materias[i])
        {
            delete this->materias[i];
            this->materias[i] = NULL; // Avoid dangling pointer
        }
        if (other.materias[i])
            this->materias[i] = other.materias[i]->clone();
    }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!materias[i])
        {
            materias[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materias[i] && materias[i]->getType() == type)
        {
            return materias[i]->clone();
        }
    }
        std::cout << "Materia has not been learned yet" << std::endl;
    return NULL;
}