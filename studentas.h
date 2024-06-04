#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Studentas
{
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzas;

public:
    //Konstruktoriai ir destruktorius
    Studentas() : egzas(0) { }
    Studentas(std::istream& is) { readStudent(is); }
    ~Studentas() {};

    // Getteriai
    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    inline vector<int> getNd() const { return nd; }
    inline int getEgzas() const { return egzas; }

    double calculateFinalGrade() const;
    double calculateMedian() const;

    istream& readStudent(std::istream& is);

    // Setteriai
    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
    void setEgzas(int e) { egzas = e; }
    void addNd(int n) { nd.push_back(n); }
};

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
