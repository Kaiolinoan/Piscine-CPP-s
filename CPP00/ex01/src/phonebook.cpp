#include "phonebook.h"


phonebook::phonebook() : index(0) {}
phonebook::~phonebook() {}

int phonebook::get_index() const
{
    return (index);
}
Contact phonebook::get_contact_at(int index) const
{
    return(Contacts[index]);
}

void phonebook::set_index(const int& value)
{
    index = value;
    return;
}
void phonebook::add_contact(std::string param_first_name, std::string param_last_name, std::string param_nickname, std::string param_phone_number, std::string param_password)
{
    if (index > 7)
        set_index(0);
    Contacts[index].set_firstname(param_first_name);
    Contacts[index].set_lastname(param_last_name);
    Contacts[index].set_nickname(param_nickname);
    Contacts[index].set_phonenumber(param_phone_number);
    Contacts[index].set_password(param_password);
    index++;
}   
