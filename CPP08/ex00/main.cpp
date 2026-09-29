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

    std::cout << "result: " << easyfind(nums, 67) << "\n";

    std::cout <<" ======== INVALID VECTOR ========= \n";

    std::cout << "result: " << easyfind(nums, 100) << "\n";

    std::list<int> list_nums;

    list_nums.push_back(10);
    list_nums.push_back(50);
    list_nums.push_back(30);
    list_nums.push_back(67);
    list_nums.push_back(88);

    std::cout <<" ======== VALID LIST =========== \n";
    std::cout << "result: " << easyfind(list_nums, 10) << "\n";

    std::cout <<" ======== INVALID LIST ========= \n";
    std::cout << "result: " << easyfind(list_nums, 100) << "\n";

    std::set<int> set_nums;

    set_nums.insert(10);
    set_nums.insert(50);
    set_nums.insert(30);
    set_nums.insert(67);
    set_nums.insert(88);

    std::cout <<" ======== VALID SET =========== \n";
    std::cout << "result: " << easyfind(set_nums, 50) << "\n";

    std::cout <<" ======== INVALID SET ========= \n";
    std::cout << "result: " << easyfind(set_nums, 100) << "\n";

}