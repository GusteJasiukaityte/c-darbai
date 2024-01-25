//prijungiame bibliotekas.
#include <iostream> // biblioteka atsakinga už komandas cout ir cin.
#include <fstream> // biblioteka atsakinga už komandas ifstream ir ofstream.

using namespace std; // priklauso standartinės funkcijos ir kintamieji.

void skaiciai(int pirmas, int antras); // programai pranešama apie funkcijos egzistavimą.

int main() // pagrindinė programos funkcija.
{
    int pirmas, // pirmo įvesto skaičiaus kintamasis.
    antras; // antro įvesto skaičiaus kintamasis.

    setlocale(LC_ALL, "Lithuanian");  //išvedimui naudosime lietuvių kalbą

    cout << "Įveskite du skaičius: " << endl; // prašoma vartotojo įvesti du skaičius.
    cin >> pirmas; // įvedamas pirmas skaičius.
    cin >> antras; // įvedamas antras skaičius.
    cout << endl; // tarp rezultato ir įvedamų skaičių padaromas vienos eilutės tarpas.

    skaiciai(pirmas, antras); // iškviečiama void tipo funkcija „skaiciai“.

    return 0; // rprograma užbaigta ir įvykdyta sėkmingai.
}

void skaiciai(int pirmas, int antras) // void tipo funkcija, pavadinimu „skaiciai“.
{
    if (pirmas > antras) // sąlyga, ar pirmas yra didesnis už antrą.
    {
        cout << pirmas; // jeigu sąlyga patenkinama, tai išvedamas pirmas skaičius.
    }
    else if  (pirmas < antras) // sąlyga, ar pirmas yra mažesnis už antrą.
    {
        cout << antras; // jeigu sąlyga patenkinama, tai išvedamas antras skaičius.
    }
    else if (pirmas == antras) // sąlyga, ar pirmas yra lygus antram.
    {
        cout << "Skaičiai lygūs."; // jeigu sąlyga patenkinama, išvedama, jog skaičiai yra lygūs.
    }
}
