//prijungiame bibliotekas
#include <iostream>
#include <fstream>
//#include <iomanip>

using namespace std;

//duomenè ir rezultatè failè aprq-ymas
const char duomenu_failas [] = "Duomenys1.txt";
const char rezultatu_failas [] = "Rezultatai1.txt";

int main()
{
   int k, //kiek pirmąją prekybos dieną parduota porcijų.
   m, // keliomis porcijomis kiekvieną kitą dieną buvo parduodama daugiau.
   n, //kelias dienas buvo prekiauta ledais.
   vk = 0; // ledų porcijų suma.

   setlocale(LC_ALL, "Lithuanian");

    ifstream df (duomenu_failas);
    if (!df)
    {
        cout << "Failas neatidarytas" << endl; // jeigu failo neišeina atidaryti.

        return -1;
    }
    else
    {
       df >> k >> m >> n;

       for (int i = 0; i < n; i++)
       {
           vk += k + i * m; // Pirmąją prekybos dieną parduotų porcijų kiekis sudedamas su papildomu kiekiu (i * m).
        }
       }

        df.close();

        ofstream rf (rezultatu_failas);
        rf << vk;
        rf.close();

        return 0;
    }
