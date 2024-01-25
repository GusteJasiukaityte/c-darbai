//// Ávedamos bibliotekos.
#include <iostream> // biblioteka programoje atsakinga uþ tokias komandas kaip cout ir cin.
#include <cmath> // biblioteka programoje atsakinga uþ matematinius veiksmus, tokius kaip pow, sqrt ir pan.
#include <iomanip> // biblioteka programoje atsakinga uþ tokias komandas, kaip set precision ar setw.


using namespace std; // reikalinga, kad galëtume naudoti cout, cin, endl, ifstream bei ofstream.


int main() // pagrindinë programos funkcija.
{

    setlocale (LC_ALL, "Lithuanian"); //iðvedimui naudojame lietuviø kalbà.

    ////kintamøjø ávedimas.
    int skaiciai[100], kvadratai[100], laipsniu[100]; // ávedami masyvai, kurie bus naudojami vedant skaicius, jø kvadratus ir juos, pakeltus tam tikru laipsniu.
    int kiek, // kintamasis, nurodantis kieká skaièiø, kuriuos áves vartotojas.
    laipsnis; // kintamasis, nurodantis kelintu laipsniu reikës pakelti kiekvienà duotà skaièiø.


    ////pradiniø duomenø ávedimas.
    cout << "Kiek skaièiø suvesti: "; // Praðoma vartotojo ávestá kieká skaièiø, su kuriais bus atliekami veiksmai.
    cin >> kiek; // vieta, skirta vartotojui ávesti pradinius duomenis.


    cout << endl; // padaromas eilutës tarpas tarp klausimø.


    //// kiekvieno skaièiaus ávedimas.
    for (int i = 0; i < kiek; i++)//sukuriamas ciklas, kuriuo bus galima ávesti visus pradinius duomenis ( visus skaièius).
    {
        cout << i + 1 << "-asis skaicius: "; // praðoma vartotojo ávesti kiekvienà skaièiø.
        cin >> skaiciai[i]; // vieta, kur vartotojas áveda kiekvienà skaièiø.
    }


    cout << endl; // padaromas eilutës tarpas tarp klausimø


    // pradiniø duomenø ávedimas.
    cout << "Pasirinkite laipsni, kuriuo bus keliami visi duoti skaièiai: "; // vartotojo praðoma ávesti pasirinktà laipsná, kuriuo bus keliami visi skaièiai.
    cin >> laipsnis; // vieta vartotojui ávesti pasirinktà laipsná.


    //// veiksmai su pradiniais duomenimis.
    for (int i = 0; i < kiek; i++)//sukuriamas ciklas, kuriuo bus galima atlikti veiksmus su pradiniais duomenimis.
    {
        kvadratai[i] = skaiciai[i] * skaiciai[i]; // randamas kiekvieno skaièiaus kvadratas.
        laipsniu[i] = pow(skaiciai[i], laipsnis); // randamas kiekvienas skaièius, pakletas duotu laipsniu.
    }


    //// á konsolæ iðvedami pateikti duomenys.
    cout << "\nSuvesti skaiciai: \n"; // pateikiami vartotojo suvesti skaièiai, ðis sakinys ið virðaus ir apaèios atskiriamas tarpais.


    for (int i = 0; i < kiek; i++) // ciklas, leidþiantis iðvesti kiekvienà vartotojo ávestà skaièiø.
    {
        cout << skaiciai[i] << " "; // iðvedami visi vartotojo pasirinkti skaièiai.
    }

    cout << "\n\nSiu skaiciu kvadratai:\n"; // pateikiami vartotojo suvestø skaièiø kvadratai, ðis sakinys ið virðaus ir apaèios atskiriamas tarpais.


    for (int i = 0; i < kiek; i++) // ciklas, leidþiantis iðvesti kiekvienà vartotojo ávestà skaièiø pakelta kvadratu.
    {
        cout << kvadratai[i] << " "; // iðvedami visi vartotojo pasirinktø skaièiø kvadratai.
    }


    cout << "\n\nSie skaiciai pakelti " << laipsnis << "-u laipsniu:\n"; // pateikiami vartotojo suvesti skaièiai pakelti pasirinktu laipsniu, ðis sakinys ið virðaus ir apaèios atskiriamas tarpais.


    for (int i = 0; i < kiek; i++) // ciklas, leidþiantis iðvesti kiekvienà vartotojo ávestà skaièiø pakeltà pasirinktu laipsniu.
    {
        cout << laipsniu[i] << " "; // iðvedami visi vartotojo pasirinkti skaièiai pakelti pasirinktu laipsniu.
    }


    //// kuriama lentelë su rezultatais.
    cout << "\n\n"; // padaromi du tarpai po atsakymø.
    cout << "+----------+-----------+---------------+\n"; // sukuriama lentelës virðutinë kraðtinë.
    cout << "| Skaicius | Kvadratas | " << laipsnis << "-as laipsnis |\n"; // ávedami kiekvienos lentelës dalies pavadinimai.
    cout << "+----------+-----------+---------------+\n"; // atkarpa po kiekvienos dalies pavadinimu.


    for (int i = 0; i < kiek; i++) // ciklas, leidþiantis á lentelæ ávesti visus rezultatøs.
    {
        cout << "| " << setw(8) << left << skaiciai[i] << " | " // ávedamas skaièius, jam skiriamos 8 vietos.
            << setw(9) << kvadratai[i] << " | " // ávedamas kiekvieno skaièiaus kvadratas, jam skiriamos 9 vietos.
            << setw(13) << laipsniu[i] << " |\n"; // ávedamas kiekvienas skaièius, pakeltas pasirinktu laipsniu, jam skiriama 13 vietø.
    }


    cout << "+----------+-----------+---------------+\n"; // apatinë lentelës kraðtinë.


    return 0; // programa uþbaigta ir ávykdyta sëkmingai.
}
