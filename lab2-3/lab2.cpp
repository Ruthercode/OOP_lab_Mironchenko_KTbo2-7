
#include <iostream>

#include "interactor.h"
using namespace std;

int main()
{
    Interactor it;
    it.init("clients.txt", "food.txt");
    return 0;
}