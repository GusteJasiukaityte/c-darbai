#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cin ir cout.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas kaip ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso stndartinės funkcijos ir kintamieji.

// duomenų ir rezultatų failų aprašymas.
const char duomenu_failas [] = "Duomenys.txt"; // duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // rezultatų failo vardas.

int main() // pagrindinė programos funkcija.
{

    int visos_rankos, // visos planetoje gyenančių būtybių rankos.
    visos_kojos, // visos planetoje gyenančių būtybių kojos.
    visos_akys, // visos planetoje gyenančių būtybių akys.
    guciku_rankos, // visos gucikų rankos.
    guciku_kojos, // visos gucikų kojos.
    guciku_akys, // visos gucikų akys.
    muciku_rankos, // visos mucikų rankos.
    muciku_kojos, // visos mucikų kojos.
    muciku_akys, // visos mucikų akys.
    fuciku_rankos, // visos fucikų rankos.
    fuciku_kojos, // visos fucikų kojos.
    fuciku_akys; // visos mucikų akys.

    setlocale (LC_ALL, "Lithuanian"); // išvedimui naudojame lietuvių kalba.

    ifstream df (duomenu_failas); // duomenų failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas" << endl; // jeigu failas neatsidaro, į konsolę išvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        df >> visos_rankos >> visos_kojos >> visos_akys; // duomenų failas nuskaito kintamuosius visos_rankos, visos_kojos ir visos_akys.

        df >> guciku_rankos >> guciku_kojos >> guciku_akys; // duomenų failas nuskaito kintamuosius guciku_rankos, guciku_kojos ir guciku_akys.
        df >> muciku_rankos >> muciku_kojos >> muciku_akys; // duomenų failas nuskaito kintamuosius muciku_rankos, muciku_kojos ir muciku_akys;.
        df >> fuciku_rankos >> fuciku_kojos >> fuciku_akys; // duomenų failas nuskaito kintamuosius fuciku_rankos, fuciku_kojos ir fuciku_akys.

        df.close(); // uždarome duomenų failą.

        ofstream rf (rezultatu_failas); // failo rašymas

        int guciku_skaicius = 0, // planetoje gyvenančių gucikų skaičius.
        muciku_skaicius = 0, // planetoje gyvenančių mucikų skaičius.
        fuciku_skaicius = 0; // planetoje gyvenančių fucikų skaičius.

        for (int gucikai = 0; gucikai <= 500; gucikai++) // gucikų skaičius didėja vienu vienetu tol, kol jis yra lygus 500.
        {
            for (int mucikai = 0; mucikai <= 500; mucikai++) // mucikų skaičius didėja vienu vienetu tol, kol jis yra lygus 500.
            {
                for (int fucikai = 0; fucikai <= 500; fucikai++) // fucikų skaičius didėja vienu vienetu tol, kol jis yra lygus 500.
                {
                    // Tikriname, ar visų būtybių turimas rankų, kojų ir akių skaičius atitinka bendrus rankų, kojų ir akių skaičius planetoje.
                    if (gucikai * guciku_rankos + mucikai * muciku_rankos + fucikai * fuciku_rankos == visos_rankos &&
                        gucikai * guciku_kojos + mucikai * muciku_kojos + fucikai * fuciku_kojos == visos_kojos &&
                        gucikai * guciku_akys + mucikai * muciku_akys + fucikai * fuciku_akys == visos_akys)
                    {
                        guciku_skaicius = gucikai; // gucikų skaičius yra lygus gucikams, tai nurodo kiek gucikų yra planetoje.
                        muciku_skaicius = mucikai;// mucikų skaičius yra lygus mucikams, tai nurodo kiek mucikų yra planetoje.
                        fuciku_skaicius = fucikai;// fucikų skaičius yra lygus fucikams, tai nurodo kiek fucikų yra planetoje.
                    }
                }
            }
        }

        rf << guciku_skaicius << " " << muciku_skaicius << " " << fuciku_skaicius << endl; // į rezultatų failą įvedame rezultatus: gucikų, mucikų ir fucikų skaičių.

        rf.close(); // uždarome rezultatų failą.
    }

    return 0;
}
