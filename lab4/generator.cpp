// #include <iostream>
// #include <vector>
// #include <random>
// #include <time.h>

// using namespace std;

// double fRand(double fMin, double fMax)
// {
//     double f = (double)rand() / RAND_MAX;
//     return fMin + f * (fMax - fMin);
// }

// int main()
// {
//     freopen("test.txt", "w", stdout);
//     string first_names[12] = {"Alexander", "Vladimir", "Inside", 
//                             "Vladislav", "AAAAAA", "Ulia",
//                             "Pagislav", "Sensei", "Pepa",
//                             "Name", "GRUD'", "JIR"};

//     string second_names[12] = {"Griror'evich", "Vladimirovich", "Evgen'evich", 
//                             "Alexandrovich", "AAAAAAAA", "Vladimirovna",
//                             "Anatol'evich", "nol'", "odin",
//                             "SecondName", "GRUD'EVICH", "JIR"};
                            
//     string last_names[12] = {"Lukashenko", "Putin", "Dead", 
//                             "Lyz'", "AAAAAAAAAAAAAA", "Timoshenko",
//                             "Mironchenko", "Tarasov", "Bistrov",
//                             "LastName", "GRUDININ", "JIRINOVSKIY"};
    
//     string jobs[10] = {"Russia", "EdianyaRossiya", "MonitorElectric",
//                        "Belaruc", "ICTIS", "Macdac",
//                        "Google", "Yandex", "CumZone",
//                        "job", };

//     srand(time(NULL));
//     cout << 5000000 << endl;
//     for (int i = 0; i < 5000000; ++i)
//     {
//         cout << last_names[rand() %12] << " " << first_names[rand() %12] << " " << second_names[rand() %12]
//         << " " << 1+(rand()%31) << '.' << 1+(rand()%12) << '.' << 1970+(rand()%51) << ' '
//         << jobs[rand()%10] << ' ' << fRand(0,100) << '\n';
//     }
//     return 0;
// }