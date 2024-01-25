#include <iostream> // biblioteka atsakinga uþ komandas cout ir cin.
#include <fstream> // biblioteka atsakinga uþ komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandà.
#include <cmath> // biblioteka atsakinga uþ matematinius veiksmus.

using namespace std; // priklauso standartinës funkcijos ir kintamieji.

//duomenø ir rezultatø failø apraðymas
const char duomenu_failas [] = "Duomenys.txt"; // Duomenø failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatø failo vardas.

int lenteliu_skaicius() // funkcija, skaièiuojanti lenteliø kieká.
{
   ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolë iðvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        int n, // kabinetø kiekis.
        s, // lenteliø suma.
        x; // kintamasis saugantis lenteliø kieká.

        df >> n; // nuskaitomas kabinetø kiekis.

        s = 0; // suma lygi nuliui.
        x = 0; // lenteliø kiekis lygus nuliui.

        for ( int i = 1; i <= n; i++ ) // i = 1 ir didëja, kol yra vienetu maþesnis arba lygus n.
        {
            x = int (log10(i)+1); // x lygus logoritmui, kurio pagrindas yra 10, o skaitiklis i + 1.
            //Èia apskaièiuojama kiek lenteliø reikës kiekvienam kabinetui.
            //Kol kabineto numeris maþesnis uþ 10, tol i bus lygus 0, o 0 + 1 = 1, todël tam kabinetui reikës vienos lentelës.
            //Kai kabineto numerii bus dviþenkliai skaièiai, i bus lygus 1, o 1+1 = 2.

            s += x; // s = s + x.

        }
        df.close(); // uþdaromas duomenø failas.
        return s; // gràþinama s reikðmë.
    }
}

int main() // pagrindinë programos funkcija.
{
    int skaicius = lenteliu_skaicius(); // kintamasis skaicius lygus funkcijos rezultatui.

    ofstream rf (rezultatu_failas); // atidaromas rezultatø failas.
    rf << skaicius; // á rezultatø failà áraðomas atsakymas.
    rf.close(); // uþdaromas rezultatø failas.

    return 0;
}
