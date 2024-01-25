//// Įvedamos bibliotekos.
#include <iostream> // biblioteka programoje atsakinga už tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga už tokias komandas ifstream ir ofstream.

using namespace std; // reikalinga, kad galėtume naudoti cout, cin, endl, ifstream bei ofstream.

////rezultatų failo aprašymas
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatų failo vardas.

////funkcija, skirta gauti ir palyginti skaičių.
int ivedimas() // int tipo funkcija pavadinimu „ivedimas“.
{
    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

    ////kintamojo įvedimas.
    int pazymys, // vartotojo įvesto paskutinio pažymio kintamasis.
    busena; // kintamasis nurodantis palyginant skaičių gautą rezulatą.

    ////skaičiaus palyginimas.
    cout << "Įveskite savo paskutinį gautą pažymį: "; // Prašoma vartotojo įvesti pradinius duomenis - savo paskutinį pažymį.
    cin >> pazymys; // vieta, skirta vartotojui įvesti savo paskutinį pažymį.

    // jeigu pažymys yra daugiau arba lygu 4, tai funkcijos būsena yra true.
    if (pazymys >= 4)
    {
        busena = true; // jeigu sąlyga patenkinama, būsena yra true.
    }
    // jeigu pažymys yra mažiau už 4, tai funkcijos būsena yra false.
    if (pazymys < 4)
    {
        busena = false; // jeigu sąlyga patenkinama, būsena yra false.
    }
    return busena; // grąžinama būsena, palyginus skaičių.
}

int main() // pagrindinė programos funkcija.
{
    setlocale (LC_ALL, "Lithuanian"); //išvedimui naudojame lietuvių kalbą.

    ////rezultatų įvedimas į rezultatų failą.
    ofstream rf(rezultatu_failas); // atidaromas rezultatų failas.
    int rezultatas = ivedimas(); // įvedamas kintamasis „rezultatas“, kuriame saugomas „ivedimas“ funkcijos rezultatas.

    if (rezultatas == true) // sąlyga, jeigu rezultatas yra true.
        {
        rf << "Paskutinis pažymys yar teigiamas (daugiau arba lygu 4)." << endl; // į rezultatų failą išvedamas atsakymas.
        }
    else if (rezultatas == false) // sąlyga, jeigu rezultatas yra false.
        {
        rf << "Paskutinis pažymys yra neigiamas (mažiau už 4)." << endl; // į rezultatų failą išvedamas atsakymas.
        }
    rf.close(); // uždaromas rezultatų failas.
    return 0; // programa užbaigta ir įvykdyta sëkmingai.
}
