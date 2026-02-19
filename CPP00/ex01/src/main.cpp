#include "phonebook.h"

bool check_if_is_alpha(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
        if(!isalpha(str[i]))
            return false;
    return true;
}

bool check_if_is_num(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
        if(!std::isdigit(str[i]))
            return false;
    return true;
}

void get_contact_information_and_add(phonebook& pb)
{
    std::string temp_first_name;
    std::string temp_last_name;
    std::string temp_nickname;
    std::string temp_phone_number;
    std::string temp_password;
    
    std::cout << "First name:" << std::endl;
    std:: cin >> temp_first_name;
    if (!check_if_is_alpha(temp_first_name))
    {
        std::cout << "Invalid input." << std::endl;
        return ;
    }
    std::cout << "Last name:" << std::endl;
    std:: cin >> temp_last_name;
    if (!check_if_is_alpha(temp_last_name))
    {
        std::cout << "Invalid input." << std::endl;
        return ;
    }
    std::cout << "Nickname:" << std::endl;
    std:: cin >> temp_nickname;
    if (!check_if_is_alpha(temp_nickname))
    {
        std::cout << "Invalid input." << std::endl;
        return ;
    }
    std::cout << "Phone number:" << std::endl;// 
    std:: cin >> temp_phone_number;
    if (!check_if_is_num(temp_phone_number))
    {
        std::cout << "Invalid input." << std::endl;
        return ; 
    }
    std::cout << "Darkest secret:" << std::endl;
    std:: cin >> temp_password;
    
    pb.add_contact(temp_first_name, temp_last_name, temp_nickname, temp_phone_number, temp_password);
}
void display_all_contacts(phonebook& pb)
{
    std::cout << std::right;
    std::cout << "*********************************************" << std::endl;
    std::cout << "*" << std::setw(10) << "INDEX" << "|";
    std::cout << std::setw(10) << "FIRST NAME" << "|";
    std::cout << std::setw(10) << "LAST NAME" << "|";
    std::cout << std::setw(10) << "NICK NAME" << "*" << std::endl;
    std::cout << "*********************************************" << std::endl;
    for (int i = 0; i < pb.get_index(); i++)
    {
		std::string fn = pb.get_contact_at(i).get_firstname();
    	std::string ln = pb.get_contact_at(i).get_lastname();
    	std::string nn = pb.get_contact_at(i).get_nickname();

		std::string new_fn = fn;
		std::string new_ln = ln;
		std::string new_nn = nn;
		if (fn.length() > 10)
		{
			new_fn = fn.substr(0, 10);
			new_fn[9] = '.';
		}
		if (ln.length() > 10)
		{
			new_ln = ln.substr(0, 10);
			new_ln[9] = '.';
		}
		if (nn.length() > 10)
		{
			new_nn = nn.substr(0, 10);
			new_nn[9] = '.';
		}
    	std::cout << "*" << std::setw(10) << i << "|" ;
    	std::cout << std::setw(10) << new_fn << "|" ;
    	std::cout << std::setw(10) << new_ln << "|" ;
    	std::cout << std::setw(10) << new_nn << "*" << std::endl;
    }
    std::cout << "*********************************************" << std::endl;
}
void display_specific_contact(phonebook pb, int index)
{
    std::cout << "First Name: " <<  pb.get_contact_at(index).get_firstname() << std::endl;
    std::cout << "Last Name: " <<  pb.get_contact_at(index).get_lastname() << std::endl;
    std::cout << "Nickname: " <<  pb.get_contact_at(index).get_nickname() << std::endl;
    std::cout << "Phone Number: " <<  pb.get_contact_at(index).get_phonenumber() << std::endl;
    std::cout << "Darkest secret: " <<  pb.get_contact_at(index).get_password() << std::endl;
}
void search(phonebook pb)
{
    int index;

    if (pb.get_index() == 0)
    {
        std::cout << "There are no contacts saved." << std::endl; 
        return ;
    }
    display_all_contacts(pb);
    while (true)
    {
        std::cout << "Choose an Index." << std::endl;
        std::cin >> index;
        if (index < 0 || index > pb.get_index() || !std::cin)
        {
            std::cout << "Invalid input." << std::endl;
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            break ;
        }
        else
        {
            display_specific_contact(pb, index);
            break;
        }
    }
}

int main (void)
{
    phonebook pb;
    std::string user_input;

    while (true)
    {
        std::cout << "Choose one of the folowing commands: ADD, SEARCH or EXIT" << std::endl;
        std::cin >> user_input;
        if (!std::cin) 
            break ;
        else if (user_input == "ADD")
            get_contact_information_and_add(pb);
        else if (user_input == "SEARCH")
            search(pb);
        else if (user_input == "EXIT")
            break;
        else
            std::cout << "Invalid input." << std::endl;
    }    
}