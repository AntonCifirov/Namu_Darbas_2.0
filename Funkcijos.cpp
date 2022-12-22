#pragma once
#include "my_lib.h"

//
//IVEDIMAS
//


/*vector<Duom> Sort(vector<Duom> temp)
{
    for (int k = 0; k < temp.size(); k++)
    {
        for (int i = 0; i < temp.size() - 1; i++)
        {
            string a = temp[i].pav;
            string b = temp[i + 1].pav;
            if ((a.compare(b) > 0))
            {
                Duom z;
                z = temp[i];
                temp[i] = temp[i + 1];
                temp[i + 1] = z;
            }
        }
    }
    return temp;
}*/
istream& operator>>(istream& in, Duom& a)
 {
     string str;
     int count = 0;
     double sk;
     getline(in, str);
     stringstream stream(str);
     str = "";


     while (stream >> str)
     {
         count++;
     }
     stream.clear();
     stream.seekg(0);
     stream >> a.mVar >> a.mPav;
     for (int i = 0; i < count - 3; i++)
     {
         stream >> sk;
         a.mPaz.push_back(sk);
     }
     stream >> a.mEgz;

     a.galutinis();

     a.galutinis_m();

     return in;
    }

istream& operator>>(std::string str, Duom& a) {
    int count = 0;

    stringstream in(str);
    while (in)
    {
        count++;
    }
    in.clear();
    in.seekg(0);

    in >> a.mVar >> a.mPav;
    for (int i = 0; i != count - 3; i++)
    {
        in >> a.mPaz[i];
    }
    in >> a.mEgz;

    return in;
}

Duom::Duom(string Var, string Pav, vector<double> Paz, double Egz) : Zmogus{ Var, Pav }, mPaz{ Paz }, mEgz{Egz}
{
    galutinis();
    galutinis_m();
}



void Duom::sorting()
{
    sort(mPaz.begin(), mPaz.end());
}

double Duom::findMean()
{
    int nd_sk = mPaz.size();
    float vidurkis;
    float sum = 0;
    for (int z = 0; z < nd_sk; z++) {
        sum = sum + mPaz[z];
    }
    vidurkis = (sum) / (nd_sk);
    return vidurkis;
}

double Duom::findMedian()
{
    sorting();
    int n = mPaz.size();
    if (n % 2 == 0)
    {
        double median = (mPaz[n / 2] + mPaz[(n / 2) - 1]) / 2 + 0.5;
        return median;
    }
    else
    {
        double median = (mPaz[(n / 2)]);
        return median;
    }
}

void Duom::galutinis_m() 
{ 
    mGal_m = 0.4 * findMedian() + 0.6 * mEgz; 
}

void Duom::galutinis() 
{ 
    mGal = 0.4 * findMean() + 0.6 * mEgz;
}

Duom eilutes_nuskaitymas(ifstream& kursiokai, int nd_sk)
{
    string Var, Pav;
    vector<double> Paz;
    int Egz;
    kursiokai >> Var;
    kursiokai >> Pav;
    int p;
    for (int k = 0; k < nd_sk; k++)
    {
        kursiokai >> p;
        Paz.push_back(p);

    }

    kursiokai >> Egz;
    Duom asmuo(Var, Pav, Paz, Egz);
    /*double median;
    median = findMedian(asmuo, nd_sk);
    asmuo.gal_m = 0.4 * median + 0.6 * asmuo.egz;
    float vidurkis;
    float sum = 0;
    for (int z = 0; z < nd_sk; z++) {
        sum = sum + asmuo.paz[z];
    }
    vidurkis = (sum) / (nd_sk);
    asmuo.gal = 0.4 * vidurkis + 0.6 * asmuo.egz;

*/
    return asmuo;
}
void Duom::eilutes_nuskaitymas(ifstream& kursiokai, int nd_sk)
{
    string Var, Pav;
    vector<double> Paz;
    int Egz;
    kursiokai >> Var;
    kursiokai >> Pav;
    double p;
    for (int k = 0; k < nd_sk; k++)
    {
        kursiokai >> p;
        Paz.push_back(p);
    }

    kursiokai >> Egz;
    mVar = Var;
    mPav = Pav;
    mPaz = Paz;
    mEgz = Egz;
    galutinis();
    galutinis_m();
}


