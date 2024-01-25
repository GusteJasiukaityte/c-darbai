//prijungiame bibliotekas.
#include <iostream> // biblioteka atsakinga uþ komandas cout ir cin.
#include <fstream> // biblioteka atsakinga uþ komandas ifstream ir ofstream.
#include <time.h> // biblioteka, ðioje programoje naudojama atsitiktinio skaièiaus generavimui.

using namespace std; // priklauso standartinës funkcijos ir kintamieji.

void skaicius(int kiekis); // programai praneðama apie funkcijos egzistavimà.

int main() // pagrindinë programos funkcija.
{
    int kiekis; // kintamasis, nurodantis, kiek atsitiktiniø skaièiø reikia sugeneruoti.

    setlocale(LC_ALL, "Lithuanian");  // iðvedimui naudosime lietuviø kalbà

    cout << "Áveskite skaièiø: " << endl; // praðoma vartotojo ávesti skaièiø.
    cin >> kiekis; // ávedamas skaièius nurodantis, kiek atsitiktiniø skaièiø reikia sugeneruoti.
    cout << endl; // tarp rezultato ir ávedamø skaièiø padaromas vienos eilutës tarpas.

    skaicius(kiekis); // iðkvieèiama void tipo funkcija „skaicius“.

    return 0; // programa uþbaigta ir ávykdyta sëkmingai.
}

void skaicius(int kiekis) // void tipo funkcija, pavadinimu „skaicius“.
{
    setlocale(LC_ALL, "Lithuanian");  // iðvedimui naudosime lietuviø kalbà.

    srand(time(NULL)); // sukuria seed, kuris bus naudojamas atsitiktinio skaièiaus generavimui

    for (int i = 0; i < kiekis; i++) // kintamasisi i didës vienetu tol, kol bus vienetu maþiau uþ kieká.
    {
        int atsitiktinis = rand() % 100 + 1; // sugeneruojamas atsitiktinis skaièius.
        cout << atsitiktinis << " "; // iðvedamas atsitiktinis skaièius.
    }
}
