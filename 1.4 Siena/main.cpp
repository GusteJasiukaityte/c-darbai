#include <iostream> // biblioteka atsakinga už komandas cout ir cin.
#include <fstream> // biblioteka atsakinga už komandas ifstream ir ofstream.
#include <iomanip> // biblioteka programoje nuskaito setprecision komandą.

using namespace std; // priklauso standartinės funkcijos ir kintamieji.

//duomenų ir rezultatų failų aprašymas.
const char duomenu_failas [] = "Duomenys.txt"; // Duomenų failo vardas.
const char rezultatu_failas [] = "Rezultatai.txt"; // Rezultatų failo vardas.

int tikrinimas1(int a, int p) // funkcija, tikrinanti ar pateikti duomenys atitinka reikalavimus.
{
    if(p <= 1 || a >= 1000) // sąlyga, jei p mažiau lygu ir a daugiau lygu 1000.
    {
        cout << "Duomenys yra neteisingi.";// išvedama, jog duomenys neatitinka reikalavimų.

        return -1;
    }
    return 0;
}

int siena() // funkcija, skaičiuojanti sienos plotą.
{
    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, į konsolė išvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        int p, // sienos plotis.
        a, // sienos aukštis.
        P; // sienos plotas.

        df >> p >> a; // nuskaitomi kintamieji duomenų faile.
        tikrinimas1(p, a); // iškviečiama funkcija "tikrinimas".
        P = p * a; // sienos plotas apskaičiuojamas plotį dauginant su aukščiu.

        df.close(); // uždaromas duomenų failas.

        return P; // grąžinamas gautas sienos plotas.
    }
}

int tikrinimas2 (int N)
{
    if (1 >= N >= 1000)
    {
        cout << "Duomenys yra neteisingi.";// išvedama, jog duomenys neatitinka reikalavimų.

        return -1;
    }
    return 0;
}

int tikrinimas3 (int x1, int y1, int x2, int y2)
{
    if (0 >= x1 > x2 >= p; 0 >= y1 > y2 >= a)
    {
        cout << "Duomenys yra neteisingi.";// išvedama, jog duomenys neatitinka reikalavimų.

        return -1;
    }
    return 0;
}

int plakatai() // funkcija, skaičiuojanti visų plakatų plotą.
{
    ifstream df (duomenu_failas); // failo skaitymas.
    if (!df) // Patikra.
    {
        cout << "Failas neatidarytas." << endl; // jeigu failas neatsidaro, į konsolė išvedama, jog failo atidaryti nepavyko.

        return -1;
    }
    else
    {
        int x1, // atstumas nuo kairiojo sienos krašto iki kairiosios plakato kraštinės.
        x2, // atstumas nuo kairiojo sienos krašto iki dešiniosios plakato kraštinės.
        y1, // atstumas nuo apatinio sienos krašto iki apatinės plakato kraštinės.
        y2, // atstumas nuo apatinio sienos krašto iki viršutinės plakato kraštinės.
        P, // plakatų plotas
        N, // plakatų kiekis.
        z, // pločio kintamasis
        w; // aukščio kintamasis.

        P = 0; // plotui duodama  reikšmė.

        df >> z >> w; // nuskaitomos ir saugomos pločio ir aukščio reikšmės.
        df >> N; // duomenų failas  nuskaito plakatų kiekio kintamąjį.

        tikrinimas2( N ); // iškviečiama tikrinimo funkcija.
        tikrinimas3(x1, y1, x2, y2); // iškviečiama tikrinimo funkcija.

        for ( int i = 0; i < N; i++) // i didės tol, kol bus vienetu mažesnis už N.
        {
            df >> x1 >> y1 >> x2 >> y2; // nuskaitomi kintamieji.

            int A = y2 - y1; // randame plakto aukštį.
            int B = x2 - x1; // randame plakato plotį.
            P += A * B; // P = P + A * B. Randame bendrą plakatų plotą.
        }
        df.close(); // uždaromas duomenų failas.
        return P; // grąžinamas bendras plakatų plotas.
    }
    return 0;
}

int neuzdengta() // funkcija, skaičiuojanti neuždengtą sienos plotą.
{
    int neuzdengtas_plotas; // neuždengto ploto kintamasis.

    int Psiena = siena(); // Sienos plotas lygus funkcijos siena rezultatui.
    int Pplakatai = plakatai(); // Plakatų plotas lygus plakatai rezultatui.
    neuzdengtas_plotas = Psiena - Pplakatai; // neuzdengtas sienos plotas gaunamas is sienos ploto atėmus plakatų plotą.

    return neuzdengtas_plotas; // grąžinama gauta neuždengto sienos ploto reikšmė.
}

int main() // pagrindinė programos funkcija.
{
    int neuzdengta_siena = neuzdengta(); //neuždengtos sienos plotas lygus neuzdengta funkcijai.
    ofstream rf (rezultatu_failas); // atidarome rezultatų failą.
    rf << neuzdengta_siena; // į rezultatų failą įrašomas neuždengtos sienos plotas.
    rf.close(); // uždaromas rezultatų failas.

    return 0;
}