string txt = " ";
int nd_sk = 0;
ifstream kursiokai;
/*
vector<Duom> Failo_nuskaitymas() {
    string txt = "";

    int word = 0;
    char failo_pavadinimas[20];
    cout << "Iveskite failo pavadinima: ";
    cin >> failo_pavadinimas;
    try
    {
        kursiokai.open(failo_pavadinimas);
    }
    catch (const ifstream::failure& e)
    {
        cout << "Nera tokio failo";
    }


    //cout << "Toks failas neegzistuoja" << endl;


    vector<Duom> asmuo1;

    //counting the number of students stud_sk
    vector<string> eilutes;
    while (getline(kursiokai, txt))
    {

        eilutes.push_back(txt);
    }
    int stud_sk = eilutes.size() - 1;

    kursiokai.clear();
    kursiokai.seekg(0); //pointer to begging
    txt.clear();

    while (kursiokai >> txt)
    {

        nd_sk++;
    }
    nd_sk = (nd_sk - 3 * (stud_sk + 1)) / (stud_sk + 1);



    kursiokai.clear();
    kursiokai.seekg(0);
    getline(kursiokai, txt);

    for (int i = 0; i < stud_sk; i++)
    {
        asmuo1.push_back(.eilutes_nuskaitymas(nd_sk));
    }

    txt.clear();


    return asmuo1;
}
*/

void Failo_nuskaitymas(string failo_pavadinimas, vector<Duom>& asmuo1) {
    string txt = "";
    Duom asmuo;


    kursiokai.open(failo_pavadinimas + ".txt");

    int stud_sk{ -1 };
    //counting the number of students stud_sk

    while (getline(kursiokai, txt))
    {
        stud_sk++;
    }

    kursiokai.clear();
    kursiokai.seekg(0); //pointer to begging


    getline(kursiokai, txt);
    istringstream line(txt);
    nd_sk = 0;
    while (line >> txt)
    {
        nd_sk++;
    }
    nd_sk = nd_sk - 3;
    line.clear();
    //  kursiokai.clear();
    //  kursiokai.seekg(0);




    for (int i = 0; i < stud_sk; i++)
    {
        asmuo.eilutes_nuskaitymas(kursiokai, nd_sk);
        asmuo1.push_back(asmuo);
    }


    kursiokai.clear();
    kursiokai.seekg(0);
    kursiokai.close();
    txt.clear();

}

 
void Failo_nuskaitymas(string failo_pavadinimas, list<Duom>& asmuo1) {

    Duom asmuo;
    kursiokai.open(failo_pavadinimas + ".txt");
    string txt = "";
    int stud_sk = -1;

    //counting the number of students stud_sk
    while (getline(kursiokai, txt))
    {
        stud_sk++;
    }


    kursiokai.clear();
    kursiokai.seekg(0); //pointer to begging

    getline(kursiokai, txt);
    istringstream line(txt);

    nd_sk = 0;
    while (line >> txt)
    {
        nd_sk++;
    }
    nd_sk = nd_sk - 3;
    //   kursiokai.clear();
    //   kursiokai.seekg(0);
    //   getline(kursiokai, txt);

    for (int i = 0; i < stud_sk; i++)

    {

        asmuo.eilutes_nuskaitymas(kursiokai, nd_sk);
        asmuo1.push_back(asmuo);
    }

    //   kursiokai.clear();
    //   kursiokai.seekg(0);
    kursiokai.close();
    line.clear();
    txt.clear();
    cout << "____7" << endl;

}

/*
Duom ivedimas() {
    Duom asmuo;
    int random;
    cout << "Ar norite atsitiktinai sugeneruoti duomenys, ar ivesti. Ivesti - spauskite 0 ENTER. Sugeneruoti - spauskite 1 ENTER." << endl;
    cin >> random;



    if (random) //atsitiktinai generuoojame duomenys
    {
        string Vardai[15] = { "James", "Robert", "John", "Michael", "David",  "William",  "Richard",  "Mary",  "Patricia",  "Jennifer", "Linda", "Elizabeth", "Barbara", "Susan", "Jessica" };
        string Pavardes[15] = { "Smith", "Johnson", "Williams", "Brown", "Jones",  "Miller",  "Davis",  "Garcia",  "Rodriguez",  "Wilson", "Martinez", "Anderson", "Taylor", "Thomas", "Hernandez" };


        asmuo.var = Vardai[rand() % 15];

        asmuo.pav = Pavardes[rand() % 15];
        cout << "Kiek namu darbu pazymiu norite sugeneruot ? ";
        cin >> asmuo.n;
        for (int i = 0; i < asmuo.n; i++)
        {
            asmuo.paz.push_back((rand() % 10) + 1);
        }
        asmuo.egz = ((rand() % 10) + 1);

    }



    // ivedame duomenys ranka
    else {
        cout << "Iveskite mokynio varda: " << endl; cin >> asmuo.var;
        cout << "Iveskite mokynio pavarde: " << endl; cin >> asmuo.pav;

        for (int i = 0; i > -5; i++) {
            cout << "Iveskite " << i + 1 << "nd pazymi, baigus ivedima spauskite 0 ENTER: " << endl;
            int k;
            cin >> k;
            while (true) {
                if (!cin) {
                    cout << "Neteisingas ivedimo formatas, iveskite dar karta: " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> k;
                    if (!cin) {
                        continue;
                    }
                    else break;
                }
                else   break;
            }
            if (k == 0) break;
            else if (k <= 10 && k >= 1) {
                asmuo.paz.push_back(k);
                asmuo.n++;
            }
        }
        cout << "Iveskite mokinio egzamino pazymi: " << endl;
        while (true) {
            cin >> asmuo.egz;
            if (!cin) {
                cout << "Neteisingas ivedimo formatas, iveskite is naujo: " << endl;
                cin.clear();
                cin.ignore();
            }
            else break;
        }
    }



    cout << "Ar galutini pazymi norite skaiciuoti su Vidurkiu ar su Mediana? Mediana - spauskite 1 ENTER. Vidurkis - spauskite 0 ENTER." << endl;
    int if_median;

    cin >> if_median;
    if (if_median) // skaicuojam mediana
    {
        double median;
        median = findMedian(asmuo, asmuo.n);
        asmuo.gal = 0.4 * median + 0.6 * asmuo.egz;
    }

    else // skaicuojam vidurki
    {

        float vidurkis;
        float sum = 0;
        for (int i = 0; i < asmuo.n; i++) {
            sum = sum + asmuo.paz[i];
        }
        vidurkis = (sum) / (asmuo.n);
        asmuo.gal = 0.4 * vidurkis + 0.6 * asmuo.egz;
    }


    return asmuo;
}*/

