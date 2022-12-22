
#pragma once
#include "my_lib.h"
#include "Funkcijos.h"


string generuoja_faila(int mokiniu_sk, int nd_sk);

void RemoveStudent(vector<Duom>& students, int gal);


void Failo_rusiavimas_vector(vector<Duom> asmuo_vector, vector<Duom>& varg_vector, vector<Duom>& kiet_vector);

void Failo_rusiavimas_vector_mod(vector<Duom> asmuo_vector, vector<Duom>& varg_vector, vector<Duom>& kiet_vector);

void Failo_rusiavimas_vector_2str(vector<Duom>& asmuo_vector, vector<Duom>& varg_vector);

void Failo_rusiavimas_vector_2str_mod(vector<Duom>& asmuo_vector, vector<Duom>& varg_vector);

void Failo_rusiavimas_list(list<Duom> asmuo_list, list<Duom>& varg_list, list<Duom>& kiet_list);

void Failo_rusiavimas_list_2str(list<Duom>& asmuo_list, list<Duom>& varg_list);

/*
void Failo_rusiavimas_vargseliai(vector<duom> asmuo_vector, vector<duom>& varg_vector);

void Failo_rusiavimas_vargseliai(list<duom> asmuo_list, list<duom>& varg_list);

void Failo_rusiavimas_kietakai(vector<duom> asmuo_vector, vector<duom>& kiet_vector);

void Failo_rusiavimas_kietakai(list<duom> asmuo_list, list<duom>& kiet_vector);
*/

void Isvedimas_i_failus_vector(string failo_pavadinimas, vector<Duom> varg, vector<Duom> kiet);

void Isvedimas_i_failus_list(string failo_pavadinimas, list<Duom> varg, list<Duom> kiet);
