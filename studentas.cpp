    #include "studentas.h"
    #include <iostream>
    #include <fstream>
    #include <algorithm>
    #include <numeric>
    #include <cstdlib>
    #include <ctime>
    #include <iomanip>
    #include <chrono>
    #include <functional>

    using namespace std;
    using namespace std::chrono;

void printStudentState(const Studentas& student, const string& name) {
    cout << name << ":" << endl;
    cout << "  Vardas: " << student.getVardas() << endl;
    cout << "  Pavarde: " << student.getPavarde() << endl;
    cout << "  Egzas: " << student.getEgzas() << endl;
    cout << "  ND: ";
    for (int grade : student.getNd()) {
        cout << grade << " ";
    }
    cout << endl;
}

// Copy assignment operator
Studentas& Studentas::operator=(const Studentas& s) {
    if (this != &s) {
        Zmogus::operator=(s);
        nd = s.nd;
        egzas = s.egzas;
    }
    return *this;
}

// Move assignment operator
Studentas& Studentas::operator=(Studentas&& s) noexcept {
    if (this != &s) {
        Zmogus::operator=(move(s));
        nd = move(s.nd);
        egzas = s.egzas;
        s.egzas = 0;
    }
    return *this;
}

// Copy assignment operator
Zmogus& Zmogus::operator=(const Zmogus& o) {
    if (this != &o) {
        vardas = o.vardas;
        pavarde = o.pavarde;
    }
    return *this;
}

// Move assignment operator
Zmogus& Zmogus::operator=(Zmogus&& z) noexcept {
    if (this != &z) {
        vardas = std::move(z.vardas);
        pavarde = std::move(z.pavarde);
    }
    return *this;
}

void createfile(const string& filename, const int& kiekis) {
    ifstream checkfile(filename);

    // Check if the file is open, indicating that it already exists
    if (checkfile.is_open()) {
        cout << "Failas jau egzistuoja" << endl;
        checkfile.close();
        return;
    }

    // Proceed with file creation if it doesn't exist
    ofstream inf(filename);

    const int ilgis = 20;
    inf << setw(ilgis) << left << "Vardas" << " " << setw(ilgis) << left << "Pavarde" << "     ";
    for (int i = 1; i < 16; i++) {
        inf << setw(10) << left << "ND" + to_string(i);
    }
    inf << setw(10) << left << "Egz." << endl;

    for (int j = 1; j < kiekis + 1; j++) {
        inf << setw(ilgis) << left << "Vardas" + to_string(j) << " " << setw(ilgis) << std::left << "Pavarde" + to_string(j) << "     ";
        for (int i = 0; i < 15; i++) {
            inf << setw(10) << left << rand() % 10 + 1;
        }
        inf << setw(10) << left << rand() % 10 + 1 << std::endl;
    }

    inf.close();
}

bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Function to read an integer from input
int readInt(const string& prompt) {
    string input;
    cout << prompt;
    cin >> input;

    if (!isNumeric(input)) {
        throw invalid_argument("Klaida: Įvestas tekstas, prašome įvesti skaičių.");
    }

    return stoi(input);
}
    bool compareNames(const string& a, const string& b) {
        string numA, numB;
        for (char c : a) {
            if (isdigit(c)) {
                numA += c;
            }
        }

        // Extract numeric part from the names in string 'b'
        for (char c : b) {
            if (isdigit(c)) {
                numB += c; // Append the digit character to numB
            }
        }

        // Convert extracted numeric parts to integers
        int intA = stoi(numA);
        int intB = stoi(numB);

        // Compare the numeric parts
        return intA < intB;
    }
    
void clearFiles() {
    ofstream ofs1("vargsai.txt", ios::trunc);
    ofstream ofs2("galva.txt", ios::trunc);
    ofs1.close();
    ofs2.close();
}
double Studentas::calculateFinalGrade() const {
    double nd_sum = accumulate(nd.begin(), nd.end(), 0);
    double vidurkis = nd_sum / nd.size();
    return 0.4 * vidurkis + 0.6 * egzas;
}

