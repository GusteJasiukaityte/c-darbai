//// �vedamos bibliotekos.
#include <iostream> // biblioteka programoje atsakinga u� tokias komandas kaip cout ir cin.
#include <cmath> // biblioteka programoje atsakinga u� matematinius veiksmus, tokius kaip pow, sqrt ir pan.
#include <iomanip> // biblioteka programoje atsakinga u� tokias komandas, kaip set precision ar setw.


using namespace std; // reikalinga, kad gal�tume naudoti cout, cin, endl, ifstream bei ofstream.


int main() // pagrindin� programos funkcija.
{

    setlocale (LC_ALL, "Lithuanian"); //i�vedimui naudojame lietuvi� kalb�.

    ////kintam�j� �vedimas.
    int skaiciai[100], kvadratai[100], laipsniu[100]; // �vedami masyvai, kurie bus naudojami vedant skaicius, j� kvadratus ir juos, pakeltus tam tikru laipsniu.
    int kiek, // kintamasis, nurodantis kiek� skai�i�, kuriuos �ves vartotojas.
    laipsnis; // kintamasis, nurodantis kelintu laipsniu reik�s pakelti kiekvien� duot� skai�i�.


    ////pradini� duomen� �vedimas.
    cout << "Kiek skai�i� suvesti: "; // Pra�oma vartotojo �vest� kiek� skai�i�, su kuriais bus atliekami veiksmai.
    cin >> kiek; // vieta, skirta vartotojui �vesti pradinius duomenis.


    cout << endl; // padaromas eilut�s tarpas tarp klausim�.


    //// kiekvieno skai�iaus �vedimas.
    for (int i = 0; i < kiek; i++)//sukuriamas ciklas, kuriuo bus galima �vesti visus pradinius duomenis ( visus skai�ius).
    {
        cout << i + 1 << "-asis skaicius: "; // pra�oma vartotojo �vesti kiekvien� skai�i�.
        cin >> skaiciai[i]; // vieta, kur vartotojas �veda kiekvien� skai�i�.
    }


    cout << endl; // padaromas eilut�s tarpas tarp klausim�


    // pradini� duomen� �vedimas.
    cout << "Pasirinkite laipsni, kuriuo bus keliami visi duoti skai�iai: "; // vartotojo pra�oma �vesti pasirinkt� laipsn�, kuriuo bus keliami visi skai�iai.
    cin >> laipsnis; // vieta vartotojui �vesti pasirinkt� laipsn�.


    //// veiksmai su pradiniais duomenimis.
    for (int i = 0; i < kiek; i++)//sukuriamas ciklas, kuriuo bus galima atlikti veiksmus su pradiniais duomenimis.
    {
        kvadratai[i] = skaiciai[i] * skaiciai[i]; // randamas kiekvieno skai�iaus kvadratas.
        laipsniu[i] = pow(skaiciai[i], laipsnis); // randamas kiekvienas skai�ius, pakletas duotu laipsniu.
    }


    //// � konsol� i�vedami pateikti duomenys.
    cout << "\nSuvesti skaiciai: \n"; // pateikiami vartotojo suvesti skai�iai, �is sakinys i� vir�aus ir apa�ios atskiriamas tarpais.


    for (int i = 0; i < kiek; i++) // ciklas, leid�iantis i�vesti kiekvien� vartotojo �vest� skai�i�.
    {
        cout << skaiciai[i] << " "; // i�vedami visi vartotojo pasirinkti skai�iai.
    }

    cout << "\n\nSiu skaiciu kvadratai:\n"; // pateikiami vartotojo suvest� skai�i� kvadratai, �is sakinys i� vir�aus ir apa�ios atskiriamas tarpais.


    for (int i = 0; i < kiek; i++) // ciklas, leid�iantis i�vesti kiekvien� vartotojo �vest� skai�i� pakelta kvadratu.
    {
        cout << kvadratai[i] << " "; // i�vedami visi vartotojo pasirinkt� skai�i� kvadratai.
    }


    cout << "\n\nSie skaiciai pakelti " << laipsnis << "-u laipsniu:\n"; // pateikiami vartotojo suvesti skai�iai pakelti pasirinktu laipsniu, �is sakinys i� vir�aus ir apa�ios atskiriamas tarpais.


    for (int i = 0; i < kiek; i++) // ciklas, leid�iantis i�vesti kiekvien� vartotojo �vest� skai�i� pakelt� pasirinktu laipsniu.
    {
        cout << laipsniu[i] << " "; // i�vedami visi vartotojo pasirinkti skai�iai pakelti pasirinktu laipsniu.
    }


    //// kuriama lentel� su rezultatais.
    cout << "\n\n"; // padaromi du tarpai po atsakym�.
    cout << "+----------+-----------+---------------+\n"; // sukuriama lentel�s vir�utin� kra�tin�.
    cout << "| Skaicius | Kvadratas | " << laipsnis << "-as laipsnis |\n"; // �vedami kiekvienos lentel�s dalies pavadinimai.
    cout << "+----------+-----------+---------------+\n"; // atkarpa po kiekvienos dalies pavadinimu.


    for (int i = 0; i < kiek; i++) // ciklas, leid�iantis � lentel� �vesti visus rezultat�s.
    {
        cout << "| " << setw(8) << left << skaiciai[i] << " | " // �vedamas skai�ius, jam skiriamos 8 vietos.
            << setw(9) << kvadratai[i] << " | " // �vedamas kiekvieno skai�iaus kvadratas, jam skiriamos 9 vietos.
            << setw(13) << laipsniu[i] << " |\n"; // �vedamas kiekvienas skai�ius, pakeltas pasirinktu laipsniu, jam skiriama 13 viet�.
    }


    cout << "+----------+-----------+---------------+\n"; // apatin� lentel�s kra�tin�.


    return 0; // programa u�baigta ir �vykdyta s�kmingai.
}
