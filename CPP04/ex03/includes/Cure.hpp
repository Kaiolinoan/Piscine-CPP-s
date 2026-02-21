#ifndef CURE_HPP
#define CURE_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure: public  virtual AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        AMateria* clone() const;
        void use(ICharacter& target);
};



#endif

