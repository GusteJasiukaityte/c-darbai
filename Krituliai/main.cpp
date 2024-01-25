#include <iostream> // biblioteka programoje atsakinga uþ tokias komandas kaip cout ir cin.
#include <fstream> // biblioteka programoje atsakinga uþ tokias komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandà.
#include <cmath> // biblioteka programoje nuskaito bendruosius matematinius veiksmus.

using namespace std; // priklauso standartinës funkcijos ir kintamieji.

//duomenø ir rezultatø failø apraðymas.
const char duomenu_failas [] = "Krituliai.txt"; // duomenø failo vardas.
const char rezultatu_failas [] = "Krituliaiviso.txt"; // rezultatø failo vardas.

int main() // pagrindinë programos funkcija.
{
    int n, // skaièius kelias paras buvo matuojamas krituliø kiekis.
    p; // kiek kartø per parà buvo matuojamas krituliø kiekis.
    double k = 0.0, // krituliø kiekis kiekvienà kartà, vertë nustatoma á 0.
    vkd = 0.0, // vidutinis krituliø kiekis tà dienà, vertë nustatoma á 0.
    kv = 0.0; // kiek ið viso krituliø iðkrito per visas dienas, vertë nustatoma á 0.

    setlocale (LC_ALL, "Lithuanian"); // iðvedimui naudojame lietuviø kalbà.

    ifstream df (duomenu_failas); // duomenø failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, á konsolæ iðvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        df >> n ; // nuskaitome skaièiø, kelias paras buvo matuojamas krituliø kiekis.

        ofstream rf(rezultatu_failas);

        for ( int i = 0; i < n; i++) //ciklas yra vykdomas n kartø.
        {
            df >> p; // nuskaitoma kiek kartø per parà buvo matuojamas krituliø kiekis.
            vkd = 0.0; // dienos krituliø suma nustatoma á pradinæ padëtá (0).

                for ( int j = 0; j < p; j++) // ðis ciklas yra vykdomas p kartø ir naudojamas nuskaityti duomenø vertes ið duomenø failo.
                {
                    df >> k; // nuskaitomas krituliø kiekis kiekvienà dienà.
                    vkd += k; // vienos dienos krituliø suma.
                    kv += k; // kv = kv + k, sudedama visø dienø krituliø suma.
                }

            rf << i + 1 << "  " << fixed << setprecision(2) << vkd / p << endl; // á rezultatø failà iðvedame vidutiná kiekvienos dienos krituliø kieká.
        }

        rf << "Viso krituliø : " << fixed << setprecision(2) << kv << endl; // á rezultatø failà iðvedame visø dienø krituliø sumà.

        df.close(); // uþdarome duomenø failà.
        rf.close(); // uþdarome rezultatø failà.
    }

    return 0;
}
