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

        void readObjects(const std::string& file);

        std::string iteration(const char& command, const int&  target);

        void help();
        void init(const std::string& matrices);

        ~Interactor();
};

#endif 