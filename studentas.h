#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <stdexcept> // for std::out_of_range
#include <iterator> // for std::iterator
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

using namespace std;

template <typename T>
class Vector {
public:
    // Member types
    using value_type = T;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

private:
    size_type _size;
    size_type _capacity;
    T* _data;

    void reallocate(size_type new_capacity) {
        T* new_data = new T[new_capacity];
        std::copy(_data, _data + _size, new_data);
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    // Constructors
    Vector() : _size(0), _capacity(1), _data(new T[1]) {}
    
    explicit Vector(size_type count) : _size(count), _capacity(count), _data(new T[count]) {}

    Vector(size_type count, const T& value) : _size(count), _capacity(count), _data(new T[count]) {
        std::fill(_data, _data + _size, value);
    }

    Vector(const Vector& other) : _size(other._size), _capacity(other._capacity), _data(new T[other._capacity]) {
        std::copy(other._data, other._data + other._size, _data);
    }

    Vector(Vector&& other) noexcept : _size(other._size), _capacity(other._capacity), _data(other._data) {
        other._data = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    Vector(std::initializer_list<T> init) : _size(init.size()), _capacity(init.size()), _data(new T[init.size()]) {
        std::copy(init.begin(), init.end(), _data);
    }

    // Destructor
    ~Vector() {
        delete[] _data;
    }

    // Assignment operators
    void assign(size_type count, const T& value) {
        if (count > _capacity) {
            reallocate(count);
        }
        std::fill(_data, _data + count, value);
        _size = count;
    }

    template <typename InputIt>
    void assign(InputIt first, InputIt last) {
        size_type count = std::distance(first, last);
        if (count > _capacity) {
            reallocate(count);
        }
        std::copy(first, last, _data);
        _size = count;
    }

    void assign(std::initializer_list<T> ilist) {
        if (ilist.size() > _capacity) {
            reallocate(ilist.size());
        }
        std::copy(ilist.begin(), ilist.end(), _data);
        _size = ilist.size();
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _capacity = other._capacity;
            _data = new T[_capacity];
            std::copy(other._data, other._data + _size, _data);
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _capacity = other._capacity;
            _data = other._data;
            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;
        }
        return *this;
    }

    // Element access
    reference at(size_type pos) {
        if (pos >= _size) throw std::out_of_range("Index out of range");
        return _data[pos];
    }

    const_reference at(size_type pos) const {
        if (pos >= _size) throw std::out_of_range("Index out of range");
        return _data[pos];
    }

    reference operator[](size_type pos) {
        return _data[pos];
    }

    const_reference operator[](size_type pos) const {
        return _data[pos];
    }

    reference front() {
        return _data[0];
    }

    const_reference front() const {
        return _data[0];
    }

    reference back() {
        return _data[_size - 1];
    }

    const_reference back() const {
        return _data[_size - 1];
    }

    pointer data() noexcept {
        return _data;
    }

    const_pointer data() const noexcept {
        return _data;
    }

    // Iterators
    iterator begin() noexcept {
        return _data;
    }

    const_iterator begin() const noexcept {
        return _data;
    }

    iterator end() noexcept {
        return _data + _size;
    }

    const_iterator end() const noexcept {
        return _data + _size;
    }

    reverse_iterator rbegin() noexcept {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() noexcept {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator(begin());
    }

    // Capacity
    bool empty() const noexcept {
        return _size == 0;
    }

    size_type size() const noexcept {
        return _size;
    }

    size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max();
}

    void reserve(size_type new_cap) {
        if (new_cap > _capacity) {
            reallocate(new_cap);
        }
    }

    size_type capacity() const noexcept {
        return _capacity;
    }

    void shrink_to_fit() {
        if (_capacity > _size) {
            reallocate(_size);
        }
    }

    // Modifiers
    void clear() noexcept {
        _size = 0;
    }

    void push_back(const T& value) {
        if (_size >= _capacity) {
            reallocate(_capacity * 2);
        }
        _data[_size++] = value;
    }

    void push_back(T&& value) {
        if (_size >= _capacity) {
            reallocate(_capacity * 2);
        }
        _data[_size++] = std::move(value);
    }

    void pop_back() {
        if (_size > 0) --_size;
    }

    void resize(size_type count) {
        if (count > _capacity) {
            reallocate(count);
        }
        _size = count;
    }

    void resize(size_type count, const value_type& value) {
        if (count > _capacity) {
            reallocate(count);
        }
        if (count > _size) {
            std::fill(_data + _size, _data + count, value);
        }
        _size = count;
    }

    // Non-member functions
    friend bool operator==(const Vector& lhs, const Vector& rhs) {
        if (lhs._size != rhs._size) return false;
        return std::equal(lhs._data, lhs._data + lhs._size, rhs._data);
    }

    friend bool operator!=(const Vector& lhs, const Vector& rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const Vector& lhs, const Vector& rhs) {
        return std::lexicographical_compare(lhs._data, lhs._data + lhs._size, rhs._data, rhs._data + rhs._size);
    }

    friend bool operator<=(const Vector& lhs, const Vector& rhs) {
        return !(rhs < lhs);
    }

    friend bool operator>(const Vector& lhs, const Vector& rhs) {
        return rhs < lhs;
    }

    friend bool operator>=(const Vector& lhs, const Vector& rhs) {
        return !(lhs < rhs);
    }
};

class Zmogus 
{
protected:
    string vardas;
    string pavarde;
    int amzius;
public:
    Zmogus() = default;
    Zmogus(const string& vardas, const string& pavarde) : vardas(vardas), pavarde(pavarde) {}
    virtual ~Zmogus() = default;
        
