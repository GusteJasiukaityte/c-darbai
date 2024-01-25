#include <iostream> // biblioteka programoje atsakinga uþ tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga uþ tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandà.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std;

int main()
{
    //ofstream rf ("rezultatu_failas.txt");  //failo raðymas
    //ofstream rf (rezultatu_failas);  //failo raðymas.
    const char duomenu_failas[] = "Duomenys.txt"; // Duomenø failo vardas.

    ifstream df; // failo skaitymas.
    df.open("duomenys.txt");
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolë iðvedama, jog failo atidaryti nepavyko.

    }
    else
    {
      cout << "Failas atidarytas." << endl;
    }
    //int neuzdengta_siena = neuzdengta();
    //rf << neuzdengta_siena;
    //rf.close();


    return 0;
}
