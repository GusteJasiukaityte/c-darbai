//// �vedamos bibliotekos.
#include <iostream> // biblioteka programoje atsakinga u� tokias komandas kaip cout ir cin.
#include <cmath> // biblioteka programoje atsakinga u� matematinius veiksmus, tokius kaip pow, sqrt ir pan.
#include <iomanip> // biblioteka programoje atsakinga u� tokias komandas, kaip set precision ar setw.


using namespace std; // reikalinga, kad gal�tume naudoti cout, cin, endl, ifstream bei ofstream.


int main() // pagrindin� programos funkcija.
{

    setlocale (LC_ALL, "Lithuanian"); //i�vedimui naudojame lietuvi� kalb�.

    ////kintam�j� �vedimas.
    int skaiciai[100]; // �vedamas masyvas, kuris bus naudojamas �vedant skai�ius, i� j� i�vedant lyginius ir nelyginius.
    int kiekis; // kintamasis, nurodantis kiek� skai�i�, kuriuos �ves vartotojas.


    ////pradini� duomen� �vedimas.
    cout << "Kiek skai�i� nor�site �vesti?: "; // Klausiama vartotojo, kiek skai�i� jis nor�s �vesti.
    cin >> kiekis; // vieta, skirta vartotojui �vesti pradinius duomenis.


    cout << endl; // padaromas eilut�s tarpas tarp klausim�.


    //// kiekvieno skai�iaus �vedimas.
    for (int i = 0; i < kiekis; i++)//sukuriamas ciklas, kuriuo bus galima �vesti visus pradinius duomenis (visus skai�ius).
    {
        cout << i + 1 << "-asis skaicius: "; // pra�oma vartotojo �vesti kiekvien� skai�i�.
        cin >> skaiciai[i]; // vieta, kur vartotojas �veda kiekvien� pasirinkt� skai�i�.
    }

    cout << endl; // padaromas eilut�s tarpas tarp klausim�

    //// � konsol� i�vedami pradiniai duomenys (vartotojo pasirinkti skai�iai).
    cout << "\nSuvesti skai�iai: \n"; // pateikiami vartotojo suvesti skai�iai, �i eilut� i� vir�aus ir apa�ios atskiriamas tarpais.

    for (int i = 0; i < kiekis; i++) // ciklas, leid�iantis i�vesti kiekvien� vartotojo �vest� skai�i�.
    {
        cout << skaiciai[i] << " "; // i�vedami visi vartotojo pasirinkti skai�iai.
    }


    //// � konsol� i�vedami tik lyginiai skai�iai i� vis� �vest�.
    cout << "\nTik lyginiai skai�iai i� vis� �vest�: \n"; // pateikiami tik lyginiai vartotojo suvesti skai�iai.
    for (int i = 0; i < kiekis; i++) // ciklas, leid�iantis i�vesti kiekvien� vartotojo �vest� skai�i�.
    {
        if ( skaiciai[i] % 2 == 0 ) // s�lyga, nurodanti, kad i�vesti tik lyginius skai�ius i� vis� �vest�.
        {
            cout << skaiciai[i] << " "; // i�vedami lyginiai skai�iai.
        }
    }


    //// � konsol� i�vedami tik nelyginiai skai�iai i� vis� �vest�.
    cout << "\nTik nelyginiai skai�iai i� vis� �vest�: \n"; // pateikiami tik nelyginiai vartotojo suvesti skai�iai.

    for (int i = 0; i < kiekis; i++) // ciklas, leid�iantis i�vesti kiekvien� vartotojo �vest� skai�i�.
    {
        if ( skaiciai[i] % 2 != 0) // s�lyga, nurodanti, kad i�vesti tik nelyginius skai�ius i� vis� �vest�.
        {
            cout << skaiciai[i] << " "; // i�vedami nelyginiai skai�iai.
        }
    }

    return 0; // programa u�baigta ir �vykdyta s�kmingai.
}



