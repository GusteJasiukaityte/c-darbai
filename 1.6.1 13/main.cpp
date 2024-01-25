//// �vedamos bibliotekos.
#include <iostream> // biblioteka programoje atsakinga u� tokias komandas kaip cout ir cin.
#include <cmath> // biblioteka programoje atsakinga u� matematinius veiksmus, tokius kaip pow, sqrt ir pan.
#include <iomanip> // biblioteka programoje atsakinga u� tokias komandas, kaip set precision ar setw.


using namespace std; // reikalinga, kad gal�tume naudoti cout, cin, endl, ifstream bei ofstream.


int main() // pagrindin� programos funkcija.
{

    setlocale (LC_ALL, "Lithuanian"); //i�vedimui naudojame lietuvi� kalb�.

    ////kintam�j� �vedimas.
    int skaiciai[100]; // Masyvas, skirtas saugoti vartotojo �vestus skai�ius.
    int atvirkstinisSkaiciai[100]; // Masyvas skirtas saugoti vartotojo �vestus skai�ius atvirk�tine tvarka.
    int kiekis; // kintamasis, nurodantis kiek� skai�i�, kuriuos �ves vartotojas.


    ////pradini� duomen� �vedimas
    cout << "Kiek skai�i� nor�site �vesti? : "; // klausiama vartotojo, kiek skai�i� jis nor�s �vesti.
    cin >> kiekis; // vieta, kur vartotojas �veda pasirinktus skai�ius.


    cout << endl; // padaromas tarpas tarp klausim�.


    ////kiekvieno skai�iaus �vedimas.
    for (int i = 0; i < kiekis; i++) //sukuriamas ciklas, kuriuo bus galima �vesti visus pradinius duomenis (visus skai�ius).
    {
        cout << i + 1 << "-asis skaicius: "; // pra�oma vartotojo �vesti kiekvien� pasirinkt� skai�i�.
        cin >> skaiciai[i]; // vieta, kur vartotojas �veda kiekvien� pasirinkt� skai�i�.
    }

    ////vartotojo �vesti skai�iai eilut�je.
    cout << "\n�vesti skai�iai: "; // pateikiami vartotojo suvesti skai�iai.
    for (int i = 0; i < kiekis; i++) // ciklas, leid�iantis i�vesti kiekvien� vartotojo �vest� skai�i�.
    {
        cout << skaiciai[i] << " "; // i�vedami visi vartotojo pasirinkti skai�iai.
    }


    //// vartotojo �vesti skai�iai atvirk�tin�je eilut�je.
    for (int i = 0; i < kiekis; i++) // ciklas, leid�iantis i�vesti kiekvien� vartotojo �vest� skai�i�.
    {
        atvirkstinisSkaiciai[i] = skaiciai[kiekis - i - 1]; // atvirk�tini� skai�i� masyvo prilyginimas skai�i� masyvui.
    }


    //// vartotojo �vesti skai�iai atvirk�tin�je eilut�je.
    cout << "\n�vesti skai�iai atvirk�tine tvarka: ";  // pateikiami vartotojo suvesti skai�iai atvirk�tine tvarka.
    for (int i = 0; i < kiekis; i++) // ciklas, leid�iantis i�vesti kiekvien� vartotojo �vest� skai�i�.
    {
        cout << atvirkstinisSkaiciai[i] << " "; // i�vedami visi skai�iai atvirk�tine tvarka.
    }

    return 0; // programa u�baigta ir �vykdyta s�kmingai.
}
