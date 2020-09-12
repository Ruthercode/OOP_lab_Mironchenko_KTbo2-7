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

        void readObjects(std::string file);

        std::string iteration(char command, int target);

        void help();
        void init(std::string matrices);

        ~Interactor();
};

#endif 