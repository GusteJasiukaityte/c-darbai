//prijungiame bibliotekas
#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso standartinës funkcijos ir kintamieji.

//duomenų ir rezultatų failų aprašymas
const char duomenu_failas [] = "Rezultatai.txt"; // Duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatų failo vardas.

void lentele(); // programa informuojama apie funkcijos egzistavimą.
void isvedimas (); // programa informuojama apie funkcijos egzistavimą.

int main() // pagrindinė programos funckija.
{
    {
        lentele(); // iškviečiama funkcija.
        isvedimas (); // iškviečiama funkcija.
    }

    return 0;
}

void lentele() // void funkcia pavadinimu „lentele“.
{
    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

        srand(time(NULL)); // sukuria seed, kuris bus naudojamas atsitiktinio skaiciaus generavimui
    int v1 = rand() % 10 + 1; // nuo 1 iki 10.
    int v2 = rand() % 10 + 1; // nuo 1 iki 10.
    int v3 = rand() % 10 + 1; // nuo 1 iki 10.
    int v4 = rand() % 10 + 1; // nuo 1 iki 10.
    int v5 = rand() % 10 + 1; // nuo 1 iki 10.
    int v6 = rand() % 10 + 1; // nuo 1 iki 10.
    int v7 = rand() % 10 + 1; // nuo 1 iki 10.
    int v8 = rand() % 10 + 1; // nuo 1 iki 10.

    ofstream rf (rezultatu_failas);  //failo rašymas

    //į rezultatų failą išvedame atsakymus.
    rf << v1 << "  " << v2 << "  " << v1 + v2 << endl;
    rf << v3 << "  " << v4 << "  " << v3 + v4 << endl;
    rf << v5 << "  " << v6 << "  " << v5 + v6 << endl;
    rf << v7 << "  " << v8 << "  " << v7 + v8 << endl;

    rf.close(); // uždaromas rezultatų failas.

}
void isvedimas () // void funkcija pavadinimu „isvedimas“.
{
    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

    ifstream rf (duomenu_failas); // failo skaitymas.
    if (!rf) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, į konsolę išvedama, jog failo atidaryti nepavyko.
    }
    else
    {
        // kintamieji, skirti nuskaityti duomeis iš duomenų failo.
        int n1, m1 ,l1;
        int n2, m2, l2;
        int n3, m3, l3;
        int n4, m4, l4;

        // iš duomenų failo nuskaitomi duomenys.
        rf >> n1 >> m1 >> l1;
        rf >> n2 >> m2 >> l2;
        rf >> n3 >> m3 >> l3;
        rf >> n4 >> m4 >> l4;

        // į konsolę išvedame rezultatus.
        cout << n1 << "  " << m1 << "  " << l1 << endl;
        cout << n2 << "  " << m2 << "  " << l2 << endl;
        cout << n3 << "  " << m3 << "  " << l3 << endl;
        cout << n4 << "  " << m4 << "  " << l4 << endl;

        rf.close (); // uždaromas duomenų failas.
    }
}
