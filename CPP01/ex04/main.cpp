#include <iostream>
#include <fstream>
#include <string>

void ft_replace(std::string filename, std::string str1, std::string str2)
{
    std::string     outfileName = filename + ".replace";
    std::string     buffer;
    std::ofstream   outfile;
    std::ifstream   infile;

    if (filename.empty() || str1.empty() || str2.empty())
        return;

    infile.open(filename.c_str());
    if (infile.fail()) 
    {
        std::cout << "Error opening infile.\n";
        return ;
    }
    outfile.open(outfileName.c_str());
    if (outfile.fail())
    {
        std::cout << "Error opening outfile.\n";
        return ;
    } 
    while(std::getline(infile, buffer))
    {
        for(size_t i = 0; buffer[i]; i++)
        {
            if (buffer.compare(i, str1.length(), str1) == 0)
            {
                buffer.erase(i, str1.length());
                buffer.insert(i, str2);
            }
        }
        outfile << buffer << "\n";
    }

    infile.close();
    outfile.close();
}

int main (int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Inputs must be in the following format: Filename, String to be replaced, String to replace. \n";
        return (1);
    }
    ft_replace(argv[1], argv[2], argv[3]);
}