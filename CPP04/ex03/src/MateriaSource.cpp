#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
    for(size_t i = 0; i < 4; i++)
        stored[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) 
{
    for(size_t i = 0; i < 4; i++)
    {
        if (other.stored[i])
            stored[i] = other.stored[i];
        else
            stored[i] = NULL;
    }
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for(size_t i = 0; i < 4; i++)
            if (stored[i])
                delete stored [i];
        for(size_t i = 0; i < 4; i++)
        {
            if (other.stored[i])
                stored[i] = other.stored[i];
            else
                stored[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
        if (stored[i])
            delete stored[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for(size_t i = 0; i < 4; i++)
        if(!stored[i])
        {
            stored[i] = m->clone();
            return;
        }
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++)
        if (stored[i]->getType() == type)
            return (stored[i]->clone());
    return (0);
}

