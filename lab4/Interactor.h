#ifndef INTERACTOR_H
#define INTERACTOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include "ICandidateContainer.h"
#include "ContainerFactory.h"

class Interactor
{
public:
    Interactor();
    ~Interactor();
    void Init(const std::string& file_to_input);
private:
    ICandidateContainer* _container;
    void _Help() const;
    void _FileParse(const std::string& file_to_input);
    void _Interaction(const std::string& file_to_input);
    void _ChooseContainer();
};


#endif 