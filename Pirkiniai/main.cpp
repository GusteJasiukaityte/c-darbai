#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso standartinės funkcijos ir kintamieji.

//duomenų ir rezultatų failų aprašymas.
const char duomenu_failas [] = "Pirkiniai.txt"; // duomenų failo vardas.
const char rezultatu_failas [] = "Išlaidos.txt"; // rezultatų failo vardas.

int main() // pagrindinė programos funkcija.
{
    int n, // aplankytų parduotuvių kiekis.
    m; // įsigytų prekių kiekis.
    double kaina, // kintamasis, naudojamas programoje saugoti prekės kainą.
    bendra_suma = 0.0; //visa parduotuvėse išleista pinigų suma.


    setlocale (LC_ALL, "Lithuanian"); // išvedimui naudojame lietuvių kalbą.

    ifstream df (duomenu_failas); // duomenų failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, į konsolę išvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        df >> n >> m; // nuskaitome kintamuosius n ir m.

        ofstream rf(rezultatu_failas);

        for ( int i = 0; i < n; i++) //kintamasis "i" vienu vienetu didės tol, kol jis bus vienu vienetu mažesnis už kintamąjį "n".
        {
            double parduotuves_islaidos = 0.0; // kintamasis, kuriame sudėsime parduotuvėje išleistą pinigų sumą.

            for ( int j = 0; j < m; j++) // kintamasis "j" didės vienu vienetu tol, kol jis bus vienu vienetu mažesnis už kintamąjį "m".
            {
                df >> kaina; // duomenų failas nuskaito kintamąjį "kaina".
                parduotuves_islaidos += kaina; // parduotuves_islaidos = parduotuves islaidos + kaina, gauname vienoje parduotuvėje išleistą pinigų sumą.
            }

            bendra_suma += parduotuves_islaidos; // bendra_suma = bendra_suma + parduotuves_islaidos, gauname bendrą išleistą pinigų sumą visose parudotuvėse.

            rf << i + 1 << "  " << fixed << setprecision (2) << parduotuves_islaidos << " Eur." << endl; // į rezultatų failą įrašomas parduotuvės numeris ir toje parduotuvėje išleista pinigų suma (2 skaičiai po kablelio).
        }
        rf << endl; // rezultatų faile padaromas eilutės tarpas tarp kiekvienoje parduotuvėje išleistų pinigų sumų ir bendrai visose parduotuvėse išleistos pinigų sumos.
        rf << "Viso išleista: " << fixed << setprecision(2) << bendra_suma << " Eur." << endl; // į rezultatų failą irašoma visose parduotuvėse išleista pinigų suma (2 skaičiai po kablelio).

    df.close(); // uždarome duomenų failą.
    rf.close(); // uždarome rezultatų failą.

    }
    return 0;
}
