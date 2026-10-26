#include "Array.hpp"
#include <iostream>
#include <stdlib.h>


#include "Array.hpp"
#include <iostream>
#include <string>
#include <exception>

int tests_run = 0;
int tests_failed = 0;

void check(bool condition, const std::string &description)
{
    tests_run++;

    if (condition)
        std::cout << "[PASS] " << description << std::endl;
    else
    {
        tests_failed++;
        std::cout << "[FAIL] " << description << std::endl;
    }
}

int main()
{
    std::cout << "\n========== DEFAULT CONSTRUCTION ==========\n";

    Array<int> empty;

    check(empty.size() == 0,
        "Default constructor creates an empty array");


    std::cout << "\n========== SIZE CONSTRUCTION ==========\n";

    Array<int> numbers(5);

    check(numbers.size() == 5,
        "Constructor creates an array of the requested size");

    check(numbers[0] == 0,
        "First int element is value-initialized");

    check(numbers[4] == 0,
        "Last int element is value-initialized");


    std::cout << "\n========== ZERO-SIZED ARRAY ==========\n";

    Array<int> zero(0);

    check(zero.size() == 0,
        "Zero-sized array has size zero");

    bool zero_threw = false;

    try
    {
        zero[0] = 42;
    }
    catch (const std::exception &e)
    {
        zero_threw = true;
        std::cout << "Caught: " << e.what() << std::endl;
    }

    check(zero_threw,
        "Indexing a zero-sized array throws an exception");


    std::cout << "\n========== READ AND WRITE ==========\n";

    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    check(numbers[0] == 10 && numbers[4] == 50,
        "Elements can be written and read");

    check(numbers.size() == 5,
        "Writing elements does not change the size");


    std::cout << "\n========== COPY CONSTRUCTOR ==========\n";

    Array<int> original(3);
    original[0] = 10;
    original[1] = 20;
    original[2] = 30;

    Array<int> copied(original);

    check(copied.size() == original.size(),
        "Copy constructor preserves the size");

    check(copied[0] == 10 && copied[1] == 20
        && copied[2] == 30,
        "Copy constructor preserves the values");

    copied[0] = 99;

    check(original[0] == 10 && copied[0] == 99,
        "Copy constructor creates an independent copy");


    std::cout << "\n========== ASSIGNMENT OPERATOR ==========\n";

    Array<int> source(3);
    source[0] = 100;
    source[1] = 200;
    source[2] = 300;

    Array<int> destination(1);
    destination[0] = -1;

    destination = source;

    check(destination.size() == 3,
        "Assignment updates the destination size");

    check(destination[0] == 100 && destination[1] == 200
        && destination[2] == 300,
        "Assignment copies all values");

    destination[0] = 999;

    check(source[0] == 100 && destination[0] == 999,
        "Assignment creates an independent copy");


    std::cout << "\n========== ASSIGNMENT BETWEEN DIFFERENT SIZES ==========\n";

    Array<int> small(1);
    small[0] = 7;

    Array<int> large(4);
    large[0] = 1;
    large[1] = 2;
    large[2] = 3;
    large[3] = 4;

    small = large;

    check(small.size() == 4,
        "Assignment from a larger array updates the size");

    check(small[0] == 1 && small[3] == 4,
        "Assignment from a larger array copies every value");

    Array<int> smaller(1);
    smaller[0] = 42;

    large = smaller;

    check(large.size() == 1 && large[0] == 42,
        "Assignment from a smaller array updates the size");


    std::cout << "\n========== SELF-ASSIGNMENT ==========\n";

    Array<int> self(3);
    self[0] = 11;
    self[1] = 22;
    self[2] = 33;

    self = self;

    check(self.size() == 3,
        "Self-assignment preserves the size");

    check(self[0] == 11 && self[1] == 22 && self[2] == 33,
        "Self-assignment preserves all values");


    std::cout << "\n========== CONST ACCESS ==========\n";

    const Array<int> const_array(original);

    check(const_array[0] == 10,
        "Const array supports read access");

    check(const_array.size() == 3,
        "size() works on a const array");

    bool const_threw = false;

    try
    {
        (void)const_array[3];
    }
    catch (const std::exception &e)
    {
        const_threw = true;
        std::cout << "Caught: " << e.what() << std::endl;
    }

    check(const_threw,
        "Out-of-bounds const access throws an exception");


    std::cout << "\n========== OUT-OF-BOUNDS ACCESS ==========\n";

    bool negative_threw = false;

    try
    {
        numbers[-1] = 42;
    }
    catch (const std::exception &e)
    {
        negative_threw = true;
        std::cout << "Caught: " << e.what() << std::endl;
    }

    check(negative_threw,
        "Negative index throws an exception");

    bool upper_threw = false;

    try
    {
        numbers[5] = 42;
    }
    catch (const std::exception &e)
    {
        upper_threw = true;
        std::cout << "Caught: " << e.what() << std::endl;
    }

    check(upper_threw,
        "Index equal to size throws an exception");


    std::cout << "\n========== STRING ARRAY ==========\n";

    Array<std::string> words(2);
    words[0] = "hello";
    words[1] = "world";

    check(words[0] == "hello" && words[1] == "world",
        "Array works with std::string");

    Array<std::string> words_copy(words);
    words_copy[0] = "changed";

    check(words[0] == "hello" && words_copy[0] == "changed",
        "String arrays also copy independently");


    std::cout << "\n========== FINAL RESULTS ==========\n";

    std::cout << "Tests run: " << tests_run << std::endl;
    std::cout << "Tests failed: " << tests_failed << std::endl;

    if (tests_failed == 0)
        std::cout << "All tests passed!" << std::endl;
    else
        std::cout << "Some tests failed!" << std::endl;

    return (tests_failed == 0 ? 0 : 1);
}
