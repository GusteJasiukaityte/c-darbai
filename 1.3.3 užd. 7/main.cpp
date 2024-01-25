//prijungiame bibliotekas.
#include <iostream> // biblioteka atsakinga už komandas cout ir cin.
#include <fstream> // biblioteka atsakinga už komandas ifstream ir ofstream.
#include <time.h> // biblioteka, šioje programoje naudojama atsitiktinio skaičiaus generavimui.

using namespace std; // priklauso standartinės funkcijos ir kintamieji.

void skaiciai(int kiek, int minimumas, int maksimumas); // programai pranešama apie funkcijos egzistavimą.

int main() // pagrindinė programos funkcija.
{
    int kiek, // kintamasis, nurodantis, kiek atsitiktinių skaičių reikia sugeneruoti.
    minimumas, // mažiausia galima atsitiktinio skaičiaus reikšmė.
    maksimumas; // didžiausia galima atsitiktinio skaičiaus reikšmė.

    setlocale(LC_ALL, "Lithuanian");  // išvedimui naudosime lietuvių kalbą.

    cout << "Įveskite skaičių: " << endl; // prašoma vartotojo įvesti skaičių.
    cin >> kiek; // įvedamas skaičius nurodantis, kiek atsitiktinių skaičių reikia sugeneruoti.
    cout << endl; // tarp kito klausimo ir įvedamo skaičiaus padaromas vienos eilutėss tarpas.

    cout << "Įveskite mažiausią galimą atsitiktinio skaičiaus reikšmę: " << endl; // prašoma vartotojo įvesti mažiausią galimą atsitiktinio skaičiaus reikšmę.
    cin >> minimumas; // įvedama mažiausia galima atsitiktinio skaičiaus reikšmė.
    cout << endl; // tarp kito klausimo ir įvedamo skaičiaus padaromas vienos eilutėss tarpas.

    cout << "Įveskite didžiausią galimą atsitiktinio skaičiaus reikšmę: " << endl; // prašoma vartotojo įvesti didžiausią galimą atsitiktinio skaičiaus reikšmę.
    cin >> maksimumas; // įvedama mažiausia galima atsitiktinio skaičiaus reikšmė.
    cout << endl; // padaromas vienos eilutės tarpas.

    skaiciai(kiek, minimumas, maksimumas); // iškviečiama void tipo funkcija „skaiciai“.

    return 0; // programa užbaigta ir įvykdyta sėkmingai.
}

void skaiciai(int kiek, int minimumas, int maksimumas) // void tipo funkcija, pavadinimu „skaiciai“.
{
    setlocale(LC_ALL, "Lithuanian");  // išvedimui naudosime lietuvių kalba.

    srand(time(NULL)); // sukuria seed, kuris bus naudojamas atsitiktinio skaičiaus generavimui.

    for (int i = 0; i < kiek; i++) // kintamasisi i didės vienetu tol, kol bus vienetu mažiau už kintamąjį „kiek“.
    {
        int atsitiktinis = rand() % (maksimumas - minimumas + 1) + minimumas; // sugeneruojamas atsitiktinis skaičius, ribose nuo mažiausios galimos reikšmės iki didžiausios.
        cout << atsitiktinis << ", "; // išvedamas atsitiktinis skaičius.
    }
}