    // Getteriai
    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }

    // Setteriai
    virtual void setVardas(const string& v) = 0;
    virtual void setPavarde(const string& p) = 0;

    // Copy constructor
    Zmogus(const Zmogus& o) : vardas(o.vardas), pavarde(o.pavarde) {}
    
    // Move constructor
    Zmogus(Zmogus&& o) noexcept : vardas(move(o.vardas)), pavarde(move(o.pavarde)) {}
        
    // Copy assignment operator
    Zmogus& operator=(const Zmogus& o);

    // Move assignment operator
    Zmogus& operator=(Zmogus&& z) noexcept;
};

class Studentas: public Zmogus {
private:
    Vector<int> nd;
    int egzas;

public:
    // Constructors
    Studentas() : Zmogus(), egzas(0) {}
    Studentas(const string& vardas, const string& pavarde, int egzas = 0) 
        : Zmogus(vardas, pavarde), egzas(egzas) {}
    Studentas(std::istream& is) { readStudent(is); }
    Studentas(int s) : Zmogus(), egzas(s) {}

    // Copy constructor
    Studentas(const Studentas& s) : Zmogus(s.vardas, s.pavarde), nd(s.nd), egzas(s.egzas) {}

    // Move constructor
    Studentas(Studentas&& s) noexcept : Zmogus(move(s)), nd(move(s.nd)), egzas(s.egzas) {
        s.egzas = 0;
    }

    //Naudojamas patikrinimui
    //~Studentas() { cout << "Sunaikintas " << vardas << " " << pavarde << " kurio egzamino rezultatas " << egzas << endl;}
    ~Studentas() {}

    // Copy assignment operator
    Studentas& operator=(const Studentas& s);
    // Move assignment operator
    Studentas& operator=(Studentas&& s) noexcept;

    // Getters
    inline Vector<int> getNd() const { return nd; }
    inline int getEgzas() const { return egzas; }

    //Calculate funkcijos
    double calculateFinalGrade() const;
    double calculateMedian() const;

    istream& readStudent(std::istream& is);

    // Setters
    void setVardas(const string& v) override { vardas = v; }
    void setPavarde(const string& p) override { pavarde = p; }
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
void studrus2(Vector<Studentas>& students, Vector<Studentas>& vargsai, Vector<Studentas>& galva, const string& filename, int dydis);
void clearFiles();
int partition(Vector<Studentas>& students, int low, int high, int rusis);
void quickSort(Vector<Studentas>& students, int low, int high, int rusis);
void studrus(Vector<Studentas>& students, Vector<Studentas>& vargsai, Vector<Studentas>& galva, const string& filename, int dydis);
void studrus1(Vector<Studentas>& students, Vector<Studentas>& vargsai, const string& filename, int dydis);
void createfile(const string& filename, const int& kiekis);
void skaitymas(Vector<Studentas>& students);
void rasytiranka(Vector<Studentas>& students);
void skaityti(Vector<Studentas>& students);
void spausdint(const Vector<Studentas>& students);
void spausdintfaila(const Vector<Studentas>& students);
std::string randname();

#endif
