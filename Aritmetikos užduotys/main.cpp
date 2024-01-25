//prijungiame bibliotekas
#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso standartinės funkcijos ir kintamieji.

//duomenų ir rezultatų failų prašymas
const char duomenu_failas [] = "Duomenys.txt"; // Duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Duomenų failo vardas.

int main() // pagrindinė prorgramos funkcija.
{
    int x1, // pirmas sveikasis skaičius.
    x2; // antras sveikasis skaičius.

    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df)
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, į konsolė išvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        df >> x1 >> x2; // nuskaitome kintamuosius x1 ir x2.
        df.close(); // uždarome duomenų failą.

        ofstream rf (rezultatu_failas);

        for( int i = x1; i <= x2; i++ ) // kintamasis "i" yra lygus kintamajam x1, kintamasis "i" didėja vienu vienetu tol, kol "i" yra lygu kintamajam x2.
        {

            for ( int j = x2; j >= x1; j--) // kintamasis "j" yra lygus x2, kintamasis "j" mažėjo vienu vienetu tol, kol "j" yra lygus x1.
            {

                if (i % j == 0) // jeigu "i" padalinus iš "j" liekana yra 0, tai ciklas yra tesiamas.
                {

                    if ( i != j ) // jeigu "i" yra nelygu "j", tai ciklas yra tesiamas.
                    {
                        rf << i << "+" << j << "=" << i + j << endl; // "i" ir "j" sudėties rezultatą išvedame į rezultatų failą.
                        rf << i << "-" << j << "=" << i - j << endl; // "i" ir "j" atimties rezultatą išvedame į rezultatų failą.
                        rf << i << "*" << j << "=" << i * j << endl; // "i" ir "j" sandaugą išvedame į rezultatų failą.
                        rf << i << "/" << j << "=" << i / j << endl; // "i" ir "j" dalybos rezultatą rezultatą išvedame į rezultatų failą.
                        rf << "****************" << endl; // atskiriame aritmetinius veiksmus žvaigždutėmis.
                    }
                }
            }
        }

    rf.close(); // uždarome rezultatų failą.

    }

    return 0;
}


