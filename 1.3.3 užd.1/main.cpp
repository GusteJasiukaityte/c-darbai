// Prijungiiame bibliotekas.
#include <iostream> // biblioteka atsakinga uþ komandas cout ir cin.
#include <fstream> // biblioteka atsakinga uþ komandas ifstream ir ofstream.

using namespace std; // priklauso standartinës funkcijos ir kintamieji.

void duomenys (string vardas, string pavarde, int amzius, string profesija); // programai praneðama apie funkcijos egzistavimà.

int main() // pagrindinë programos funkcija.
{
    setlocale(LC_ALL, "Lithuanian");  // iðvedimui naudosime lietuviø kalbà.

    duomenys ("Petras",  "Petraitis", 26, "ugniagesys"); // iðkvieèiama funkcija „duomenys“.
    duomenys ("Matas",  "Matulionis", 30, "inþinierius"); // iðkvieèima funkcija „duomenys“.

    return 0; //programa uþbaigta ir ávykdyta sëkmingai.
}

void duomenys (string vardas, string pavarde, int amzius, string profesija) // void tipo funkcija, pavadinimu „duomenys“.
{
    cout << vardas << " " << pavarde << ", " << amzius << " metø, yra " << profesija << "." << endl; // á konsolæ iðvedamas atsakymas.
}