//
//ISVEDIMAS
//

int int_length(int x) {
    int a;
    a = floor(log10(x) + 1);
    return a;
}

void isvedimas(Duom temp) {

    string tab_1(6, ' ');
    string tab_2(7, ' ');
    string tab_3(5, ' ');
    string egz_tab(11 - int_length(temp.egzaminas()), ' ');
    string gal_tab(11 - int_length(temp.mGal), ' ');
    string V_ardas(temp.vardas().length(), ' ');
    string P_avarde(temp.pavarde().length(), ' ');



    //pirmos lenteles eilutes isvedimas
    cout << "|Vardas" << V_ardas << "|Pavarde" << P_avarde;
    for (int i = 0; i < temp.pazymiai().size(); i++) {
        string nd_tab(7 - int_length(i + 1), ' ');
        cout << "|" << i + 1 << "nd" << nd_tab;
    }


    cout << "|Egzaminas  ";
    cout << "|Galutinis  ";
    cout << endl;


    // antros lenteles eilutes isvedimas
    cout << "|" << temp.vardas() << tab_1;
    cout << "|" << temp.pavarde() << tab_2;
    for (int i = 0; i < temp.pazymiai().size(); i++) {
        string paz_tab(9 - int_length(temp.pazymiai()[i]), ' ');
        cout << "|" << temp.pazymiai()[i] << paz_tab;


    }
    cout << "|" << temp.egzaminas() << egz_tab;
    cout << "|" << setprecision(2) << temp.mGal << gal_tab << endl << endl;



}

void ISVEDIMAS(vector<Duom> temp)
{
    string V_ardas(10, ' ');
    string P_avarde(10, ' ');
    string Gal_vid(6, ' ');
    cout << " __________________________________________________________________________" << endl;
    cout << "|Vardas" << V_ardas << "|Pavarde" << P_avarde;
    cout << "|Galutinis (vid.)" << Gal_vid << "|Galutinis (med.)|" << endl;
    cout << "|                |                 |                      |                |" << endl;
    cout << "|--------------------------------------------------------------------------|" << endl;

    for (auto i : temp)
    {
        string var(16 - i.vardas().length(), ' ');
        string pav(17 - i.pavarde().length(), ' ');
        string gal(18, ' ');
        string gal_m(12, ' ');
        cout << "|" << i.vardas() << var;
        cout << "|" << i.pavarde() << pav;
        cout << "|" << fixed << setprecision(2) << i.mGal << gal;
        cout << "|" << fixed << setprecision(2) << i.mGal_m << gal_m << "|" << endl;

    }

    cout << "|__________________________________________________________________________|" << endl;
}

void ISVEDIMAS2(vector<Duom> temp)
{
    string V_ardas(10, ' ');
    string P_avarde(10, ' ');
    string egz(6, ' ');
    cout << " __________________________________________________________________________" << endl;
    cout << "|Vardas" << V_ardas << "|Pavarde" << P_avarde;
    cout << "|Egzaminas" << egz << "|Galutinis" << endl;
    cout << "|                |                 |               |                       |" << endl;
    cout << "|--------------------------------------------------------------------------|" << endl;

    for (auto i : temp)
    {
        string var(16 - i.vardas().length(), ' ');
        string pav(17 - i.pavarde().length(), ' ');
        string gal(19, ' ');
        string egz(11, ' ');
        cout << "|" << i.vardas() << var;
        cout << "|" << i.pavarde() << pav;
        cout << "|" << fixed << setprecision(2) << i.egzaminas() << egz;
        cout << "|" << fixed << setprecision(2) << i.mGal << gal << "|" << endl;

    }

    cout << "|__________________________________________________________________________|" << endl;
}