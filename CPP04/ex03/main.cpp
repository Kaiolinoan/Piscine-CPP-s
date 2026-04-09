#include "Interface.hpp"

// void testFullInventory() {
//     std::cout << "--- Test Full Inventory ---" << std::endl;
//     IMateriaSource* src = new MateriaSource();
//     AMateria* temp1 = new Ice();
//     AMateria* temp2 = new Ice();
//     AMateria* temp3 = new Ice();
//     AMateria* temp4 = new Ice();
//     src->learnMateria(temp1);
//     src->learnMateria(temp2);
//     src->learnMateria(temp3);
//     src->learnMateria(temp4);
    
//     AMateria* extra = new Ice();
//     src->learnMateria(extra);
    
//     ICharacter* me = new Character("me");
//     me->equip(src->createMateria("ice"));
//     me->equip(src->createMateria("ice"));
//     me->equip(src->createMateria("ice"));
//     me->equip(src->createMateria("ice"));
    
//     AMateria* fifth = src->createMateria("ice");
//     me->equip(fifth);
//     delete fifth;
//     delete me;
//     delete src;
//     delete temp1;
//     delete temp2;
//     delete temp3;
//     delete temp4;
//     delete extra;
// }

// void testAssignmentLeak() {
//     std::cout << "--- Test Assignment Leak ---" << std::endl;
//     Character a("A");
//     a.equip(new Ice());
    
//     Character b("B");
//     b.equip(new Cure());
    
//     b = a;
// }

// void testDeepCopy() {
//     std::cout << "--- Test Deep Copy ---" << std::endl;
//     Character* dur0 = new Character("dur0");
//     dur0->equip(new Ice());
    
//     Character* dur1 = new Character(*dur0);
//     delete dur0;
    
//     dur1->use(0, *dur1); 
 
//     delete dur1;
// }

// void testUnequip() {
//     std::cout << "--- Test Unequip ---" << std::endl;
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
    
//     tmp = new Ice();
//     me->equip(tmp);
//     me->unequip(0);
    
//     delete tmp; 
//     delete me;
// }

// int main()
// {
//     testDeepCopy();
//     testAssignmentLeak();
//     testFullInventory();
//     testUnequip();
// }

int main()
{
    IMateriaSource* src = new MateriaSource();
    AMateria* ice_temp = new Ice();
    AMateria* cure_temp = new Cure();
    
    src->learnMateria(ice_temp);
    src->learnMateria(cure_temp);

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    delete ice_temp;
    delete cure_temp;
    return 0;
}