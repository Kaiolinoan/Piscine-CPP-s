#include "contact.h"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::get_firstname() const
{
    return (first_name);
}
std::string Contact::get_lastname() const
{
    return (last_name);
}
std::string Contact::get_nickname() const
{
    return (nickname);
}
std::string Contact::get_phonenumber() const
{
    return (phone_number);
}
std::string Contact::get_password() const
{
    return (password);
}

void Contact::set_firstname(const std::string &value)
{
    first_name = value;
    return ;
}
void Contact::set_lastname(const std::string &value)
{
    last_name = value;
    return ;
}
void Contact::set_nickname(const std::string &value)
{
    nickname = value;
    return ;
}
void Contact::set_phonenumber(const std::string &value)
{
    phone_number = value;
    return ;
}
void Contact::set_password(const std::string &value)
{
    password = value;
    return ;
}
