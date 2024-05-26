#include <iostream>
#include "funkcijosVector.h"
#include <algorithm>
#include <ctime>
#include <chrono>
#include <functional>
using namespace std;
using namespace std::chrono;
int main() {
    srand(time(nullptr));
    auto startg = high_resolution_clock::now();
    vector<studentas> students;
    vector<studentas> vargsai;
    vector<studentas> galva;
    vector<double> galrez;
    vector<double> median;
    int kodas;
    int rusis;
    int par;
    auto start = high_resolution_clock::now();
    createfile("failas1.txt", 1000);
    auto end = high_resolution_clock::now();
    duration<double> diff = end-start;
    cout << "Sukurti 1000 elementu faila uztruko " << diff.count() << " s" << endl;
    cout << "Kokia studentu rusiavimo strategija naudot: " << endl;
    cout << "1 strategija - spausti 1 " << endl;
    cout << "2 strategija - spausti 2 " << endl;
    cout << "3 strategija - spausti 3 " << endl;
    cin >> par;
    if(par == 1)
    studrus(students, vargsai, galva, "failas1.txt",1000);
    else if(par == 2)
    studrus1(students, vargsai, "failas1.txt",1000);
    else if(par == 3)
    studrus2(students, vargsai, galva, "failas1.txt",1000);
    auto start1 = high_resolution_clock::now();
    createfile("failas2.txt", 10000);
    auto end1 = high_resolution_clock::now();
    duration<double> diff1 = end1-start1;
    cout << "Sukurti 10000 elementu faila uztruko " << diff1.count() << " s" << endl;
    cout << "Kokia studentu rusiavimo strategija naudot: " << endl;
    cout << "1 strategija - spausti 1 " << endl;
    cout << "2 strategija - spausti 2 " << endl;
    cout << "3 strategija - spausti 3 " << endl;
    cin >> par;
    if(par == 1)
    studrus(students, vargsai, galva, "failas2.txt",10000);
    else if(par == 2)
    studrus1(students, vargsai, "failas2.txt",10000);
    else if(par == 3)
    studrus2(students, vargsai, galva, "failas2.txt",10000);
    auto start2 = high_resolution_clock::now();
    createfile("failas3.txt", 100000);
    auto end2 = high_resolution_clock::now();
    duration<double> diff2 = end2-start2;
    cout << "Sukurti 100000 elementu faila uztruko " << diff2.count() << " s" << endl;
    cout << "Kokia studentu rusiavimo strategija naudot: " << endl;
    cout << "1 strategija - spausti 1 " << endl;
    cout << "2 strategija - spausti 2 " << endl;
    cout << "3 strategija - spausti 3 " << endl;
    cin >> par;
    if(par == 1)
    studrus(students, vargsai, galva, "failas3.txt",100000);
    else if(par == 2)
    studrus1(students, vargsai, "failas3.txt",100000);
    else if(par == 3)
    studrus2(students, vargsai, galva, "failas3.txt",100000);
    auto start3 = high_resolution_clock::now();
    createfile("failas4.txt", 1000000);
    auto end3 = high_resolution_clock::now();
    duration<double> diff3 = end3-start3;
    cout << "Sukurti 1000000 elementu faila uztruko " << diff3.count() << " s" << endl;
    cout << "Kokia studentu rusiavimo strategija naudot: " << endl;
    cout << "1 strategija - spausti 1 " << endl;
    cout << "2 strategija - spausti 2 " << endl;
    cout << "3 strategija - spausti 3 " << endl;
    cin >> par;
    if(par == 1)
    studrus(students, vargsai, galva, "failas4.txt",1000000);
    else if(par == 2)
    studrus1(students, vargsai, "failas4.txt",1000000);
    else if(par == 3)
    studrus2(students, vargsai, galva, "failas4.txt",1000000);
     bool correctInput = false;

    /*while (!correctInput) {
        try {
            cout << "Ar norite duomenis generuoti / rasyti ranka - 1" << endl << "Ar norite duomenis skaityti is failo - 2" << endl;
            cin >> kodas;

            if (kodas != 1 && kodas != 2) {
                throw "Neteisingas ivesties pasirinkimas.";
            }
            correctInput = true;

            if (kodas == 1) {
                rasytiranka(students, galrez, median);
            } else if (kodas == 2) {
                skaitymas(students, galrez, median);
                int slap;
                bool correctPrintInput = false;

                while (!correctPrintInput) {
                    try {
                        cout << "Ar duomenis spausdinti ekrane - 1" << endl << "Ar duomenis spausdint faile - 2" << endl;
                        cin >> slap;

                        if (slap == 1 || slap == 2) {
                            correctPrintInput = true;
                            if (slap == 1)
                                spausdint(students, galrez, median);
                            else if (slap == 2)
                                spausdintfaila(students, galrez, median);
                        } else {
                            throw "Neteisingas pasirinkimas duomenu spausdinimui.";
                        }
                    } catch (const char* msg) {
                        cerr << msg << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            }
        } catch (const char* msg) {
            cerr << "Klaida: " << msg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    */auto endg = high_resolution_clock::now();
    duration<double> diffg = endg-startg;
    cout << "Visas kodas uztruko " << diffg.count() << " s" << endl;
    return 0;
}
