#pragma once
#pragma once
#pragma once
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <sstream>
using std::ifstream;
using std::string;
using std::endl;
using std::cin;
using std::cout;
using std::nothrow;
using std::floor;
using std::vector;
using std::sort;
using std::setprecision;
using std::fstream;
using std::getline;
using namespace std;


class Zmogus {

protected:
    string mVar;
    string mPav;


public:

    Zmogus() {};
    Zmogus(string Var, string Pav) : mVar{ Var }, mPav{ Pav } {};

    virtual void print() = 0;

    string vardas() 
        { return mVar; }    //mVar getter

    void vardas(string Var) 
        { mVar = Var; };  //mVar setter

    string pavarde()
        { return mPav; }  //mPav getter

    void pavarde(string Pav) 
        { mPav = Pav; } //mPav setter



};



class Duom: public Zmogus {
private:
    vector <double> mPaz;
    int mN = 0;
    double mEgz;
public:
    double mGal;
    double mGal_m = 0;

    Duom() {};

    Duom(string Var, string Pav, vector<double> Paz, double Egz);

    //Duom(string Var, string Pav, vector<double> Paz, double Egz);  // konstruktorius 


    //Duom(const Duom& a) : mVar(a.mVar), mPav(a.mPav), mPaz(a.mPaz), mEgz(a.mEgz), mGal(a.mGal), mGal_m(a.mGal_m) {};

    Duom& operator=(Duom const a) 
    {
        //if(this != a)
        if (mPaz.size() != a.mPaz.size())
        {
            mPaz.resize(a.mPaz.size());
        }
        else
        {
            mVar = a.mVar;
            mPav = a.mPav;
            mPaz = a.mPaz;
            mEgz = a.mEgz;
            mGal = a.mGal;
            mGal_m = a.mGal_m;
        }
        return *this;
    }

    Duom(ifstream& is);

    inline int pazymiu_sk() const { return mN; }

    inline void egzaminas(int a)  { mEgz = a; } //mEgz setter

    inline double egzaminas() const { return mEgz; } //mEgz getter

    inline vector<double> pazymiai() const { return mPaz; } //mPaz getter

    inline void pazymiai(vector<double> Paz) { mPaz = Paz; } //mPaz setter

    inline string vardas() const { return mVar; }    //mVar getter

    inline void vardas(string Var) { mVar = Var; };  //mVar setter

    inline string pavarde() const { return mPav; }  //mPav getter

    inline void pavarde(string Pav) { mPav = Pav; } //mPav setter

    void galutinis_m();

    void galutinis();

    void eilutes_nuskaitymas(ifstream& kursiokai, int nd_sk);

    friend ostream& operator<<(ostream& out, const Duom& a) {
        out << a.mVar << "   " << a.mPav << "  " << endl;
        out << "Pazymiai : [ ";
        for (int i = 0; i != a.mPaz.size(); i++)
        {
            out << a.mPaz[i] << ", ";
        }
        out << "] " << endl;;
        out << "Egzaminas : " << a.mEgz << endl;
        out << "Galutinis(su vidurkiu) : " <<fixed<<setprecision(2)<< a.mGal << endl;
        out << "Galutinis(su mediana) : " << fixed << setprecision(2) << a.mGal_m << endl;
        return out;
    }

    double findMean();

    double findMedian();

    void sorting();

    friend istream& operator>>(istream& in, Duom& a);
 
    friend std::istream& operator>>(std::string str, Duom& a);

    ifstream& readStudent(ifstream &kursiokai);

    ~Duom() 
    {
        mVar.clear();
        mPav.clear();
        mPaz.clear();
    }

    void print()
    {
        cout << "Vardas : " << mVar << endl;
        cout << "Pavarde : " << mPav << endl;
        cout << "Pazymiai : " << " ";
        for (auto paz : mPaz)
        {
            cout << paz << " ";
        }
        cout << "Egzaminas : " << mEgz << endl;
        cout << "Galutinis : " << mGal << endl;
        cout << "Galutinis(med.) " << mGal_m << endl;
    }


};
/*

*/