double Studentas::calculateMedian() const {
    vector<int> sorted_nd = nd;
    sort(sorted_nd.begin(), sorted_nd.end());
    int n = sorted_nd.size();
    if (n % 2 == 0) {
        return (sorted_nd[n / 2 - 1] + sorted_nd[n / 2]) / 2.0;
    } else {
        return sorted_nd[n / 2];
    }
}

istream& Studentas::readStudent(istream& is) {
    is >> vardas >> pavarde;
    nd.clear();
    for (int k = 0; k < 15; k++) {
        int nd_val;
        is >> nd_val;
        nd.push_back(nd_val);
    }
    is >> egzas;
    return is;
}

void studrus(vector<Studentas>& students, vector<Studentas>& vargsai, vector<Studentas>& galva, const string& filename, int dydis) {
    clearFiles();
    const int ilgis = 20;
    ifstream inf(filename);
    string firstline;
    getline(inf, firstline);
    Studentas tempstud;
    int rakt;
    double nt = 0, st = 0, wt = 0, nereikt = 0;

    vector<Studentas> visistud;
    int processedCount = 0;

    cout << "Studentus rikiuoti pagal bendra vidurki - 1" << endl << "Studentus rikiuoti pagal mediana - 2" << endl;
    cin >> rakt;

    // Skaitom
    auto start = high_resolution_clock::now();
    while (processedCount < dydis && inf >> tempstud) {
        Studentas newStudent;
        newStudent = tempstud; // copy assignment 
        visistud.push_back(std::move(newStudent)); // move
        processedCount++;
    }
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    nt += diff.count();

    // Sortinam
    auto start100 = high_resolution_clock::now();
    if (rakt == 1) {
        sort(visistud.begin(), visistud.end(), [&](const Studentas& a, const Studentas& b) {
            return a.calculateFinalGrade() < b.calculateFinalGrade();
        });
    } else if (rakt == 2) {
        sort(visistud.begin(), visistud.end(), [&](const Studentas& a, const Studentas& b) {
            return a.calculateMedian() < b.calculateMedian();
        });
    }
    auto end100 = high_resolution_clock::now();
    duration<double> diff100 = end100 - start100;
    nereikt += diff100.count();

    // Skaidom
    auto start1 = high_resolution_clock::now();
    for (const auto& stud : visistud) {
        double finalGrade = stud.calculateFinalGrade();
        double median = stud.calculateMedian();

        if (rakt == 1) {
            if (finalGrade < 5) {
                vargsai.push_back(stud);
            } else {
                galva.push_back(stud);
            }
        } else if (rakt == 2) {
            if (median < 5) {
                vargsai.push_back(stud);
            } else {
                galva.push_back(stud);
            }
        }
    }
    auto end1 = high_resolution_clock::now();
    duration<double> diff1 = end1 - start1;
    st += diff1.count();

    // Rasom
    auto start2 = high_resolution_clock::now();
    ofstream of("vargsai.txt", ios::app);
    ofstream oif("galva.txt", ios::app);
    if (of.is_open() && oif.is_open()) {
        of << fixed << setprecision(2);
        oif << fixed << setprecision(2);
        for (const auto& stud : vargsai) {
            of << setw(ilgis) << left << stud.getPavarde() << " " << setw(ilgis) << left << stud.getVardas() << "       ";
            of << setw(ilgis) << left << stud.calculateFinalGrade() << "      ";
            of << setw(ilgis) << left << stud.calculateMedian() << endl;
        }
        for (const auto& stud : galva) {
            oif << setw(ilgis) << left << stud.getPavarde() << " " << setw(ilgis) << left << stud.getVardas() << "       ";
            oif << setw(ilgis) << left << stud.calculateFinalGrade() << "      ";
            oif << setw(ilgis) << left << stud.calculateMedian() << endl;
        }
        of.close();
        oif.close();
    } else {
        cerr << "Error: Unable to open files for writing" << endl;
    }
    auto end2 = high_resolution_clock::now();
    duration<double> diff2 = end2 - start2;
    wt += diff2.count();

    visistud.clear();
    vargsai.clear();
    galva.clear();
    cout << "Nuskaiyti duomenis uztruko " << nt << " s" << endl;
    cout << "Surusiuoti duomenis uztruko " << nereikt << " s" << endl;
    cout << "Suskirstyti duomenis i 2 grupes uztruko " << st << " s" << endl;

    inf.close();
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void studrus1(vector<Studentas>& students, vector<Studentas>& vargsai, const string& filename, int dydis) {
    clearFiles();
    const int ilgis = 20;
    ifstream inf(filename);
    string firstline;
    getline(inf, firstline);
    Studentas tempstud;
    int rakt;
    double nt = 0, st = 0, wt = 0, nereikt = 0;

    vector<Studentas> visistud;
    int processedCount = 0;

    cout << "Studentus rikiuoti pagal bendra vidurki - 1" << endl << "Studentus rikiuoti pagal mediana - 2" << endl;
    cin >> rakt;

    // Skaitom
    auto start = high_resolution_clock::now();
    while (processedCount < dydis && inf >> tempstud) {
        Studentas newStudent;
        newStudent = tempstud; // copy assignment 
        visistud.push_back(std::move(newStudent)); // move
        processedCount++;
    }
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    nt += diff.count();

    // Sortinam
    auto start100 = high_resolution_clock::now();
    if (rakt == 1) {
        sort(visistud.begin(), visistud.end(), [&](const Studentas& a, const Studentas& b) {
            return a.calculateFinalGrade() < b.calculateFinalGrade();
        });
    } else if (rakt == 2) {
        sort(visistud.begin(), visistud.end(), [&](const Studentas& a, const Studentas& b) {
            return a.calculateMedian() < b.calculateMedian();
        });
    }
    auto end100 = high_resolution_clock::now();
    duration<double> diff100 = end100 - start100;
    nereikt += diff100.count();

    // Skaidymas
    auto start1 = high_resolution_clock::now();
    vector<bool> to_erase(visistud.size(), false);

    for (int i = 0; i < visistud.size(); i++) {
        const auto& stud = visistud[i];
        double finalGrade = stud.calculateFinalGrade();
        double median = stud.calculateMedian();

        if ((rakt == 1 && finalGrade < 5) || (rakt == 2 && median < 5)) {
            vargsai.push_back(stud);
            to_erase[i] = true;
        }
    }
    int write_index = 0;
    for (int i = 0; i < visistud.size(); i++) {
    if (!to_erase[i]) {
        visistud[write_index++] = visistud[i];
        }
    }
    visistud.resize(write_index);
    
    auto end1 = high_resolution_clock::now();
    duration<double> diff1 = end1 - start1;
    st += diff1.count();

    // Rasymas
    auto start2 = high_resolution_clock::now();
    ofstream of("vargsai.txt", ios::app);
    ofstream oif("galva.txt", ios::app);
    if (of.is_open() && oif.is_open()) {
        of << fixed << setprecision(2);
        oif << fixed << setprecision(2);
        for (const auto& stud : vargsai) {
            of << setw(ilgis) << left << stud.getPavarde() << " " << setw(ilgis) << left << stud.getVardas() << "       ";
            of << setw(ilgis) << left << stud.calculateFinalGrade() << "      ";
            of << setw(ilgis) << left << stud.calculateMedian() << endl;
        }
        for (const auto& stud : visistud) {
            oif << setw(ilgis) << left << stud.getPavarde() << " " << setw(ilgis) << left << stud.getVardas() << "       ";
            oif << setw(ilgis) << left << stud.calculateFinalGrade() << "      ";
            oif << setw(ilgis) << left << stud.calculateMedian() << endl;
        }
        of.close();
        oif.close();
    } else {
        cerr << "Error: Unable to open files for writing" << endl;
    }
    auto end2 = high_resolution_clock::now();
    duration<double> diff2 = end2 - start2;
    wt += diff2.count();

    visistud.clear();
    vargsai.clear();
    cout << "Nuskaiyti duomenis uztruko " << nt << " s" << endl;
    cout << "Surusiuoti duomenis uztruko " << nereikt << " s" << endl;
    cout << "Suskirstyti duomenis i 2 grupes uztruko " << st << " s" << endl;

    inf.close();
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void studrus2(vector<Studentas>& students, vector<Studentas>& vargsai, vector<Studentas>& galva, const string& filename, int dydis) {
    clearFiles();
    const int ilgis = 20;
    ifstream inf(filename);
    string firstline;
    getline(inf, firstline);
    Studentas tempstud;
    int rakt;
    double nt = 0, st = 0, wt = 0, nereikt = 0;

    vector<Studentas> visistud;
    int processedCount = 0;

    cout << "Studentus rikiuoti pagal bendra vidurki - 1" << endl << "Studentus rikiuoti pagal mediana - 2" << endl;
    cin >> rakt;

    // Skaitom
    auto start = high_resolution_clock::now();
    while (processedCount < dydis && inf >> tempstud) {
        Studentas newStudent;
        newStudent = tempstud; // copy assignment 
        visistud.push_back(std::move(newStudent)); // move
        processedCount++;
    }
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    nt += diff.count();

    // Sortinam
    auto start100 = high_resolution_clock::now();
    if (rakt == 1) {
        sort(visistud.begin(), visistud.end(), [&](const Studentas& a, const Studentas& b) {
            return a.calculateFinalGrade() < b.calculateFinalGrade();
        });
    } else if (rakt == 2) {
        sort(visistud.begin(), visistud.end(), [&](const Studentas& a, const Studentas& b) {
            return a.calculateMedian() < b.calculateMedian();
        });
    }
    auto end100 = high_resolution_clock::now();
    duration<double> diff100 = end100 - start100;
    nereikt += diff100.count();

    // Skaidom
    auto start1 = high_resolution_clock::now();
    auto partition_point = partition(visistud.begin(), visistud.end(), [&](const Studentas& stud) {
        if (rakt == 1) {
            return stud.calculateFinalGrade() < 5;
        } else if (rakt == 2) {
            return stud.calculateMedian() < 5;
        }
        return false;
    });
    vargsai.assign(visistud.begin(), partition_point);
    galva.assign(partition_point, visistud.end());
    auto end1 = high_resolution_clock::now();
    duration<double> diff1 = end1 - start1;
    st += diff1.count();

    // Rasom
    auto start2 = high_resolution_clock::now();
    ofstream of("vargsai.txt", ios::app);
    ofstream oif("galva.txt", ios::app);
    if (of.is_open() && oif.is_open()) {
        of << fixed << setprecision(2);
        oif << fixed << setprecision(2);

        auto write_student = [&](ofstream& stream, const Studentas& stud) {
            stream << setw(ilgis) << left << stud.getPavarde() << " " << setw(ilgis) << left << stud.getVardas() << "       ";
            stream << setw(ilgis) << left << stud.calculateFinalGrade() << "      ";
            stream << setw(ilgis) << left << stud.calculateMedian() << endl;
        };

        for_each(vargsai.begin(), vargsai.end(), [&](const Studentas& stud) { write_student(of, stud); });
        for_each(galva.begin(), galva.end(), [&](const Studentas& stud) { write_student(oif, stud); });

        of.close();
        oif.close();
    } else {
        cerr << "Error: Unable to open files for writing" << endl;
    }
    auto end2 = high_resolution_clock::now();
    duration<double> diff2 = end2 - start2;
    wt += diff2.count();

    visistud.clear();
    vargsai.clear();
    galva.clear();
    cout << "Nuskaiyti duomenis uztruko " << nt << " s" << endl;
    cout << "Surusiuoti duomenis uztruko " << nereikt << " s" << endl;
    cout << "Suskirstyti duomenis i 2 grupes uztruko " << st << " s" << endl;

    inf.close();
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}
