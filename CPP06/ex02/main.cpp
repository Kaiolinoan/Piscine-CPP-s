#include "Base.hpp"

int  main()
{
    srand(time(0));

    Base* item = generate();

    if (!item)
        return 1;

    Base& item_ref = *item; 
    identify(item);
    identify(item_ref);
    delete item;
}