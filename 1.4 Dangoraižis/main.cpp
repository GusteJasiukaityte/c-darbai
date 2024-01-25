#include <iostream> // biblioteka atsakinga u� komandas cout ir cin.
#include <fstream> // biblioteka atsakinga u� komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komand�.
#include <cmath> // biblioteka atsakinga u� matematinius veiksmus.

using namespace std; // priklauso standartin�s funkcijos ir kintamieji.

//duomen� ir rezultat� fail� apra�ymas
const char duomenu_failas [] = "Duomenys.txt"; // Duomen� failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultat� failo vardas.

int lenteliu_skaicius() // funkcija, skai�iuojanti lenteli� kiek�.
{
   ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, � konsol� i�vedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        int n, // kabinet� kiekis.
        s, // lenteli� suma.
        x; // kintamasis saugantis lenteli� kiek�.

        df >> n; // nuskaitomas kabinet� kiekis.

        s = 0; // suma lygi nuliui.
        x = 0; // lenteli� kiekis lygus nuliui.

        for ( int i = 1; i <= n; i++ ) // i = 1 ir did�ja, kol yra vienetu ma�esnis arba lygus n.
        {
            x = int (log10(i)+1); // x lygus logoritmui, kurio pagrindas yra 10, o skaitiklis i + 1.
            //�ia apskai�iuojama kiek lenteli� reik�s kiekvienam kabinetui.
            //Kol kabineto numeris ma�esnis u� 10, tol i bus lygus 0, o 0 + 1 = 1, tod�l tam kabinetui reik�s vienos lentel�s.
            //Kai kabineto numerii bus dvi�enkliai skai�iai, i bus lygus 1, o 1+1 = 2.

            s += x; // s = s + x.

        }
        df.close(); // u�daromas duomen� failas.
        return s; // gr��inama s reik�m�.
    }
}

int main() // pagrindin� programos funkcija.
{
    int skaicius = lenteliu_skaicius(); // kintamasis skaicius lygus funkcijos rezultatui.

    ofstream rf (rezultatu_failas); // atidaromas rezultat� failas.
    rf << skaicius; // � rezultat� fail� �ra�omas atsakymas.
    rf.close(); // u�daromas rezultat� failas.

    return 0;
}
