#include <iostream>

int main(int argc, char **argv)
{
    std::string text;
    std::string final;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
        return 1;
    }

    for(int i = 1; i < argc; i++)
    {
        text = argv[i];
        for (long unsigned int j = 0; j < text.length(); j++)
            final += std::toupper(text[j]);
        std::cout << final;
        final.clear();
    }
}