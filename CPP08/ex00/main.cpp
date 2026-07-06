#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> nums;

    nums.reserve(5);
    nums.push_back(10);
    nums.push_back(50);
    nums.push_back(30);
    nums.push_back(67);
    nums.push_back(88);
    int res = easyfind(nums, 67);
    std::cout << "result: " << res << "\n";
}