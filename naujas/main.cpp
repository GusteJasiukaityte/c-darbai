#include <iostream> // biblioteka programoje atsakinga u� tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga u� tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komand�.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std;

int main()
{
    //ofstream rf ("rezultatu_failas.txt");  //failo ra�ymas
    //ofstream rf (rezultatu_failas);  //failo ra�ymas.
    const char duomenu_failas[] = "Duomenys.txt"; // Duomen� failo vardas.

    ifstream df; // failo skaitymas.
    df.open("duomenys.txt");
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, � konsol� i�vedama, jog failo atidaryti nepavyko.

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
