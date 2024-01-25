//prijungiame bibliotekas
#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.

using namespace std; // reikalinga, kad galėtume naudoti cout, cin, endl, ifstream bei ofstream.


//// duomenų ir rezultatų failų aprašymas.
const char duomenu_failas[] = "Duomenys.txt"; // duomenų failo vardas.
const char rezultatu_failas[] = "Rezultatai.txt"; // rezultatų failo vardas.
const int max_n = 500; // nustatomas maksimalus namų skaičius.

int main() // pagrindinė programos funkcija.
{
    setlocale(LC_ALL, "Lithuanian"); // išvedimui naudojame lietuvių kalbą.

    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolë iðvedama, jog failo atidaryti nepavyko.
    }
    else
    {

        //// kintamųjų įvedimas.
        int n; // įvedamas kintamasis, reiškiantis namų skaičių gatvėje.
        df >> n; // nuskaitomas kintamasis n iš duomenų failo.

        int gyventojai[n]; // masyvas, skirtas gyventojų skaičiui visuose namuose.

        int sumags = 0; // visų gyventojų suma.
        int suma_kaire = 0; // kairės gatvės pusės gyventojų suma.
        int suma_desine = 0; // Dešinės gatvės pusės gyventojų suma.


        //// skaičiuojamas bendras, kairės pusės ir dešinės pusės namų gyventojų skaičius.
        for (int i = 0; i < n; i++) // ciklas, besikartojantis iki n - 1.
        {
            int nm, // namo numerio kintamasis.
            gs; // gyventojų skaičiaus kintamasis.

            df >> nm >> gs; // nuskaitomas kintamieji nm ir gs iš duomenų failo.

            sumags += gs; // gyventojų skaičiaus suma lygi sumags + gyventojų skaičius.
            gyventojai[i] = gs; // masyvas gyventojai[i] lygus gyventojų skaičiui.

            // skaičiuojami kiekvienos pusės gyventojai.
            if (nm % 2 == 0) // sąlyga, ar namo numeris yra lyginis.
            {
                suma_desine += gs; // dešinės pusės namų gyvetojų suma lygi suma_desine + gyventojų skaičius.
            }
            else // sąlyga, jeigu namo numeris yra ne lyginis.
            {
                suma_kaire += gs; // kairės pusės namų gyventojų suma lygi suma_kaire + gyventojų skaičius.
            }
        }

        df.close(); // uždaromas duomenų failas.

        // skaičiuojame vidutinį gyventojų skaičių kiekvienoje gatvės pusėje.
        double vid_kaire = (double) suma_kaire / 5; // skaičiuojame vidutinį gyventojų skaičių kairėje gatvės pusėje.
        double vid_desine = (double) suma_desine / 5;  // skaičiuojame vidutinį gyventojų skaičių dešinėjė gatvės pusėje.

        // išvedame rezultatus į rezultatų failą.
        ofstream rf(rezultatu_failas); // atidarome rezultatų failą.

        rf << "Iš viso gyventojų gatvėje: " << fixed << setprecision(2) << sumags << endl; // į rezultatų failą išvedama bendra gyventojų suma.
        rf << "Kairiosios gatvės pusėje gyvena: " << fixed << setprecision(2) << suma_kaire << " gyventojai" << endl; // į rezultatų failą išvedama kairėje pusėje gyvenančių gyventojų suma.
        rf << "Dešiniosios gatvės pusėje gyvena: " << fixed << setprecision(2) << suma_desine << " gyventojai" << endl; // į rezultatų failą išvedama dešinėje pusėje gyvenančių gyventojų suma.
        rf << "Vidutiniškai kairiosios gatvės pusėje gyvena: " << fixed << setprecision(2) << vid_kaire << " gyventojai" << endl; // į rezultatų failą išvedamas vidutinis gyventojų skaičius kairėje gatvės pusėje.
        rf << "Vidutiniškai dešiniosios gatvės pusėje gyvena: " << fixed << setprecision(2) << vid_desine << " gyventojai" << endl; // į rezultatų failą išvedamas vidutinis gyventojų skaičius dešinėjė gatvės pusėje.

        rf.close(); // uždaromas rezultatų failas.

        return 0; // programa užbaigta ir įvykdyta sėkmingai.
    }
}
