//prijungiame bibliotekas
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
    setlocale(LC_ALL, "Lithuanian"); // išvedimui naudojame lietuvių kalbą.

    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolë iðvedama, jog failo atidaryti nepavyko.
    }
    else
    {

        //// įvedami kintamieji.
        int n; // klasės mokinių skaičius.
        df >> n; // nuskaitomas kintamasis n iš duomenų failo.

        int ugiai[max_n]; // mokinių ūgių masyvas.

        int bendrasugism = 0, // bendras merginų ūgis.
        bendrasugisv = 0; // bendras vaikinų ūgis.
        int merginos = 0, //merginų skaičius.
        vaikinai = 0; // vaikinų ūgis.

        //// ūgių skaičiavimai.
        for (int i = 0; i < n; ++i) // ciklas, besitęsiantis iki n - 1.
        {
            df >> ugiai[i]; // duomenų failas nuskaito ūgių masyvą.
            if (ugiai[i] > 0) // jeigų ūgių masyvas didesnis už 0.
            {
                bendrasugism += ugiai[i]; // bendras merginų ūgis = bendras merginų ūgis + ūgio masyvas.
                merginos++; // merginų skaičius didėja vienetu.
            }
            else
            {
                bendrasugisv += ugiai[i]; // bendras vaikinų ūgis = bendras vaikinų ūgis + ūgio masyvas.
                vaikinai++; // vaikinų skaičius didėja vienetu.
            }
        }

        ////kintamųjų įvedimas.
        double vidurkism = 0; // merginų vidurkio kintamasis.
        double vidurkisv = 0; // vaikinų vidurkio kintamasis.


        ////vidrukių skaičiavimas.
        if (merginos > 0) // jeigu merginų skaičius didesnis už 0.
        {
            vidurkism = double (bendrasugism) / merginos; // merginų vidurkio skaičiavimas.
        }

        if (vaikinai > 0) // jeigu vaikinų skaičius didesnis už 0.
        {
            vidurkisv = double (bendrasugisv) / vaikinai; // vaikinų vidurkio skaičiavimas.
        }


        ////rezultatai įrašomi į rezultatų failą.
        ofstream rf(rezultatu_failas); // atidaromas rezultatų failas.

        rf << fixed << setprecision(2) << "V klasės mokinių vidutinis ūgis: " << vidurkism << " cm" << endl; // įrašomas mokinių vidutinis ūgis.
        rf << fixed << setprecision(2) << "V klasės merginų vidutinis ūgis: " << vidurkism << " cm" << endl; // įrašomas vidutinis merginų ūgis.
        rf << fixed << setprecision(2) << "V klasės vaikinų vidutinis ūgis: " << vidurkisv << " cm" << endl; // įrašomas vidutinis vaikinų ūgis.

        ////merginų komandos sudarymas.
        rf << fixed << setprecision(2) << "Merginų komanda: "; // į rezultatų failą įrašomas tekstas.

        if (vidurkism > 175 && merginos >= 5 && vaikinai >= 2) // jei vidurkis didesnis už 175 ir yra bent 5 merginos bei 2 vaikinai.
        {
            rf << "Sudaryti galima" << endl; // komandą sudaryti galima.
        }
        else
        {
            rf << "Sudaryti negalima" << endl; // komandos sudaryti negalima.
        }


        rf << fixed << setprecision(2) << "Vaikinų komanda: "; // į rezultatų failą įrašomas tekstas.

        if (vidurkisv > 175 && vaikinai >= 5 && merginos >= 2) // jei vidurkis didesnis už 175 ir yra bent 5 vaikinai bei 2 merginos.
        {
            rf << "Sudaryti galima" << endl; // komandą sudaryti galima.
        }
        else
        {
            rf << "Sudaryti negalima" << endl;// komandos sudaryti negalima.
        }


        df.close(); // uždaromas duomenų failas.
        rf.close(); // uždaromas rezultatų failas.
        }

    return 0; // programa užbaigta ir įvykdyta sėkmingai.
}
