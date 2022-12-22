#pragma once
#include "my_lib.h"

vector<Duom> Sort(vector<Duom>);
//rusiuoja

Duom sorting(Duom);
// rusiuoja duom.paz


double findMean(Duom, int);
//randa vidurki vektoriaus Duom.paz;

double findMedian(Duom, int);
//randa mediana vektoriaus duom.paz;

Duom ivedimas();
//ivedimas ranka arba atsitiktinis generavimas

Duom eilutes_nuskaitymas();
//patalpina viena failo eilute i duom tipo objecta

vector<Duom> Failo_nuskaitymas();
//nuskaito visa faila ir patalpina info i vector<duom>

void Failo_nuskaitymas(string failo_pavadinimas, vector<Duom>& asmuo1);
//overoad funkcijos Failo_nuskaitymas
// nuskaito faila - failo_pavadinimas.txt

void Failo_nuskaitymas(string failo_pavadinimas, list<Duom>& asmuo1);
//nuskaito visa faila ir patalpina info i list<duom>


int int_length(int);
//grazina skaiciaus ilgi;


void isvedimas(Duom);
//isveda dveju eiluciu lentele tipo:
//Vardas   Pavarde   ND1   ND2  ... EGZAMINAS   GALUTINIS
//Iosif    Mainhem   10    10

void ISVEDIMAS(vector<Duom>);

void ISVEDIMAS2(vector<Duom> temp);
