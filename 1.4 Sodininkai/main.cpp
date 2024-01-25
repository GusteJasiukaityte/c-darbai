#include <iostream> // biblioteka atsakinga u� komandas cout ir cin.
#include <fstream> // biblioteka atsakinga u� komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komand�.

using namespace std; // priklauso standartin�s funkcijos ir kintamieji.

//duomen� ir rezultat� fail� apra�ymas
const char duomenu_failas [] = "Duomenys.txt"; // Duomen� failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultat� failo vardas.

int bendras_plotas() // funkcija, skai�iuojanti visiems sodininkams esant� bendr� plot�.
{
    //ifstream inputFile("Duomenys.txt");
    //ofstream outputFile("Rezultatai.txt");
    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, � konsol� i�vedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        int x1, // kairio apatinio kampo x koordinat�.
        y1, // kairio apatinio kampo y koordinat�.
        x2, // de�inio vir�utinio kampo x koordinat�.
        y2; // de�inio vir�utinio kampo y koordinat�.

        int x1_maksimalus = 0, // nustatoma,kad x1 maksimali reik�m� lygi nuliui.
        y1_maksimalus = 0, // nustatoma,kad x1 maksimali reik�m� lygi nuliui.
        x2_minimalus = 999, // nustatoma,kad x2 minimali reik�m� lygi 999.
        y2_minimalus = 999; // nustatoma,kad y2 minimali reik�m� lygi 999.

        for (int i = 0; i < 3; ++i)// skai�iuojamas bendras plotas.
        {
            df >> x1 >> y1 >> x2 >> y2; // nuskaitomi kintamieji i� duomen� failo.
            x1_maksimalus = max(x1_maksimalus, x1);// randama, kur baigiasi visi sklypai i kair� pus�.
            y1_maksimalus = max(y1_maksimalus, y1);// randama, kur prasideda visi sklypai � de�in�.
            x2_minimalus = min(x2_minimalus, x2);// randama, kur baigiasi visi sklypai �emyn.
            y2_minimalus = min(y2_minimalus, y2); // randama, kur visi sklypai prasideda auk�tyn.
        }

        int bendras_sklypas = (x2_minimalus - x1_maksimalus) * (y2_minimalus - y1_maksimalus);// skai�iuojamas bendro sta�iakampio plotas.

    df.close(). // u�daromas duomen� failas.
    return 0;
}

 int main()
 {
    ofstream rf (rezultatu_failas); // atidaromas rezultat� failas.

    int bendras = bendras_plotas(); // kintamasisi bendras = funkcijos bendras_plotas rezultatui.
    rf << bendras; // � rezultat� fail� �ra�omas atsakymas.

    rf.close(); // u�daromas rezultat� failas.
    return 0;
 }
