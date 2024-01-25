//// Įvedamos bibliotekos.
#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.

using namespace std; // reikalinga, kad galėtume naudoti cout, cin, endl, ifstream bei ofstream.

////duomenų ir rezultatų failų aprašymas
const char duomenu_failas [] = "Rezultatai1.txt"; // Duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai1.txt"; // Rezultatų failo vardas.

//// funkcijos prototipas
int nuskaitomas(); // programa informuojama apie funkcijos egzistavimą.


//// funkcija, skirta palyginti gautus pradinius duomenis.
int skaiciai() // int tipo funkcija, pavadinimu „skaiciai“.
{
    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

    ////Kintamųjų įvedimas
    int busena; // kintamasis nurodantis palyginant skaičius gautus rezulatus.
    int skaicius1, skaicius2; // vartotojo įvestų pradinių duomenų kintamieji skaičių kintamieji.
    cout << "Įveskite du skaičius, kurie sioje programoje bus lyginami tarpusavyje: " << endl; // Prašoma vartotojo įvesti pradinius duomenis.
    cin >> skaicius1 >> skaicius2; // vieta, skirta vartotojui įvesti pradinius duomenis.

    ////Skaičių palyginimas
    if (skaicius1 > skaicius2) // sąlyga palyginanti, ar skaicius1 yra didesnis už skaicius2.
    {
        busena = skaicius1; // jeigu sąlyga patenkinama, tai būsena lygi skaicius1.
    }
    else if  (skaicius1 < skaicius2) // sąlyga palyginanti skaičius, ar skaicius2 yra didesnis už skaicius1.
    {
        busena = skaicius2; // jeigu sąlyga patenkinama, būsena lygi skaicius2.
    }
    else
    {
        busena = skaicius1;// jeigu sąlyga patenkinama, būsena lygi skaicius1.
    }

    return busena; // grąžinama būsena, palyginus skaičius.
}


int main() // pagrindinė programos funkcija.
{
    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

    ////Kintamųjų įvedimas
    int rezultatas = skaiciai(); // įvedamas kintamasis „rezultatas“, kuriame saugomas „skaiciai“ funkcijos rezultatas.

    ////Rezultatų įvedimas į rezultatų failą.
    ofstream rf (rezultatu_failas); // atidaromas rezultatų failas.
    rf << rezultatas; // į rezultatų failą įrašomas atsakymas.
    rf.close(); // uždaromas rezultatų failas.

    // „nuskaitomas“ funkcijos iškvietimas.
    nuskaitomas(); // iškviečiama funkcija „nuskaitomas“.

    return 0; // programa užbaigta ir įvykdyta sėkmingai.
}

//// funkcija, skirta išvesti rezultatą į konsolę.
int nuskaitomas() // int tipo funkcija pavadinimu „nuskaitomas“.
{
    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

    //// Tikrinimas, ar egzistuoja duomenų failas.
    ifstream rf (duomenu_failas); // failo skaitymas.
    if (!rf) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolæ iðvedama, jog failo atidaryti nepavyko.
    }
    else
    {
        ////kintamojo įvedimas.
        int atsakymas; // įvedamas kintamasis „atsakymas“.

        ////Rezultato įvedimas į konsolę.
        rf >> atsakymas; // rezultatų failas nuskaito duomenis, kurie saugomi po kintamuoji „atsakymas“.
        cout << "Didesnis skaičius, is dviejų įvestų skaičių yra: " << atsakymas << endl; // į konsolę išvedamas rezultatas.
        rf.close(); // uždaromas duomenų failas.
        return atsakymas; // grąžinamas rezultatas.
    }
}
