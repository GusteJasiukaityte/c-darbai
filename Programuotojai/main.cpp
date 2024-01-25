#include <iostream> // biblioteka programoje atsakinga uþ tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga uþ tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandà.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso standartinës funkcijos ir kintamieji.

//duomenų ir rezultatų failų aprašymas.
const char duomenu_failas [] = "Programuotojai.txt"; // duomenų failo vardas.
const char rezultatu_failas [] = "Išspręsta.txt"; // rezultatų failo vardas.

int main() // pagrindinë programos funkcija.
{
    int n, // varžybose dalyvavusių programuotojų skaičius.
    uzd_sk = 0, // skaičius, kiek uždavinių programuotojas išsprendė kiekvieną dieną.
    dienu_sk = 0, // visų dienų, kai buvo rašomos programos, skaičius.
    p, // per dieną išspręstų uždavinių skaičius.
    ds, // skaičius dienų, kiek dalyvavo maratone.
    suma; // visų parašytų programų skaičius.
    double vidut; // skaičius, kiek uždavinių vidutiniškai išspręsta per dieną.

    setlocale(LC_ALL, "Lithuanian"); // išvedimui naudojame lietuvių kalbą.

    ifstream df (duomenu_failas); // duomenų failo skaitymas.
    if (!df)  // Patikra.
    {
        cout << "Failas neatidarytas" << endl; // jeigu failas neatsidaro, į konsolę išvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        ofstream rf(rezultatu_failas); //failo rašymas.

        df >> n; // nuskaitomas varžybose dalyvavusių programuotojų skaičius.

        for (int i = 1; i <= n; i++) // ciklas kartojamas n kartų.
        {
            suma = 0; // nusatoma sumo vertė (0).

            df >> ds; // nuskaitomas skaičius dienų, kiek dalyvavo maratone.

            for (int j = 0; j < ds; j++) // ciklas kartojamas ds kartų.
            {
                df >> p; // nuskaitomas per dieną išspręstų uždavinių skaičius.

                suma += p; // gaunamas visų parašytų programų skaičius. suma = suma + p.
            }

            rf << i << " programuotojas " << suma << endl; // į rezultatų failą išvedama suma.

            dienu_sk += ds; // gaunamas visų dienų, kai buvo rašomos programos, skaičius. dienu_sk = dienu_sk + ds.

            uzd_sk += suma; // gaunamas skaičius, kiek uždavinių programuotojas išsprendė kiekvieną dieną. uzd_sk = uzd_sk +suma.
        }

    rf << "Viso išspręsta " << uzd_sk << endl; // į rezultatų failą išvedame skaičių, kiek uždavinių programuotojas išsprendė kiekvieną dieną.

    vidut = (double) uzd_sk / dienu_sk; // gaunama kiek vidutiniškai uždavinių išspręsta per dieną.

    rf << "Vidutiniškai 1 išsprendė " << fixed << setprecision (1) << vidut << endl; // į rezultatų failą išvedamas skaičius, kiek uždavinių vidutiniškai išspręsta per dieną, su 1 skaičiumi po kablelio.


    df.close(); // uždarome duomenų failą.
    rf.close(); // uždarome rezultatų failą.

    return 0;
  }

}
