    #include "funkcijosDeque.h"
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
        inf << setw(ilgis) << left << "Vardas" + to_string(j) << " " << setw(ilgis) << left << "Pavarde" + to_string(j) << "     ";
        for (int i = 0; i < 15; i++) {
            inf << setw(10) << left << rand() % 10 + 1;
        }
        inf << setw(10) << left << rand() % 10 + 1 << endl;
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
        return intA > intB;
    }
void clearFiles() {
    ofstream of("vargsai.txt", ios::trunc);
    of.close();
    ofstream oif("galva.txt", ios::trunc);
    oif.close();
}

double calculateFinalGrade(const studentas& s) {
    double nd_sum = accumulate(s.nd.begin(), s.nd.end(), 0);
    double vidurkis = nd_sum / s.nd.size();
    return 0.4 * vidurkis + 0.6 * s.egzas;
}

double calculateMedian(const studentas& s) {
    deque<int> sorted_nd = s.nd;
    sort(sorted_nd.begin(), sorted_nd.end());
    int n = sorted_nd.size();
    if (n % 2 == 0) {
        return (sorted_nd[n / 2 - 1] + sorted_nd[n / 2]) / 2.0;
    } else {
        return sorted_nd[n / 2];
    }
}

void studrus(deque<studentas>& students, deque<studentas>& vargsai, deque<studentas>& galva, const string& filename, int dydis) {
    clearFiles();
    const int ilgis = 20;
    ifstream inf(filename);
    string firstline;
    getline(inf, firstline);
    studentas tempstud;
    int rakt;
    double nt = 0, st = 0, wt = 0, nereikt = 0;

    deque<studentas> visistud;
    int processedCount = 0;

    cout << "Studentus rikiuoti pagal bendra vidurki - 1" << endl << "Studentus rikiuoti pagal mediana - 2" << endl;
    cin >> rakt;

    // Skaitymas
    auto start = high_resolution_clock::now();
    while (processedCount < dydis && inf >> tempstud.vardas >> tempstud.pavarde) {
        tempstud.nd.clear();
        for (int k = 0; k < 15; k++) {
            int nd_val;
            inf >> nd_val;
            tempstud.nd.push_back(nd_val);
        }
        inf >> tempstud.egzas;
        visistud.push_back(tempstud);
        processedCount++;
    }
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    nt += diff.count();

    // Sortinam
    auto start100 = high_resolution_clock::now();
    if (rakt == 1) {
        sort(visistud.begin(), visistud.end(), [&](const studentas& a, const studentas& b) {
            return calculateFinalGrade(a) < calculateFinalGrade(b);
        });
    } else if (rakt == 2) {
        sort(visistud.begin(), visistud.end(), [&](const studentas& a, const studentas& b) {
            return calculateMedian(a) < calculateMedian(b);
        });
    }
    auto end100 = high_resolution_clock::now();
    duration<double> diff100 = end100 - start100;
    nereikt += diff100.count();

    // Skirstymas duomenu
    auto start1 = high_resolution_clock::now();
    auto it = visistud.begin();
    while (it != visistud.end()) {
        const auto& stud = *it;
        double finalGrade = calculateFinalGrade(stud);
        double median = calculateMedian(stud);

        if (rakt == 1) {
            if (finalGrade < 5) {
                vargsai.push_back(stud);
            } else {
                galva.push_back(stud);
            }
            it++;
        } else if (rakt == 2) {
            if (median < 5) {
                vargsai.push_back(stud);
            } else {
                galva.push_back(stud);
            }
            it++;
        }
    }
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
            of << setw(ilgis) << left << stud.pavarde << " " << setw(ilgis) << left << stud.vardas << "       ";
            of << setw(ilgis) << left << calculateFinalGrade(stud) << "      ";
            of << setw(ilgis) << left << calculateMedian(stud) << endl;
        }
        for (const auto& stud : galva) {
            oif << setw(ilgis) << left << stud.pavarde << " " << setw(ilgis) << left << stud.vardas << "       ";
            oif << setw(ilgis) << left << calculateFinalGrade(stud) << "      ";
            oif << setw(ilgis) << left << calculateMedian(stud) << endl;
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
    cin.get();    // Wait for user to press Enter
}

    /*void skaityti(vector<studentas>& students, vector<double>& galrez, vector<double>& median) {
    int failas;
    bool fileSelected = false;
    while (!fileSelected) {
        try {
            cout << "Is kurio failo skaityti duomenis?" << endl
                 << "10k duomenu - 1" << endl
                 << "100k duomenu - 2" << endl
                 << "1mil duomenu - 3" << endl;
            cin >> failas;

            ifstream inf;
            if (failas == 1)
                inf.open("kursiokai1.txt");
            else if (failas == 2)
                inf.open("kursiokai2.txt");
            else if (failas == 3)
                inf.open("kursiokai3.txt");
            else {
                throw "Neteisingas failo pasirinkimas.";
            }

            if (!inf.is_open()) {
                throw "Failo atidaryti nepavyko!";
            }
            fileSelected = true;

            string firstline;
            getline(inf, firstline);

            studentas tempstud;
            while (inf >> tempstud.vardas >> tempstud.pavarde) {
                tempstud.nd.clear();
                int num_grades;
                if (failas == 1)
                    num_grades = 15;
                else if (failas == 2)
                    num_grades = 20;
                else if (failas == 3)
                    num_grades = 7;

                tempstud.nd.resize(num_grades);
                for (int j = 0; j < num_grades; j++) {
                    inf >> tempstud.nd[j];
                }

                inf >> tempstud.egzas;
                sort(tempstud.nd.begin(), tempstud.nd.end());
                double median_value;
                int n = tempstud.nd.size();
                if (n % 2 == 0) {
                    median_value = (tempstud.nd[n / 2 - 1] + tempstud.nd[n / 2]) / 2.0;
                } else {
                    median_value = tempstud.nd[n / 2];
                }
                double nd_sum = accumulate(tempstud.nd.begin(), tempstud.nd.end(), 0.0);
                double vidurkis = nd_sum / n;
                double galutinis = 0.4 * vidurkis + 0.6 * tempstud.egzas;
                median.push_back(median_value);
                galrez.push_back(galutinis);
                students.push_back(tempstud);
            }

            inf.close();
        } catch (const char* msg) {
            cerr << msg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
    void spausdint(const vector<studentas>& students, const vector<double>& galrez, const vector<double>& median) {
        const int ilgis = 20;
        cout << setw(ilgis) << left << "Pavarde" << " " << setw(ilgis) << left << "Vardas" << "     " << setw(ilgis) << left << "Galutinis (Vid. ) / Galutinis (Med. )" << endl;
        cout << "..................................................................." << endl;
        cout << fixed << setprecision(2);

        for (size_t j = 0; j < students.size(); j++) {
            cout << setw(ilgis) << left << students[j].pavarde << " " << setw(ilgis) << left << students[j].vardas << "       " << setw(ilgis) << left << galrez[j] << "      " << setw(ilgis) << left << median[j] << endl;
        }
    }
    void spausdintfaila(const vector<studentas>& students, const vector<double>& galrez, const vector<double>& median) {
        ofstream outf("outputas.txt");

        const int ilgis = 20;
        outf << setw(ilgis) << left << "Pavarde" << " " << setw(ilgis) << left << "Vardas" << "     " << setw(ilgis) << left << "Galutinis (Vid. ) / Galutinis (Med. )" << endl;
        outf << "..................................................................." << endl;
        outf << fixed << setprecision(2);

        for (size_t j = 0; j < students.size(); j++) {
            outf << setw(ilgis) << left << students[j].pavarde << " " << setw(ilgis) << left << students[j].vardas << "       " << setw(ilgis) << left << galrez[j] << "      " << setw(ilgis) << left << median[j] << endl;
        }

        outf.close();
    }

    void rasytiranka(vector<studentas>& students, vector<double>& galrez, vector<double>& median) {
    int pas;
    bool reiksme1 = false;
    
    do {
        try {
            cout << "Viska rasyti ranka - 1" << endl << "Generuoti tik pazymius - 2" << endl << "Generuoti ir pazymius ir studentu vardus, pavardes - 3" << endl << "Baigti darba - 4" << endl;
            cin >> pas;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Netinkamas ivesties pasirinkimas";
            }
            if (pas == 1 || pas == 2 || pas == 3 || pas == 4) {
                studentas temp_student;
                reiksme1 = true;
                if (pas == 3) {
                    temp_student.vardas = randname();
                    temp_student.pavarde = randname();
                } else if (pas == 1 || pas == 2) {
                    cout << "Iveskite studento varda: ";
                    cin >> temp_student.vardas;

                    cout << "Iveskite studento pavarde: ";
                    cin >> temp_student.pavarde;
                }

                if (pas != 4) {
                    bool reiksme2 = false;
                    while (!reiksme2) {
                        try {
                            int n;
                            cout << "Iveskite studento pazymiu kieki: ";
                            cin >> n;
                            if (cin.fail() || n <= 0) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                throw "Netinkamas ivesties pasirinkimas";
                            }
                            reiksme2 = true;
                            temp_student.nd.resize(n);

                            int ndvid = 0;
                            for (int i = 0; i < n; i++) {
                                bool reiksme3 = false;
                                while (!reiksme3) {
                                    try {
                                        if (pas == 2 || pas == 3)
                                            temp_student.nd[i] = rand() % 10 + 1;
                                        else {
                                            cout << "Iveskite pazymi: ";
                                            cin >> temp_student.nd[i];
                                            if (cin.fail() || temp_student.nd[i] < 0 || temp_student.nd[i] > 10) {
                                                cin.clear();
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                throw "Netinkamas ivesties pasirinkimas";
                                            }
                                        }
                                        reiksme3 = true;
                                    } catch (const char* msg) {
                                        cerr << msg << endl;
                                    }
                                }
                                ndvid += temp_student.nd[i];
                            }
                            sort(temp_student.nd.begin(), temp_student.nd.end());
                            if (n % 2 == 0) {
                                median.push_back((temp_student.nd[n / 2 - 1] + temp_student.nd[n / 2]) / 2.0);
                            } else {
                                median.push_back(temp_student.nd[n / 2]);
                            }

                            double vidurkis = (double)ndvid / n;

                            bool reiksme4 = false;
                            while (!reiksme4) {
                                try {
                                    cout << "Iveskite egzamino rezultata: ";
                                    cin >> temp_student.egzas;
                                    if (cin.fail() || temp_student.egzas < 0 || temp_student.egzas > 10) {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        throw "Netinkamas ivesties pasirinkimas";
                                    }
                                    reiksme4 = true;
                                } catch (const char* msg) {
                                    cerr << msg << endl;
                                }
                            }

                            galrez.push_back(0.4 * vidurkis + 0.6 * temp_student.egzas);
                            students.push_back(temp_student);
                        } catch (const char* msg) {
                            cerr << msg << endl;
                        }
                    }
                }
            } else {
                throw "Neteisingas duomenu ivedimo pasirinkimas";
            }
        } catch (const char* msg) {
            cerr << msg << endl;
            reiksme1 = false;
        }
    } while (pas != 4);
    spausdint(students, galrez, median);
}
 int partition(vector<studentas>& students, vector<double>& galrez, vector<double>& median, int low, int high, int rusis) {
    double pivot;
    if (rusis == 1 || rusis == 2) {
        pivot = (rusis == 1) ? students[high].vardas.compare(students[high].vardas) : students[high].pavarde.compare(students[high].pavarde);
    } else if (rusis == 3) {
        pivot = galrez[high];
    } else if (rusis == 4) {
        pivot = median[high];
    }

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        double compare;
        if (rusis == 1 || rusis == 2) {
            compare = (rusis == 1) ? students[j].vardas.compare(students[j].vardas) : students[j].pavarde.compare(students[j].pavarde);
        } else if (rusis == 3) {
            compare = galrez[j];
        } else if (rusis == 4) {
            compare = median[j];
        }

        if (compare <= pivot) {
            i++;
            swap(students[i], students[j]);
            swap(galrez[i], galrez[j]);
            swap(median[i], median[j]);
        }
    }
    swap(students[i + 1], students[high]);
    swap(galrez[i + 1], galrez[high]);
    swap(median[i + 1], median[high]);
    return i + 1;
}
void quickSort(vector<studentas>& students, vector<double>& galrez, vector<double>& median, int low, int high, int rusis) {
    if (low < high) {
        int pi = partition(students, galrez, median, low, high, rusis);

        quickSort(students, galrez, median, low, pi - 1, rusis);
        quickSort(students, galrez, median, pi + 1, high, rusis);
    }
}
    void skaitymas(vector<studentas>& students, vector<double>& galrez, vector<double>& median) {
    int rusis;
    bool nominalas = false;
    try {
        skaityti(students, galrez, median);
    } catch (const char* msg) {
        cerr << msg << endl;
        exit(1);
    }

    while (!nominalas) {
        try {
            cout << "Kaip norite kad butu surusiuoti duomenis?" << endl
                 << "Pagal varda - 1" << endl
                 << "Pagal pavarde - 2" << endl
                 << "Galutini pazymiu vidurki - 3" << endl
                 << "Galutini pagal mediana - 4" << endl;
            cin >> rusis;
            if (rusis >= 1 && rusis <= 4) {
                quickSort(students, galrez, median, 0, students.size() - 1, rusis);
                nominalas = true;
            } else {
                throw "Neteisingas rusiavimo pasirinkimas";
            }
        } catch (const char* msg) {
            cerr << msg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

    string randname() {
        string randomString;
        int length = rand() % 20 + 1; // Random length between 1 and 20 characters
        for (int i = 0; i < length; ++i) {
            randomString += 'a' + rand() % 26; // Random lowercase letter between 'a' and 'z'
        }
        return randomString;
    }
*/