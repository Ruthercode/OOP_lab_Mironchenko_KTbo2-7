#include <iostream>
#include "interactor.h"
using namespace std;


int main()
{
    Interactor it;
    it.readOblects("input.txt");
    
    freopen("commands.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char ch;
        int tar;
        cin >> ch >> tar;
        cout << it.interaction(ch, tar, i+1) << endl;
    }
    
    cout << it << endl;
    return 0;
}