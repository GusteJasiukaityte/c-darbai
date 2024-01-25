#include <iostream> // biblioteka atsakinga uþ komandas cout ir cin.
#include <fstream> // biblioteka atsakinga uþ komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandà.

using namespace std; // priklauso standartinës funkcijos ir kintamieji.

//duomenø ir rezultatø failø apraðymas
const char duomenu_failas [] = "Duomenys.txt"; // Duomenø failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatø failo vardas.

int bendras_plotas() // funkcija, skaièiuojanti visiems sodininkams esantá bendrà plotà.
{
    //ifstream inputFile("Duomenys.txt");
    //ofstream outputFile("Rezultatai.txt");
    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolë iðvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        int x1, // kairio apatinio kampo x koordinatë.
        y1, // kairio apatinio kampo y koordinatë.
        x2, // deðinio virðutinio kampo x koordinatë.
        y2; // deðinio virðutinio kampo y koordinatë.

        int x1_maksimalus = 0, // nustatoma,kad x1 maksimali reikðmë lygi nuliui.
        y1_maksimalus = 0, // nustatoma,kad x1 maksimali reikðmë lygi nuliui.
        x2_minimalus = 999, // nustatoma,kad x2 minimali reikðmë lygi 999.
        y2_minimalus = 999; // nustatoma,kad y2 minimali reikðmë lygi 999.

        for (int i = 0; i < 3; ++i)// skaièiuojamas bendras plotas.
        {
            df >> x1 >> y1 >> x2 >> y2; // nuskaitomi kintamieji ið duomenø failo.
            x1_maksimalus = max(x1_maksimalus, x1);// randama, kur baigiasi visi sklypai i kairæ pusæ.
            y1_maksimalus = max(y1_maksimalus, y1);// randama, kur prasideda visi sklypai á deðinæ.
            x2_minimalus = min(x2_minimalus, x2);// randama, kur baigiasi visi sklypai þemyn.
            y2_minimalus = min(y2_minimalus, y2); // randama, kur visi sklypai prasideda aukðtyn.
        }

        int bendras_sklypas = (x2_minimalus - x1_maksimalus) * (y2_minimalus - y1_maksimalus);// skaièiuojamas bendro staèiakampio plotas.

    df.close(). // uþdaromas duomenø failas.
    return 0;
}

 int main()
 {
    ofstream rf (rezultatu_failas); // atidaromas rezultatø failas.

    int bendras = bendras_plotas(); // kintamasisi bendras = funkcijos bendras_plotas rezultatui.
    rf << bendras; // á rezultatø failà áraðomas atsakymas.

    rf.close(); // uþdaromas rezultatø failas.
    return 0;
 }
