#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

using namespace std;

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzas;

public:
    // Constructors
    Studentas() : egzas(0) {}
    Studentas(std::istream& is) { readStudent(is); }
    Studentas(int s) : egzas(s) {}

    // Copy constructor
    Studentas(const Studentas& s) : vardas(s.vardas), pavarde(s.pavarde), nd(s.nd), egzas(s.egzas) {}

    // Move constructor
    Studentas(Studentas&& s) noexcept : vardas{std::move(s.vardas)}, pavarde{std::move(s.pavarde)}, egzas{s.egzas}, nd{std::move(s.nd)} {
        s.egzas = 0;
    }

    ~Studentas() {}

    // Copy assignment operator
    Studentas& operator=(const Studentas& s);
    // Move assignment operator
    Studentas& operator=(Studentas&& s) noexcept;

    // Getters
    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    inline vector<int> getNd() const { return nd; }
    inline int getEgzas() const { return egzas; }

    double calculateFinalGrade() const;
    double calculateMedian() const;

    istream& readStudent(std::istream& is);

    // Setters
    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
    void setEgzas(int e) { egzas = e; }
    void addNd(int n) { nd.push_back(n); }

    //Out
    friend ostream& operator<<(ostream& out, const Studentas &a) {
        const int ilgis = 20;
        out << setw(ilgis) << left << a.getPavarde() << " " << setw(ilgis) << left << a.getVardas() << "       ";
        out << setw(ilgis) << left << a.calculateFinalGrade() << "      ";
        out << setw(ilgis) << left << a.calculateMedian() << endl;
        return out;
    }

    //In
    friend istream& operator>>(istream& in, Studentas &a) {
        a.nd.clear();
        a.nd.reserve(15);
        in >> a.vardas >> a.pavarde;
        for (int k = 0; k < 15; k++) {
            int nd_val;
            in >> nd_val;
            a.nd.push_back(nd_val);
        }
        in >> a.egzas;
        return in;
    }
};

void printStudentState(const Studentas& student, const string& name);
void studrus2(std::vector<Studentas>& students, std::vector<Studentas>& vargsai, std::vector<Studentas>& galva, const std::string& filename, int dydis);
void clearFiles();
int partition(std::vector<Studentas>& students, int low, int high, int rusis);
void quickSort(std::vector<Studentas>& students, int low, int high, int rusis);
void studrus(std::vector<Studentas>& students, std::vector<Studentas>& vargsai, std::vector<Studentas>& galva, const std::string& filename, int dydis);
void studrus1(std::vector<Studentas>& students, std::vector<Studentas>& vargsai, const std::string& filename, int dydis);
void createfile(const std::string& filename, const int& kiekis);
void skaitymas(std::vector<Studentas>& students);
void rasytiranka(std::vector<Studentas>& students);
void skaityti(std::vector<Studentas>& students);
void spausdint(const std::vector<Studentas>& students);
void spausdintfaila(const std::vector<Studentas>& students);
std::string randname();

#endif
