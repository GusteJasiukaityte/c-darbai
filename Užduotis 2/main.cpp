//prijungiame bibliotekas
#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.
#include <string>

using namespace std; // priklauso standartinės funkcijos ir kintamieji.

//duomenų ir rezultatų failų aprašymas
const char duomenu_failas [] = "Duomenys.txt"; // Duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatų failo vardas.

void informacija(); // programa informuojama apie funkcijos egzistavimą.

int main() // pagrindinė programos funckija.
{
    {
        informacija(); // iškviečiama funkcija.
    }

    return 0;
}

void informacija() // void funkcia pavadinimu „Informacija“.
{
    string vardas, // kintamasis, kuris nurodo policininko vardà.
    pavarde, // kintamasis, kuris nurodo policininko pavardæ.
    etatas, // kintamasis, kuris nurodo policininko etatà.
    specializacija; // kintamasis, kuris nurodo policininko specializacijà
    int amzius, // kintamasis, kuris nurodo policininko amþiø.
    alga; // kintamasis, kuris nurodo policininko algà.

    setlocale (LC_ALL, "Lithuanian"); //iðvedimui naudojame lietuviø kalbà.

    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolë iðvedama, jog failo atidaryti nepavyko.
    }
    else
    {
        df >> vardas >> pavarde >> amzius >> alga >> etatas >> specializacija; // nuskaitomi duomenys iš duomenų failo.
        df.close(); // uždaromas duomenų failas.

    ofstream rf (rezultatu_failas);  //failo rašymas

    //į rezultatų failą išvedame atsakymą.
    rf << "Pateikiama informacija apie policininkà: " << vardas << " " << pavarde << ", " << amzius << " metai. Policininko alga: " << alga << " Eur., " << etatas << " darbo etatas, " << " specializacija - " << specializacija << ", kuris šį mėnesį buvo paskelbtas geriausiu darbuotoju!";

    rf.close(); // uždaromas rezultatų failas.
    }
}
