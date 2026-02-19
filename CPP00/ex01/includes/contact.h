#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <cctype>
#include <iomanip>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string password;
    public:
        Contact();
        ~Contact();
        std::string get_firstname() const;
        std::string get_lastname() const;
        std::string get_nickname() const;
        std::string get_phonenumber() const;
        std::string get_password() const;
        void        set_firstname(const std::string &value);
        void        set_lastname(const std::string &value);
        void        set_nickname(const std::string &value);
        void        set_phonenumber(const std::string &value);
        void        set_password(const std::string &value);
};

#endif