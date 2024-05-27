#ifndef FUNKCIJOSLIST_H
#define FUNKCIJOSLIST_H

#include <string>
#include <vector>
#include <functional>
#include <list>
using namespace std;
struct studentas {
    std::string vardas;
    std::string pavarde;
    std::list<int> nd;
    int egzas;
};
void studrus2(list<studentas>& students, list<studentas>& vargsai, const string& filename, int dydis);
void studrus1(list<studentas>& students, list<studentas>& vargsai, const string& filename, int dydis);
void clearFiles();
int partition(vector<studentas>& students, vector<double>& galrez, vector<double>& median, int low, int high, int rusis);
void quickSort(vector<studentas>& students, vector<double>& galrez, vector<double>& median, int low, int high, int rusis);
void studrus(list<studentas>& students, list<studentas>& vargsai, list<studentas>& galva, const string& filename, int dydis);
void createfile(const std::string& filename, const int& kiekis);
void skaitymas(std::vector<studentas>& students, std::vector<double>& galrez, std::vector<double>& median);
void rasytiranka(std::vector<studentas>& students, std::vector<double>& galrez, std::vector<double>& median);
int readInt(const std::string& prompt);
bool isNumeric(const std::string& str);
bool compareNames(const std::string& a, const std::string& b);
void skaityti(std::vector<studentas>& students, std::vector<double>& galrez, std::vector<double>& median);
void spausdint(const std::vector<studentas>& students, const std::vector<double>& galrez, const std::vector<double>& median);
void spausdintfaila(const std::vector<studentas>& students, const std::vector<double>& galrez, const std::vector<double>& median);
std::string randname();

#endif
