#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>

int main()
{
    std::cout <<" ======== VALID VECTOR =========== \n";
    std::vector<int> nums;
    
    nums.reserve(5);
    nums.push_back(10);
    nums.push_back(50);
    nums.push_back(30);
    nums.push_back(67);
    nums.push_back(88);
    std::vector<int>::iterator it = easyfind(nums, 67);
    std::cout << "result: " << *it << "\n";
    try 
    {
        std::cout <<" ======== INVALID VECTOR ========= \n";
        it = easyfind(nums, 100);
        std::cout << "result: " << *it << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::list<int> list_nums;
    list_nums.push_back(10);
    list_nums.push_back(50);
    list_nums.push_back(30);
    list_nums.push_back(67);
    list_nums.push_back(88);
    
    std::list<int>::iterator list_it = easyfind(list_nums, 10);
    std::cout <<" ======== VALID LIST =========== \n";
    std::cout << "result: " << *list_it << "\n";
    try 
    {
        list_it = easyfind(list_nums, 100);
        
        std::cout <<" ======== INVALID LIST ========= \n";
        std::cout << "result: " << *list_it << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::set<int> set_nums;
    set_nums.insert(10);
    set_nums.insert(50);
    set_nums.insert(30);
    set_nums.insert(67);
    set_nums.insert(88);
    std::set<int>::iterator set_it = easyfind(set_nums, 50);
    std::cout <<" ======== VALID SET =========== \n";
    std::cout << "result: " << *set_it << "\n";
    try
    {
        std::cout <<" ======== INVALID SET ========= \n";
        set_it = easyfind(set_nums, 100);
        std::cout << "result: " << *set_it << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}