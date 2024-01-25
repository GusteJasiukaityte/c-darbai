//// Ávedamos bibliotekos.
#include <iostream> // biblioteka programoje atsakinga uþ tokias komandas kaip cout ir cin.
#include <cmath> // biblioteka programoje atsakinga uþ matematinius veiksmus, tokius kaip pow, sqrt ir pan.
#include <iomanip> // biblioteka programoje atsakinga uþ tokias komandas, kaip set precision ar setw.


using namespace std; // reikalinga, kad galëtume naudoti cout, cin, endl, ifstream bei ofstream.


int main() // pagrindinë programos funkcija.
{

    setlocale (LC_ALL, "Lithuanian"); //iðvedimui naudojame lietuviø kalbà.

    ////kintamøjø ávedimas.
    int skaiciai[100]; // Masyvas, skirtas saugoti vartotojo ávestus skaièius.
    int atvirkstinisSkaiciai[100]; // Masyvas skirtas saugoti vartotojo ávestus skaièius atvirkðtine tvarka.
    int kiekis; // kintamasis, nurodantis kieká skaièiø, kuriuos áves vartotojas.


    ////pradiniø duomenø ávedimas
    cout << "Kiek skaièiø norësite ávesti? : "; // klausiama vartotojo, kiek skaièiø jis norës ávesti.
    cin >> kiekis; // vieta, kur vartotojas áveda pasirinktus skaièius.


    cout << endl; // padaromas tarpas tarp klausimø.


    ////kiekvieno skaièiaus ávedimas.
    for (int i = 0; i < kiekis; i++) //sukuriamas ciklas, kuriuo bus galima ávesti visus pradinius duomenis (visus skaièius).
    {
        cout << i + 1 << "-asis skaicius: "; // praðoma vartotojo ávesti kiekvienà pasirinktà skaièiø.
        cin >> skaiciai[i]; // vieta, kur vartotojas áveda kiekvienà pasirinktà skaièiø.
    }

    ////vartotojo ávesti skaièiai eilutëje.
    cout << "\nÁvesti skaièiai: "; // pateikiami vartotojo suvesti skaièiai.
    for (int i = 0; i < kiekis; i++) // ciklas, leidþiantis iðvesti kiekvienà vartotojo ávestà skaièiø.
    {
        cout << skaiciai[i] << " "; // iðvedami visi vartotojo pasirinkti skaièiai.
    }


    //// vartotojo ávesti skaièiai atvirkðtinëje eilutëje.
    for (int i = 0; i < kiekis; i++) // ciklas, leidþiantis iðvesti kiekvienà vartotojo ávestà skaièiø.
    {
        atvirkstinisSkaiciai[i] = skaiciai[kiekis - i - 1]; // atvirkðtiniø skaièiø masyvo prilyginimas skaièiø masyvui.
    }


    //// vartotojo ávesti skaièiai atvirkðtinëje eilutëje.
    cout << "\nÁvesti skaièiai atvirkðtine tvarka: ";  // pateikiami vartotojo suvesti skaièiai atvirkðtine tvarka.
    for (int i = 0; i < kiekis; i++) // ciklas, leidþiantis iðvesti kiekvienà vartotojo ávestà skaièiø.
    {
        cout << atvirkstinisSkaiciai[i] << " "; // iðvedami visi skaièiai atvirkðtine tvarka.
    }

    return 0; // programa uþbaigta ir ávykdyta sëkmingai.
}
