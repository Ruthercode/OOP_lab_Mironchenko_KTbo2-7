#include <iostream>

using namespace std;

int main()
{
    unsigned char mass[8] = {1,2,3,4,5,6,7,8};
    int res = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (((1<<j) & mass[i])) res++;
        }
    }
    cout << res << endl;
    return 0;
}