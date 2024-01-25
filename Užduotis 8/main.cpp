//prijungiame bibliotekas
#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso standartinës funkcijos ir kintamieji.

//duomenų ir rezultatų failų aprašymas
const char duomenu_failas [] = "Rezultatai.txt"; // Duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatų failo vardas.

void atsitiktinis(); // programa informuojama apie funkcijos egzistavimą.
void isvedimas(); // programa informuojama apie funkcijos egzistavimą.
void valymas(); // programa informuojama apie funkcijos egzistavimą.

int main() // pagrindinė programos funckija.
{
    {
        atsitiktinis(); // iškviečiama funkcija.
        isvedimas(); // iškviečiama funkcija.
        valymas(); // iškviečiama funkcija.
    }

    return 0;
}

void atsitiktinis() // void funkcia pavadinimu „atsitiktinis“.
{
    int n = 100; // kintamasis n = 100.

    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

    ofstream rf (rezultatu_failas);  //failo rašymas

    srand(time(NULL)); // sukuria seed, kuris bus naudojamas atsitiktinio skaiciaus generavimui

    for(int i = 0; i < n; i++) // ciklas, skirtas gauti šimtą atsitiktinių skaičių.
    {
        int v1 = rand() % 10 + 1; // nuo 1 iki 10.

        // į rezultatų failą išvedame atsakymus.
        rf << v1 << "  ";
    }
    rf.close(); // uždaromas rezultatų failas.
}
void isvedimas() // void funkcia pavadinimu „isvedimas“.
{
    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

    ifstream rf (duomenu_failas); // failo skaitymas.
    if (!rf) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, į konsolę išvedama, jog failo atidaryti nepavyko.
    }
    else
    {
        int n = 100; // kintamasis n = 100.
        int m; // kintamasis, skirtas nuskaityti duomenis iš duomenų failo.

        // ciklas, skirtas gauti šimtą atsitiktinių skaičių.
        for(int i = 0; i < n; i++) // ciklas, skirtas gauti šimtą atsitiktinių skaičių.
        {
        rf >> m; // iš duomenų failo nuskaitomi duomenys.
        cout << m << " "; // į konsolę išvedamas rezultatas.
        }

        rf.close (); // uždaromas duomenų failas.
    }
}
void valymas() // void funkcia pavadinimu „valymas“.
{
    cout << endl; // tekstas bus spausdinamas iš naujos eilutės.
    cout << "Ar reikia isvalyti duomenu faila? (t/n)" << endl; // klausiama, ar reikia išvalyti duomenų failą.
    char isvalyti;
    cin >> isvalyti;


    if (isvalyti == 't') // išvalyti duomenų failą.
    {
        // duomenų failo išvalymas.
        ofstream rf (rezultatu_failas); // atidaromas duomenų failas
        rf.close (); // uždaromas duomenų failas
        cout << "Duomenu failas isvalytas."; // pranešama, jog duomenų failas išvalytas.
    }
    else
    {
        cout << "Duomenu failas neisvalytas."; // pranešama, jog duomenų failas neišvalytas.
    }
}
