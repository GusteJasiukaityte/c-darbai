// Prijungiiame bibliotekas.
#include <iostream> // biblioteka atsakinga u� komandas cout ir cin.
#include <fstream> // biblioteka atsakinga u� komandas ifstream ir ofstream.

using namespace std; // priklauso standartin�s funkcijos ir kintamieji.

void duomenys (string vardas, string pavarde, int amzius, string profesija); // programai prane�ama apie funkcijos egzistavim�.

int main() // pagrindin� programos funkcija.
{
    setlocale(LC_ALL, "Lithuanian");  // i�vedimui naudosime lietuvi� kalb�.

    duomenys ("Petras",  "Petraitis", 26, "ugniagesys"); // i�kvie�iama funkcija �duomenys�.
    duomenys ("Matas",  "Matulionis", 30, "in�inierius"); // i�kvie�ima funkcija �duomenys�.

    return 0; //programa u�baigta ir �vykdyta s�kmingai.
}

void duomenys (string vardas, string pavarde, int amzius, string profesija) // void tipo funkcija, pavadinimu �duomenys�.
{
    cout << vardas << " " << pavarde << ", " << amzius << " met�, yra " << profesija << "." << endl; // � konsol� i�vedamas atsakymas.
}
