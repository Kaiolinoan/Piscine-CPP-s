#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    void setIdea(size_t index, std::string content);
    std::string getIdeaAt(size_t index) const;
    ~Brain();
};


#endif