#include <iostream> // biblioteka programoje atsakinga u� tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga u� tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komand�.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso standartin�s funkcijos ir kintamieji.

//duomen� ir rezultat� fail� apra�ymas.
const char duomenu_failas [] = "Krituliai.txt"; // duomen� failo vardas.
const char rezultatu_failas [] = "Krituliaiviso.txt"; // rezultat� failo vardas.

int main() // pagrindin� programos funkcija.
{
    int n, // skai�ius kelias paras buvo matuojamas krituli� kiekis.
    p; // kiek kart� per par� buvo matuojamas krituli� kiekis.
    double k = 0.0, // krituli� kiekis kiekvien� kart�, vert� nustatoma � 0.
    vkd = 0.0, // vidutinis krituli� kiekis t� dien�, vert� nustatoma � 0.
    kv = 0.0; // kiek i� viso krituli� i�krito per visas dienas, vert� nustatoma � 0.

    setlocale (LC_ALL, "Lithuanian"); // i�vedimui naudojame lietuvi� kalb�.

    ifstream df (duomenu_failas); // duomen� failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, � konsol� i�vedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        df >> n ; // nuskaitome skai�i�, kelias paras buvo matuojamas krituli� kiekis.

        ofstream rf(rezultatu_failas);

        for ( int i = 0; i < n; i++) //ciklas yra vykdomas n kart�.
        {
            df >> p; // nuskaitoma kiek kart� per par� buvo matuojamas krituli� kiekis.
            vkd = 0.0; // dienos krituli� suma nustatoma � pradin� pad�t� (0).

                for ( int j = 0; j < p; j++) // �is ciklas yra vykdomas p kart� ir naudojamas nuskaityti duomen� vertes i� duomen� failo.
                {
                    df >> k; // nuskaitomas krituli� kiekis kiekvien� dien�.
                    vkd += k; // vienos dienos krituli� suma.
                    kv += k; // kv = kv + k, sudedama vis� dien� krituli� suma.
                }

            rf << i + 1 << "  " << fixed << setprecision(2) << vkd / p << endl; // � rezultat� fail� i�vedame vidutin� kiekvienos dienos krituli� kiek�.
        }

        rf << "Viso krituli� : " << fixed << setprecision(2) << kv << endl; // � rezultat� fail� i�vedame vis� dien� krituli� sum�.

        df.close(); // u�darome duomen� fail�.
        rf.close(); // u�darome rezultat� fail�.
    }

    return 0;
}
