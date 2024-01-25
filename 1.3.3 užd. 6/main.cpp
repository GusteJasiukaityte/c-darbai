//prijungiame bibliotekas.
#include <iostream> // biblioteka atsakinga u� komandas cout ir cin.
#include <fstream> // biblioteka atsakinga u� komandas ifstream ir ofstream.
#include <time.h> // biblioteka, �ioje programoje naudojama atsitiktinio skai�iaus generavimui.

using namespace std; // priklauso standartin�s funkcijos ir kintamieji.

void skaicius(int kiekis); // programai prane�ama apie funkcijos egzistavim�.

int main() // pagrindin� programos funkcija.
{
    int kiekis; // kintamasis, nurodantis, kiek atsitiktini� skai�i� reikia sugeneruoti.

    setlocale(LC_ALL, "Lithuanian");  // i�vedimui naudosime lietuvi� kalb�

    cout << "�veskite skai�i�: " << endl; // pra�oma vartotojo �vesti skai�i�.
    cin >> kiekis; // �vedamas skai�ius nurodantis, kiek atsitiktini� skai�i� reikia sugeneruoti.
    cout << endl; // tarp rezultato ir �vedam� skai�i� padaromas vienos eilut�s tarpas.

    skaicius(kiekis); // i�kvie�iama void tipo funkcija �skaicius�.

    return 0; // programa u�baigta ir �vykdyta s�kmingai.
}

void skaicius(int kiekis) // void tipo funkcija, pavadinimu �skaicius�.
{
    setlocale(LC_ALL, "Lithuanian");  // i�vedimui naudosime lietuvi� kalb�.

    srand(time(NULL)); // sukuria seed, kuris bus naudojamas atsitiktinio skai�iaus generavimui

    for (int i = 0; i < kiekis; i++) // kintamasisi i did�s vienetu tol, kol bus vienetu ma�iau u� kiek�.
    {
        int atsitiktinis = rand() % 100 + 1; // sugeneruojamas atsitiktinis skai�ius.
        cout << atsitiktinis << " "; // i�vedamas atsitiktinis skai�ius.
    }
}
