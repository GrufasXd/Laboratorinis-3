#include <iostream>
#include "studentas.h"
#include <algorithm>
#include <ctime>
#include <chrono>
#include <functional>
using namespace std;
using namespace std::chrono;
int main() {
    srand(time(nullptr));
    //auto startg = high_resolution_clock::now();
    Vector<Studentas> students;
    Vector<Studentas> vargsai;
    Vector<Studentas> galva;
    Vector<double> galrez;
    Vector<double> median;
    int kodas;
    int rusis;
    int par;
    // Demonstruojami "Rule of five" operatoriai
    // Inicializuojam studentas1

    Vector<int> v = {8, 4, 5, 9};
    v.push_back(6);
    v.push_back(9);
    v[2] = -1;
    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';
    cout << "Dydis " << v.size() << endl;
    v.clear();
    cout << "Dydis " << v.size() << endl;

    int b = 0;
    auto start7 = high_resolution_clock::now();
    int sz = 100000000;
    std::vector<int> v1;
    for (int i = 1; i <= sz; i++){
    v1.push_back(i);
    if (v1.capacity() == v1.size())
    b++;
    }
    auto end7 = high_resolution_clock::now();
    duration<double> diff7 = end7-start7;
    cout << "std::vector uztruko " << diff7.count() << " s" << "uzpildyti " << sz << " konteineri " << endl;
    cout << "std::vector klase padare " << b << " atminties perskirstymu" << endl;

    int c = 0;
    auto start8 = high_resolution_clock::now();
    Vector<int> v2;
    for (int i = 1; i <= sz; i++){
    v2.push_back(i);
    if (v2.capacity() == v2.size())
    c++;
    }
    auto end8 = high_resolution_clock::now();
    duration<double> diff8 = end8-start8;
    cout << "Mano Vector klase uztruko " << diff8.count() << " s" << "uzpildyti " << sz << " konteineri " << endl;
    cout << "Mano Vector klase padare " << c << " atminties perskirstymu" << endl;
    Studentas student1(10); 
    student1.setVardas("Jonas");
    student1.setPavarde("Jonaitis");
    student1.addNd(9);
    student1.addNd(8);
    student1.addNd(10);

    // Spausdinam studentas1
    printStudentState(student1, "studentas1");

    // Naudojam copy constructor
    Studentas student2 = student1;
    printStudentState(student2, "studentas2 (po kopijavimo is studentas1, studentas2 pries tai neegzistavo)");

    // Pakeiciam studentas2 informacija ir ziurim ar pasikeis nuo to studentas1 informacija
    student2.setEgzas(20);
    student2.setVardas("Petras");
    printStudentState(student1, "studentas1 (po studentas2 egzamino ir vardo pakeitimo)");
    printStudentState(student2, "studentas2 (po egzamino ir vardo pakeitimo)");

    // Naudojam move constructor
    Studentas student3 = move(student1);
    printStudentState(student3, "studentas3 (po move is studentas1, studentas3 pries tai neegzistuoja)");
    printStudentState(student1, "studentas1 (po move operacijos)");

    // Inicializuojam nauja studenta copy assignment operator panaudojimui
    Studentas student4(20);
    student4.setVardas("Antanas");
    student4.setPavarde("Antanaitis");
    student4.addNd(7);
    student4.addNd(6);

    printStudentState(student4, "studentas4 (pries copy assignment)");

    // Naudojam copy assignment operator
    student4 = student2;
    printStudentState(student4, "studentas4 (po copy assignment is studentas2)");

    // Naujas studentas move assignment operator panaudojimui
    Studentas student5(30);
    student5.setVardas("Kazys");
    student5.setPavarde("Kazlauskas");
    student5.addNd(10);
    student5.addNd(10);

    printStudentState(student5, "studentas5 (pries move assignment)");

    //Naudojam move assignment operator
    student5 = move(student2);
    printStudentState(student5, "studentas5 (po move assignment is studentas2)");
    printStudentState(student2, "studentas2 (po move assignment)");

    student1.~Studentas();
    student2.~Studentas();
    student3.~Studentas();
    student4.~Studentas();
    student5.~Studentas();
    
    /*auto start = high_resolution_clock::now();
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
    */auto start2 = high_resolution_clock::now();
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
    auto startg = high_resolution_clock::now();
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
