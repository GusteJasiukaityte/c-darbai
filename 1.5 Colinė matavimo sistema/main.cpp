#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas kaip ifstream ir ofstream.
#include <iomanip> // biblioteka programoje atsakinga už tokias komandas kaip set precision.

using namespace std; // priklauso standartinės funkcijos ir kintamieji.

//duomenų ir rezultatų failų aprašymas
const char duomenu_failas [] = "Duomenys.txt"; // Duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatų failo vardas.

double metrai_coliai(int & metrai) // funkcija, kurioje metrai paverčiami į colius.
{
    return (metrai * 100) / 2.54; // grąžinamas rezultatas coliais.
}

double coliai_pedos(double & coliai) // funkcija, kurioje coliai paverčiami į pėdas.
{
    return coliai / 12; // grąžinamas rezultatas pėdomis.
}

double pedos_jardai ( double & pedos) // funkcija, kurioje pėdos paverčiamos į jardus.
{
    return pedos / 3; // grąžinamas rezultatas jardais.
}

int main() // pagrindinė programos funckija.
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
        int metrai, //kintamasis, rodantis kiek yra metrų.
        n; // kintamasis, nurodantis kiek kartų veiks for ciklas.

        n = 5; // nustatoma n reikšmė.

        ofstream rf (rezultatu_failas); // atidaromas rezultatų failas.

        rf << setw (33) << "Rezultatai" << endl; // į rezultatų failą išvedamas pavadinimas.

        for (int i = 0; i < n; i++) // sąlyga, kad ciklas veiktų tiek kartų, kol i bus vienetu mažiau už n.
        {
            df >> metrai; // iš duomenų failo nuskaitomi metrai.
            double coliai = metrai_coliai(metrai); // coliai lygu metrai_coliai funkcijos rezultatui.
            double pedos = coliai_pedos(coliai); // pedos lygu coliai_pedos funkcijos rezultatui.
            double jardai = pedos_jardai(pedos); // jardai lygu funkcijos pedos_jardai rezultatui.

            // į rezultatų fafilą įvedamos kiekvieno dydžio reikšmės.
            rf << fixed << setprecision(2) << "Metrai: " << metrai << "    Coliai: " << coliai << "    Pedos: " << pedos  << "    Jardai: " << jardai << endl;
        }
        df.close(); // uždaromas duomenų failas.
        rf.close(); // uždaromas rezultatų failas.
    }
    return 0;
}
