    #include "funkcijos.h"
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
    ofstream inf(filename);

    const int ilgis = 20;
    inf << setw(ilgis) << left << "Vardas" << " " << setw(ilgis) << left << "Pavarde" << "     ";
    for (int i = 1; i < 16; i++) {
        inf << setw(10) << left << "ND" + to_string(i);
    }
    inf << setw(10) << left << "Egz." << endl;

    for (int j = 1; j < kiekis+1; j++) {
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
    void studrus(vector<studentas>& students, vector<double>& galrez, vector<double>& median, vector<studentas>& vargsai, vector<studentas>& galva, const string& filename)
    {
        const int ilgis = 20;
        vector<double> galutrez1;
        vector<double> galutrez2;
        vector<double> galutrezg;
        vector<double> median1;
        vector<double> median2;
        vector<double> mediang;
        ifstream inf(filename);
        string firstline;
        getline(inf, firstline);
        studentas tempstud;
        int rakt;
        cout << "Studentus rikiuoti pagal bendra vidurki - 1" << endl << "Studentus rikiuoti pagal mediana - 2" << endl;
        cin >> rakt;
        auto start = high_resolution_clock::now();
        while (inf >> tempstud.vardas >> tempstud.pavarde) {
        tempstud.nd.clear(); // Clear the vector before resizing
        tempstud.nd.resize(15);
        for (int j = 0; j < 15; j++) {
            inf >> tempstud.nd[j];
        }
        inf >> tempstud.egzas;
        double nd_sum = accumulate(tempstud.nd.begin(), tempstud.nd.end(), 0);
        double vidurkis = nd_sum / 15;
        double galutinis = 0.4 * vidurkis + 0.6 * tempstud.egzas;
        double median_value;
        int n = tempstud.nd.size();
        sort(tempstud.nd.begin(), tempstud.nd.end());
        if (n % 2 == 0) {
            median_value = (tempstud.nd[n / 2 - 1] + tempstud.nd[n / 2]) / 2.0;
        } else {
            median_value = tempstud.nd[n / 2];
        }
        if(rakt == 1)
        {
        if (galutinis < 5){
            vargsai.push_back(tempstud);
            galutrez1.push_back(galutinis);
        }
        else if (galutinis >= 5){
            galva.push_back(tempstud);
            galutrez2.push_back(galutinis);
        }
        mediang.push_back(median_value);
        }
        else if(rakt == 2)
        {
        if (median_value < 5){
            vargsai.push_back(tempstud);
            median1.push_back(median_value);
        }
        else if (median_value >= 5){
            galva.push_back(tempstud);
            median2.push_back(median_value);
        }
        galutrezg.push_back(galutinis);
        }
        }
        auto end = high_resolution_clock::now();
        duration<double> diff = end-start;
        cout << "Nuskaityti faila ir surusiuoti uztruko " << diff.count() << " s" << endl;
        inf.close();
        auto start2 = high_resolution_clock::now();
        ofstream of("vargsai.txt");
        of << setw(ilgis) << left << "Pavarde" << " " << setw(ilgis) << left << "Vardas" << "     " << setw(ilgis) << left << "Galutinis (Vid. ) / Galutinis (Med. )" << endl;
        of << "..................................................................." << endl;
        of << fixed << setprecision(2);
        if(rakt == 1){
        for (size_t j = 0; j < vargsai.size(); j++) {
        of << setw(ilgis) << left << vargsai[j].pavarde << " " << setw(ilgis) << left << vargsai[j].vardas << "       " << setw(ilgis) << left << galutrez1[j] << "      " << setw(ilgis) << left << mediang[j] << endl;
        }
        }
        else if(rakt == 2){
        for (size_t j = 0; j < vargsai.size(); j++) {
        of << setw(ilgis) << left << vargsai[j].pavarde << " " << setw(ilgis) << left << vargsai[j].vardas << "       " << setw(ilgis) << left << galutrezg[j] << "      " << setw(ilgis) << left << median1[j] << endl;
        }
        }
        of.close();
        ofstream oif("galva.txt");
        oif << setw(ilgis) << left << "Pavarde" << " " << setw(ilgis) << left << "Vardas" << "     " << setw(ilgis) << left << "Galutinis (Vid. ) / Galutinis (Med. )" << endl;
        oif << "..................................................................." << endl;
        oif << fixed << setprecision(2);
        if(rakt == 1){
        for (size_t j = 0; j < galva.size(); j++) {
        oif << setw(ilgis) << left << galva[j].pavarde << " " << setw(ilgis) << left << galva[j].vardas << "       " << setw(ilgis) << left << galutrez2[j] << "      " << setw(ilgis) << left << mediang[j] << endl;
        }
        }
        if(rakt == 2){
        for (size_t j = 0; j < galva.size(); j++) {
        oif << setw(ilgis) << left << galva[j].pavarde << " " << setw(ilgis) << left << galva[j].vardas << "       " << setw(ilgis) << left << galutrezg[j] << "      " << setw(ilgis) << left << median2[j] << endl;
        }
        }
        oif.close();
        auto end2 = high_resolution_clock::now();
        duration<double> diff2 = end2-start2;
        cout << "Ivesti studentus i faila uztruko " << diff2.count() << " s" << endl;
}
    void skaityti(vector<studentas>& students, vector<double>& galrez, vector<double>& median) {
    int failas;
    cout << "Is kurio failo skaityti duomenis?" << endl << "10k duomenu - 1" << endl << "100k duomenu - 2" << endl << "1mil duomenu - 3" << endl;
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

    string firstline;
    getline(inf, firstline); // Skip the header line

    studentas tempstud;
    while (inf >> tempstud.vardas >> tempstud.pavarde) {
        // Dynamically resize the vector based on the number of homework grades read
        tempstud.nd.clear(); // Clear the vector before resizing
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

        // Calculate median and final grade
        sort(tempstud.nd.begin(), tempstud.nd.end());
        double median_value;
        int n = tempstud.nd.size();
        if (n % 2 == 0) {
            median_value = (tempstud.nd[n / 2 - 1] + tempstud.nd[n / 2]) / 2.0;
        } else {
            median_value = tempstud.nd[n / 2];
        }
        double nd_sum = accumulate(tempstud.nd.begin(), tempstud.nd.end(), 0);
        double vidurkis = nd_sum / n;
        double galutinis = 0.4 * vidurkis + 0.6 * tempstud.egzas;

        // Store results in vectors
        median.push_back(median_value);
        galrez.push_back(galutinis);
        students.push_back(tempstud);
    }

    inf.close();
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

    void rasytiranka(vector<studentas>& students, vector<double>& galrez, vector<double>& median){
        int pas;
            try{
                do {
                    cout << "Viska rasyti ranka - 1" << endl << "Generuoti tik pazymius - 2" << endl << "Generuoti ir pazymius ir studentu vardus, pavardes - 3" << endl << "Baigti darba - 4" << endl;
                    cin >> pas;

                    if (pas == 1 || pas == 2 || pas == 3) {
                        studentas temp_student;

                        if (pas == 3) {
                            temp_student.vardas = randname();
                            temp_student.pavarde = randname();
                        } else {
                            cout << "Iveskite studento varda: ";
                            cin >> temp_student.vardas;

                            cout << "Iveskite studento pavarde: ";
                            cin >> temp_student.pavarde;
                        }

                        int n;
                        try {
                            cout << "Iveskite studento pazymiu kieki: ";
                            cin >> n;
                            if (cin.fail()) {
                                cin.clear(); // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                                throw "Netinkamas ivesties pasirinkimas";
                            }
                        } catch (const char* msg) {
                            cerr << msg << endl;
                            return;
                        }

                        temp_student.nd.resize(n);

                        int ndvid = 0;
                        for (int i = 0; i < n; i++) {
                            if (pas == 2 || pas == 3)
                                temp_student.nd[i] = rand() % 10 + 1;
                            else {
                                try {
                                    cout << "Iveskite pazymi: ";
                                    cin >> temp_student.nd[i];
                                    if (cin.fail()) {
                                        cin.clear(); // Clear the error flag
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                                        throw "Netinkamas ivesties pasirinkimas";
                                    }
                                } catch (const char* msg) {
                                    cerr << msg << endl;
                                    return;
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
                        try {
                            cout << "Iveskite egzamino rezultata: ";
                            cin >> temp_student.egzas;
                            if (cin.fail()) {
                                cin.clear(); // Clear the error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                                throw "Netinkamas ivesties pasirinkimas";
                            }
                        } catch (const char* msg) {
                            cerr << msg << endl;
                            return;
                        }

                        galrez.push_back(0.4 * vidurkis + 0.6 * temp_student.egzas);

                        // Add the temporary student to the vectors
                        students.push_back(temp_student);
                    } else if (pas != 4) {
                        throw "Neteisingas duomenu ivedimo pasirinkimas";
                    }
                }while (pas != 4);
                spausdint(students, galrez, median);
            } catch (const char* msg) {
        cerr << msg << endl;
    }
}
    void skaitymas(vector<studentas>& students, vector<double>& galrez, vector<double>& median)
    {
        int rusis;
        try {
              skaityti(students, galrez, median);
            } catch (const char* msg) {
                cerr << msg << endl;
                exit(1);
            }
            try {
                cout << "Kaip norite kad butu surusiuoti duomenis?" << endl << "Pagal varda - 1" << endl << "Pagal pavarde - 2" << endl << "Galutini pazymiu vidurki - 3" << endl << "Galutini pagal mediana - 4" << endl;
                cin >> rusis;
                bool keist;
                if (rusis == 1) {
                    do {
                        keist = false;
                        for (int i = 0; i < students.size() - 1; i++) {
                            if (compareNames(students[i].vardas, students[i + 1].vardas)) {
                                swap(students[i].vardas, students[i + 1].vardas);
                                swap(students[i].pavarde, students[i + 1].pavarde);
                                swap(galrez[i], galrez[i + 1]);
                                swap(median[i], median[i + 1]);
                                keist = true;
                            }
                        }
                    } while (keist);
                }
                else if (rusis == 2) {
                    do {
                        keist = false;
                        for (int i = 0; i < students.size() - 1; i++) {
                            if (compareNames(students[i].pavarde, students[i + 1].pavarde)) {
                                swap(students[i].pavarde, students[i + 1].pavarde);
                                swap(galrez[i], galrez[i + 1]);
                                swap(median[i], median[i + 1]);
                                swap(students[i].vardas, students[i + 1].vardas);
                                keist = true;
                            }
                        }
                    } while (keist);
                }
                else if (rusis == 3) {
                    do {
                        keist = false;
                        for (int i = 0; i < students.size() - 1; i++) {
                            if (galrez[i] > galrez[i + 1]) {
                                swap(galrez[i], galrez[i + 1]);
                                swap(median[i], median[i + 1]);
                                swap(students[i].vardas, students[i + 1].vardas);
                                swap(students[i].pavarde, students[i + 1].pavarde);
                                keist = true;
                            }
                        }
                    } while (keist);
                }
                else if (rusis == 4) {
                    do {
                        keist = false;
                        for (int i = 0; i < students.size() - 1; i++) {
                            if (median[i] > median[i + 1]) {
                                swap(median[i], median[i + 1]);
                                swap(students[i].vardas, students[i + 1].vardas);
                                swap(students[i].pavarde, students[i + 1].pavarde);
                                swap(galrez[i], galrez[i + 1]);
                                keist = true;
                            }
                        }
                    } while (keist);
                } else {
                    throw "Neteisingas rusiavimo pasirinkimas";
                }
            } catch (const char* msg) {
                cerr << msg << endl;
                exit(1);
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
