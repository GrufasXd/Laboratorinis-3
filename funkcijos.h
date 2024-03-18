#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <string>
#include <vector>
#include <functional>

struct studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd;
    int egzas;
};
void skaitytifaila(int rakt, std::vector<studentas>& vargsai, std::vector<studentas>& galva, std::vector<double> galutrez1, std::vector<double> galutrez2, std::vector<double> galutrezg, std::vector<double> median1, std::vector<double> median2, std::vector<double> mediang);
void studrus(std::vector<studentas>& students, std::vector<double>& galrez, std::vector<double>& median, std::vector<studentas>& vargsai, std::vector<studentas>& galva, const std::string& filename);
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
