//prijungiame bibliotekas
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//duomen� ir rezultat� fail� apra�ymas.
const char duomenu_failas [] = "Duomenys.txt";
const char rezultatu_failas [] = "Rezultatai.txt";

int main ()
{
    int n, // dien� skai�ius.
    suma = 0, // minu�i�, kiek dresavo katin�, suma.
    vid, // kiek vidutini�kai minu�i� per diena buvo dresuojamas katinas.
    t; // kintamasis, naudojamas gauti sum�.

    setlocale(LC_ALL, "Lithuanian");

    ifstream df (duomenu_failas);
    if (!df)
    {
        cout << "Failas neatidarytas" << endl; // jeigu failas neatsidaro.

        return -1;
    }
    else
    {
        df >> n; // duomen� fail� nukreipiame � kintam�j� n.

        for ( int i = 0; i < n; i++)
        {
            df >> t; // duomen� fail� nukreipiame � kintam�j� t.
            suma += t; // suma = suma + t.
            vid = suma / n; // suma padalijama i� dien� skai�iaus.
        }
        df.close(); // u�darome duomen� fail�.

        ofstream rf (rezultatu_failas);
        rf << suma << endl; // � rezultat� fail� i�vedame sum�.
        rf << vid << endl; // � rezultat� fail� i�vedame vidutin� minu�i� skai�i�.
        rf.close();

        return 0;
    }

}
