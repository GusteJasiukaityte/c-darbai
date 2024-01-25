//// Ávedamos bibliotekos.
#include <iostream> // biblioteka programoje atsakinga uþ tokias komandas kaip cout ir cin.
#include <cmath> // biblioteka programoje atsakinga uþ matematinius veiksmus, tokius kaip pow, sqrt ir pan.
#include <iomanip> // biblioteka programoje atsakinga uþ tokias komandas, kaip set precision ar setw.


using namespace std; // reikalinga, kad galëtume naudoti cout, cin, endl, ifstream bei ofstream.


int main() // pagrindinë programos funkcija.
{

    setlocale (LC_ALL, "Lithuanian"); //iðvedimui naudojame lietuviø kalbà.

    ////kintamøjø ávedimas.
    int skaiciai[100]; // ávedamas masyvas, kuris bus naudojamas ávedant skaièius, ið jø iðvedant lyginius ir nelyginius.
    int kiekis; // kintamasis, nurodantis kieká skaièiø, kuriuos áves vartotojas.


    ////pradiniø duomenø ávedimas.
    cout << "Kiek skaièiø norësite ávesti?: "; // Klausiama vartotojo, kiek skaièiø jis norës ávesti.
    cin >> kiekis; // vieta, skirta vartotojui ávesti pradinius duomenis.


    cout << endl; // padaromas eilutës tarpas tarp klausimø.


    //// kiekvieno skaièiaus ávedimas.
    for (int i = 0; i < kiekis; i++)//sukuriamas ciklas, kuriuo bus galima ávesti visus pradinius duomenis (visus skaièius).
    {
        cout << i + 1 << "-asis skaicius: "; // praðoma vartotojo ávesti kiekvienà skaièiø.
        cin >> skaiciai[i]; // vieta, kur vartotojas áveda kiekvienà pasirinktà skaièiø.
    }

    cout << endl; // padaromas eilutës tarpas tarp klausimø

    //// á konsolæ iðvedami pradiniai duomenys (vartotojo pasirinkti skaièiai).
    cout << "\nSuvesti skaièiai: \n"; // pateikiami vartotojo suvesti skaièiai, ði eilutë ið virðaus ir apaèios atskiriamas tarpais.

    for (int i = 0; i < kiekis; i++) // ciklas, leidþiantis iðvesti kiekvienà vartotojo ávestà skaièiø.
    {
        cout << skaiciai[i] << " "; // iðvedami visi vartotojo pasirinkti skaièiai.
    }


    //// á konsolæ iðvedami tik lyginiai skaièiai ið visø ávestø.
    cout << "\nTik lyginiai skaièiai ið visø ávestø: \n"; // pateikiami tik lyginiai vartotojo suvesti skaièiai.
    for (int i = 0; i < kiekis; i++) // ciklas, leidþiantis iðvesti kiekvienà vartotojo ávestà skaièiø.
    {
        if ( skaiciai[i] % 2 == 0 ) // sàlyga, nurodanti, kad iðvesti tik lyginius skaièius ið visø ávestø.
        {
            cout << skaiciai[i] << " "; // iðvedami lyginiai skaièiai.
        }
    }


    //// á konsolæ iðvedami tik nelyginiai skaièiai ið visø ávestø.
    cout << "\nTik nelyginiai skaièiai ið visø ávestø: \n"; // pateikiami tik nelyginiai vartotojo suvesti skaièiai.

    for (int i = 0; i < kiekis; i++) // ciklas, leidþiantis iðvesti kiekvienà vartotojo ávestà skaièiø.
    {
        if ( skaiciai[i] % 2 != 0) // sàlyga, nurodanti, kad iðvesti tik nelyginius skaièius ið visø ávestø.
        {
            cout << skaiciai[i] << " "; // iðvedami nelyginiai skaièiai.
        }
    }

    return 0; // programa uþbaigta ir ávykdyta sëkmingai.
}



