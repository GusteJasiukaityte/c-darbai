#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso standartinës funkcijos ir kintamieji.

//duomenų ir rezultatų failų aprašymas.
const char duomenu_failas [] = "technika.txt"; // duomenų failo vardas.
const char rezultatu_failas [] = "pagaminta.txt"; // rezultatų failo vardas.

int main() // pagrindinë programos funkcija.
{
    int n, // duomenų eilučių skaičius.
    gn, // gaminio numeris
    gs, // pagamintų gaminių skaičius
    s, // kiekvieno gaminio savikaina.
    pjaustykliu_suma = 0, // nustatoma pjaustyklių sumos vertė - 0.
    virduliu_suma = 0, // nustatoma virdulių sumos vertė - 0.
    mikseriu_suma = 0, // nustatoma mikserių sumos vertė - 0.
    plaktuviu_suma = 0; // nustatoma plaktuvių sumos vertė - 0.

    setlocale (LC_ALL, "Lithuanian"); // iðvedimui naudojame lietuviø kalbà.

    ifstream df (duomenu_failas); // duomenų failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, į konsolę išvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        df >> n; // nuskaitome duomenų eilučių skaičių.

        ofstream rf(rezultatu_failas);

        for ( int i = 0; i < n; i++) //ciklas yra vykdomas n kartų.
        {
            gn = 0; // gaminio numeris nustatomas lygus 0.
            gs = 0; // gaminių skaičius nustatomas lygus 0.

            df >> gn >> gs; // nuskaitome gaminio numerį ir pagamintų gaminių skaičių.

                for ( int j = 0; j < gs; j++) // ciklas vykdomas tiek, kol j bus vienetų mažiau už gs.
                {
                    df >> s; // nuskaitoma gaminių savikaina.

                    if ( gn == 1 ) // sąlyga, jeigu gaminio numeris yra 1.
                    {
                        pjaustykliu_suma += s; // pjaustykliu savikainų suma. pjaustykliu_suma = pjaustykliu_suma + s.
                    }
                    else if ( gn == 2) // sąlyga, jeigu gaminio numeris yra 2.
                    {
                        virduliu_suma += s; // virdulių savikainų suma. virduliu_suma = virduliu_suma + s.
                    }
                    else if ( gn == 3 ) // sąlyga, jeigu gaminio numeris yra 3.
                    {
                        mikseriu_suma += s; // mikserių savikainų suma. mikseriu_suma = mikseriu_suma + s.
                    }
                    else if ( gn == 4 ) // sąlyga, jeigu gaminio numeris yra 4.
                    {
                        plaktuviu_suma += s; // plaktuvių savikainų suma. plaktuvių_suma = plaktuviu_suma + s.
                    }
                }
            }

        rf << "Pjaustyklių: " << pjaustykliu_suma << " Eur." << endl; // į rezultatų failą išvedama pjaustyklių suma eurais.
        rf << "Virdulių: " << virduliu_suma << " Eur." << endl; // į rezultatų failą išvedama virdulių suma eurais.
        rf << "Mikserių: " << mikseriu_suma << " Eur." << endl; // į rezultatų failą išvedama mikserių suma eurais.
        rf << "Plaktuvių: " << plaktuviu_suma << " Eur." << endl; // į rezultatų failą išvedama plaktuvių suma eurais.

        df.close(); // uždarome duomenų failą.
        rf.close(); // uždarome rezultatų failą.
    }

    return 0;
}
