//prijungiame bibliotekas
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//duomenų ir rezultatų failų aprašymas
const char duomenu_failas [] = "Duomenys.txt";
const char rezultatu_failas [] = "Rezultatai.txt";

//programos pagrindinis ciklas
int main()
{
    int n; // mėnesių skaičius
    double suma = 0, // suma
    b; // kintamasis, naudojamas gauti sumą.

    setlocale(LC_ALL, "Lithuanian");

    ifstream df (duomenu_failas);
    if (!df)
    {
        cout << "Failas neatidarytas" << endl; // jeigu failo neišeina atidaryti.

        return -1;
    }
    else
    {
       df >> n; // duomenų failą nukreipiame į kintamąjį n

        for (int i = 0; i < n; i++)
        {
            df >> b; //duomenų failą nukreipiame į kintamajį b
            suma += b; // suma = suma + b;
        }

        df.close();

        ofstream rf (rezultatu_failas);
        rf << fixed << setprecision(2) << suma;
        rf.close();

        return 0;
    }
}
