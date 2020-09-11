#ifndef INTERACTOR_H
#define INTERACTOR_H
#include "matrix.h"
class Interactor
{
    private:
        Matrix* _first;
        Matrix* _second;
    public:
        Interactor();

        void readObjects(std::string);

        std::string interaction(char, int, int);

        friend std::ostream& operator<<(std::ostream& , const Interactor&);

        ~Interactor();
};

#endif 