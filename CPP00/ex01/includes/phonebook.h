#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "contact.h"

class phonebook
{
    private:
     Contact Contacts[8];
     int     index;
     int     count;
    public:
        phonebook();
        ~phonebook();
        void    set_index(const int& value);
        int     get_index() const;
        int     get_count() const;
        Contact get_contact_at(int index) const;
        void    add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string password);
};

#endif