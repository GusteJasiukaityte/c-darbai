#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas kaip ifstream ir ofstream.

using namespace std; // priklauso standartinės funkcijos ir kintamieji.

//duomenų ir rezultatų failų aprašymas
const char duomenu_failas [] = "Duomenys.txt"; // Duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatų failo vardas.

void indai(int & sulciu_kiekis, int & penki, int & du, int & vienas) // funkcija, kuri skaičiuoja kiek ir kokių sulčių talpų reikės.
{
    penki = sulciu_kiekis / 5; // skaičiuojame, kiek reikės 5 litrų talpos indų.
    sulciu_kiekis %= 5; // skaičiuojame, kiek litrų sulčių liks, sultis supylus į 5 litrų talpos indus.

    du = sulciu_kiekis / 2; // skaičiuojame, kiek reikės 2 litrų talpos indų.
    sulciu_kiekis %= 2; // skaičiuojame, kiek litrų sulčių liks, sultis supylus į 2 litrų talpos indus.

    vienas = sulciu_kiekis; // skaičiuojame, kiek vieno litro talpų reikės likusiam sulčių kiekiui.
}

int main() // pagrindinė programos funkcija.
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

        int n; // įvedamas kintamasis n, kuris nurodo ūkininkų skaičių.
        df >> n; // nuskaitomas ūkininkų skaičius duomenų faile.

        for (int i = 0; i < n; ++i) // sąlyga, kad ciklas kartosis tol, kol i bus vienetu mažesnis už n.
        {
            int sulciu_kiekis; // įvedamas kintamasis, nurodantis sulčių kiekį.
            df >> sulciu_kiekis; // nuskaitomas obuolių sulčių kiekis duomenų faile.

            // nustatoma, jog reikalingas kiekvienos talpos kiekis yra lygus 0.
            int penki = 0,
            du = 0,
            vienas = 0;

            indai(sulciu_kiekis, penki, du, vienas); // iškviečiama indai funkcija, kuri apskaičiuoja kiek ir kokių reikės indų.

            rf << penki << " " << du << " " << vienas << endl; // gautus rezultatus įrašome į rezultatų failą.
        }
        df.close(); // uždaromas duomenų failas.
        rf.close(); // uždaromas rezultatų failas.
    }
    return 0;
}
