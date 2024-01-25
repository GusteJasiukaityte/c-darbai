////prijungiame bibliotekas
#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.

using namespace std; // reikalinga, kad galėtume naudoti cout, cin, endl, ifstream bei ofstream.

//// duomenų ir rezultatų failų aprašymas.
const char duomenu_failas[] = "Duomenys.txt"; // duomenų failo vardas.
const char rezultatu_failas[] = "Rezultatai.txt"; // rezultatų failo vardas.
const int max_n = 30; // nustatomas maksimalus mokinių skaičius.

int main() // pagrindinė programos funkcija.
{

    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolë iðvedama, jog failo atidaryti nepavyko.
    }
    else
    {
        setlocale(LC_ALL, "Lithuanian"); // išvedimui naudojame lietuvių kalbą.

        //// kintamųjų įvedimas.
        int n; // įvedamas kintamasis, reiškiantis klasės mokinių skaičių.

        df >> n; // nuskaitomas kintamasis n iš duomenų failo.

        int knygos[n]; // masyvas, skirtas perskaitytoms knygoms.
        int suma = 0; // visų mokinių perskaitytų knygų suma.

        //// skaičiuojaas bendras visų perskaitytų knygų kiekis.
        for (int i = 0; i < n; i++) // ciklas, besikartojantis iki n - 1.
        {
            int kiek; // kintamasis, kuriame saugoma kiekvieno mokinio perskaitytų knygų suma.

            df >> kiek; // nuskaitomas kintamasis n iš duomenų failo.

            suma += kiek; // visų mokinių perskaitytų knygų suma.
            knygos[i] = kiek; // masyvas knygos[i] lygus knygų skaičiui.

        }

        ////skaičiavimai.
        double vid_metai = suma / n; //skaičiuojama kiek vidutiniškai per mokslo metus perskaitė vienas mokinys.
        double vid_menesis = vid_metai / 10; // skaičiuojama, kiek vidutiniškai per mėnesį perskaito vienas mokinys.

        df.close(); // uždaromas duomenų failas.

        //// Įrašomas rezultatas į duomenų faila.
        ofstream rf (rezultatu_failas); // atidaromas rezultatų failas.

        rf << "Per mokslo metus mokiniai perskaitė knygų: " << suma << endl; // išvedama suma.
        rf << "Per mokslo metus mokinys vidutiniškai perskaitė: " << fixed << setprecision(0) << vid_metai << endl; // išvedamas metų vidurkis.
        rf << "Per mėnesį mokinys vidutiniškai perskaitė: " << fixed << setprecision(1) << vid_menesis << endl; // išvedamas mėnesio vidurkis.

        rf.close(); // uždaromas rezultatų failas.

        return 0; // programa užbaigta ir įvykdyta sėkmingai.
    }
}
