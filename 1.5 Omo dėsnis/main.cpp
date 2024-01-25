#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas kaip ifstream ir ofstream.

using namespace std; // standartinės funkcijos ir kintamieji

//duomenų ir rezultatų failų aprašymas
const char duomenu_failas [] = "Duomenys.txt"; // Duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatų failo vardas.

void stipris (double U, double R, double & I) // funkcija, apskaičiuojanti stiprį.
{
    I = U / R; // formulė, naudojama apskaičiuoti stiprį.
}

void itampa (double I, double R, double & U)  // funkcija, apskaičiuoanti įtampą.
{
    U = I * R; // formulė, naudojama apskaičiuoti įtampai.
}

void varza(double U, double I, double & R) // funkcija, apskaičiuojanti varžą.
{
    R = U / I; // formulė, naudojama apskaičiuoti varžai.
}

int main() // pagrindinė programos funkcija
{
    setlocale(LC_ALL, "Lithuanian"); // nustatoma lietuvių kalba.

    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolë iðvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        ofstream rf (rezultatu_failas); // atidaromas rezultatų failas.

        int n; // įvedamas kintamasis n, nurodantis bandymų skaičių.
        df >> n; // nuskaitome bandymų skaičių iš duomenų failo.

        double I, U, R; // įvedame stiprio, įtampos ir varžos kintamuosius.

        cout << "Bandymų rezultatai" << endl; // į rezultatų failą įvedamas lentelės pavadinimas.
        cout << "—------------------" << endl; // į rezultatų failą įvedamos lentelės ribos.
        cout << "     I   U   R    " << endl; // į rezultatų failą įvedamos raidės, nurodančios, kurioj vietoj yra kuri reikšmė.
        cout << "—------------------" << endl; // į rezultatų failą įvedamos lentelės ribos.

        for (int i = 0; i < n; ++i) // sąlyga. kad ciklas kartosis tol, kol i bus vienetu mažiau už n.
        {
            df >> I >> U >> R; // nuskaitomas stipris, įtampa ir varža iš duomenų failo.

            if (I == 0) // sąlyga, jeigu stipris lygus 0.
            {
                stipris(U, R, I); // tada iškviečiama funkcija, apskaičiuojanti stiprį.
            }
            else if (U == 0) // sąlyga, jeigu įtampa lygi 0.
            {
                itampa(I, R, U); // tada iškviečiama funkcija, apskaičiuojanti įtampą.
            }
            else // jeigu nei viena sąlyga neatitinka.
            {
                varza(U, I, R); // tada iškviečiama funkcija, apskaičiuojanti varžą.
            }

            cout << "     " << I << "   " << U << "   " << R << endl; // į rezultatų failą įrašomi gauti rezultatai, atskirti tarpais.
        }

    cout << "—-------------------------" << endl; // į rezultatų failą įvedamos lentelės ribos.

    df.close(); // uždarome duomenų failą.
    rf.close(); // uždarome rezultatų failą.

    return 0;
    }
}

