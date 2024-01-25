#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cin ir cout.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas kaip ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso stndartinės funkcijos ir kintamieji.

// duomenų ir rezultatų failų aprašymas.
const char duomenu_failas [] = "Temperaturos.txt"; // duomenų failo vardas.
const char rezultatu_failas [] = "Vidutines.txt"; // rezultatų failo vardas.

int main() // pagrindinė programos funkcija.
{

   int n, // Lietuvos miestų, kuriuose fiksuojama temperatūra, skaičius.
   m = 7; // temperatūrų skaičius viename mieste.

   setlocale (LC_ALL, "Lithuanian"); // išvedimui naudojame lietuvių kalba.

   ifstream df (duomenu_failas); // duomenų failo skaitymas.
   if (!df) // Patikra.
   {
       cout << "Failas neatidarytas" << endl; // jeigu failas neatsidaro, į konsolę išvedama, jog failo atidaryti nepavyko.


       return -1;
   }
   else
   {

        df >> n; // duomenų failas nuskaito kintamąjį n.

        ofstream rf (rezultatu_failas); // failo rašymas

        for (int i = 0; i < n; i++) // kintamasis i didėja vienu vienetu, taip bus nuskaitoma kiekviena duomenų failo eilutė.
        {
            //int m = 7; // temperatūrų skaičius viename mieste.

            double temp_suma = 0; // įvedamas kintamasis, kokia yra vidutinė temperatūra viename mieste.

            for (int j = 0; j < m; j++) // kintamasis j didėja vienu vienetu, taip nuskaitomi visi tos pačios eilutės duomenys.
            {
                double temp; // įvedamas kintamasis, kuris laikinai saugo temperatūros duomenis ir yra naudojamas suskaičiuoti vidutinį miesto temperatūrų vidurkį.
                df >> temp; // duomenų failas nuskaito kintamąjį temp.
                temp_suma += temp ; // kad gauti vidutinį miesto temperatūrų vidurkį, atliekami veiksmai.
            }

        rf << i + 1 << "  " << fixed << setprecision(3) << temp_suma / m << endl; // į rezultatų failą išvedamas atsakymas.
        }

    df.close(); // uždaromas duomenų failas.
    rf.close(); // uždaromas rezultatų failas.
    }
    return 0;
}
