//prijungiame bibliotekas
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//duomenø ir rezultatø failø apraðymas.
const char duomenu_failas [] = "Duomenys.txt";
const char rezultatu_failas [] = "Rezultatai.txt";

int main ()
{
    int n, // dienø skaièius.
    suma = 0, // minuèiø, kiek dresavo katinà, suma.
    vid, // kiek vidutiniðkai minuèiø per diena buvo dresuojamas katinas.
    t; // kintamasis, naudojamas gauti sumà.

    setlocale(LC_ALL, "Lithuanian");

    ifstream df (duomenu_failas);
    if (!df)
    {
        cout << "Failas neatidarytas" << endl; // jeigu failas neatsidaro.

        return -1;
    }
    else
    {
        df >> n; // duomenø failà nukreipiame á kintamàjá n.

        for ( int i = 0; i < n; i++)
        {
            df >> t; // duomenø failà nukreipiame á kintamàjá t.
            suma += t; // suma = suma + t.
            vid = suma / n; // suma padalijama ið dienø skaièiaus.
        }
        df.close(); // uþdarome duomenø failà.

        ofstream rf (rezultatu_failas);
        rf << suma << endl; // á rezultatø failà iðvedame sumà.
        rf << vid << endl; // á rezultatø failà iðvedame vidutiná minuèiø skaièiø.
        rf.close();

        return 0;
    }

}
