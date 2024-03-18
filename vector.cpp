#include <iostream>
#include "funkcijos.h"
#include <algorithm>
#include <ctime>
#include <chrono>
#include <functional>
using namespace std;
using namespace std::chrono;
int main() {
    srand(time(nullptr));
    vector<studentas> students;
    vector<studentas> vargsai;
    vector<studentas> galva;
    vector<double> galrez;
    vector<double> median;
    int kodas;
    int rusis;
    createfile("failas1.txt", 1000);
    studrus(students, galrez, median, vargsai, galva, "failas1.txt");
    createfile("failas2.txt", 10000);
    studrus(students, galrez, median, vargsai, galva, "failas2.txt");
    createfile("failas3.txt", 100000);
    studrus(students, galrez, median, vargsai, galva, "failas3.txt");
    createfile("failas4.txt", 1000000);
    studrus(students, galrez, median, vargsai, galva, "failas4.txt");
    createfile("failas5.txt", 10000000);
    studrus(students, galrez, median, vargsai, galva, "failas5.txt");
    try {
        cout << "Ar norite duomenis generuoti / rasyti ranka - 1" << endl << "Ar norite duomenis skaityti is failo - 2" << endl;
        cin >> kodas;

        if (kodas != 1 && kodas != 2) {
            throw "Neteisingas ivesties pasirinkimas.";
        }

        if (kodas == 1) {
            rasytiranka(students, galrez, median);
        } else if (kodas == 2) {
            skaitymas(students, galrez, median);
            int slap;
            try {
                cout << "Ar duomenis spausdinti ekrane - 1" << endl << "Ar duomenis spausdint faile - 2" << endl;
                cin >> slap;
                if (slap == 1)
                    spausdint(students, galrez, median);
                else if (slap == 2)
                    spausdintfaila(students, galrez, median);
                else
                    throw "Neteisingas pasirinkimas duomenu spausdinimui.";
            } catch (const char* msg) {
                cerr << msg << endl;
                return 1;
            }
        }
    } catch (const char* msg) {
        cerr << "Klaida: " << msg << endl;
    }
    return 0;
}
