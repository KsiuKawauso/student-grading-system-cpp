#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int MaxMok = 100;
    const int MaxPaz = 10;

    string vard[MaxMok];
    int Paz[MaxMok][MaxPaz];
    int PazKiek[MaxMok] ={0};

    int MokKiek = 0;
    int pasirinkimas;

    do {
        cout << "\n--- MOKINIU PAZYMIU SISTEMA ---\n";
        cout << "1. Ivesti mokini ir jo pazymius\n";
        cout << "2. Perziureti visu mokiniu pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Apskaiciuoti mokinio vidurki\n";
        cout << "6. Pasalinti mokini\n";
        cout << "7. Iseiti\n";
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        if (pasirinkimas < 1 || pasirinkimas > 7) {
            cout << "Klaida! Pasirinkite skaiciu nuo 1 iki 7.\n";
            continue;
        }
        if (pasirinkimas == 7) {
            cout << "Programa baigta.\n";
            break;
        }

        if (pasirinkimas == 1) {
            if (MokKiek >= MaxMok) {
                cout << "Mokiniu sarasas pilnas.\n";
                continue;
            }

            cout << "Iveskite mokinio varda: ";
            cin >> vard[MokKiek];

            int Kiek;
            cout << "Kiek pazymiu norite ivesti (0-10)? ";
            cin >> Kiek;

            while (Kiek < 0 || Kiek > MaxPaz) {
                cout << "Klaida! Iveskite skaiciu nuo 0 iki 10: ";
                cin >> Kiek;
            }

            PazKiek[MokKiek] = Kiek;

            for (int j = 0; j < Kiek; j++) {
                cout << "Iveskite " << j + 1 << "-aji pazymi (1-10): ";
                cin >> Paz[MokKiek][j];

                while (Paz[MokKiek][j] < 1 || Paz[MokKiek][j] > 10) {
                    cout << "Klaida! Pazymys turi buti nuo 1 iki 10: ";
                    cin >> Paz[MokKiek][j];
                }
            }
            MokKiek++;
            cout << "Mokinys sekmingai pridetas.\n";
        }

        else if (pasirinkimas == 2) {
            if (MokKiek == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
                continue;
            }

            for (int i = 0; i < MokKiek; i++) {
                cout << "\nMokinys " << i + 1 << ": " << vard[i] << endl;
                cout << "Pazymiai: ";

                if (PazKiek[i] == 0) {
                    cout << "Pazymiu nera";
                } else {
                    for (int j = 0; j < PazKiek[i]; j++) {
                        cout << Paz[i][j] << " ";
                    }
                }

                cout << endl;
            }
        }

        else if (pasirinkimas == 3) {
            if (MokKiek == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
                continue;
            }

            int nr;
            cout << "Iveskite mokinio numeri (1-" << MokKiek << "): ";
            cin >> nr;

            while (nr < 1 || nr > MokKiek) {
                cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << MokKiek << ": ";
                cin >> nr;
            }

            int i = nr - 1;
            cout << vard[i] << " pazymiai: ";

            if (PazKiek[i] == 0) {
                cout << "Pazymiu nera";
            } else {
                for (int j = 0; j < PazKiek[i]; j++) {
                    cout << Paz[i][j] << " ";
                }
            }

            cout << endl;
        }

        else if (pasirinkimas == 4) {
            if (MokKiek == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
                continue;
            }

            int nr, PazNr;

            cout << "Iveskite mokinio numeri (1-" << MokKiek << "): ";
            cin >> nr;

            while (nr < 1 || nr > MokKiek) {
                cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki "
                     << MokKiek << ": ";
                cin >> nr;
            }

            int i = nr - 1;

            if (PazKiek[i] == 0) {
                cout << "Sis mokinys neturi pazymiu.\n";
                continue;
            }

            cout << "Iveskite pazymio numeri (1-" << PazKiek[i] << "): ";
            cin >> PazNr;

            while (PazNr < 1 || PazNr > PazKiek[i]) {
                cout << "Neteisingas pazymio numeris. Iveskite skaiciu nuo 1 iki " << PazKiek[i] << ": ";
                cin >> PazNr;
            }

            int j = PazNr - 1;
            int NewPaz;

            cout << "Iveskite nauja pazymi (1-10): ";
            cin >> NewPaz;

            while (NewPaz < 1 || NewPaz > 10) {
                cout << "Klaida! Pazymys turi buti nuo 1 iki 10: ";
                cin >> NewPaz;
            }

            Paz[i][j] = NewPaz;
            cout << "Pazymys atnaujintas.\n";
        }

        else if (pasirinkimas == 5) {
            if (MokKiek == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
                continue;
            }

            int nr;

            cout << "Iveskite mokinio numeri (1-" << MokKiek << "): ";
            cin >> nr;

            while (nr < 1 || nr > MokKiek) {
                cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << MokKiek << ": ";
                cin >> nr;
            }

            int i = nr - 1;

            if (PazKiek[i] == 0) {
                cout << "Sis mokinys neturi pazymiu.\n";
                continue;
            }

            double suma = 0;

            for (int j = 0; j < PazKiek[i]; j++) {
                suma += Paz[i][j];
            }

            double vidurkis = suma /PazKiek[i];

            cout << fixed << setprecision(2);
            cout << vard[i] << " pazymiu vidurkis: " << vidurkis << endl;
        }


        else if (pasirinkimas == 6) {
            if (MokKiek == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
                continue;
            }

            int nr;

            cout << "Iveskite mokinio numeri (1-" << MokKiek << "): ";
            cin >> nr;

            while (nr < 1 || nr > MokKiek) {
                cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki "
                     << MokKiek << ": ";
                cin >> nr;
            }

            int i = nr - 1;

            for (int j = i; j < MokKiek - 1; j++) {
                vard[j] = vard[j + 1];
                PazKiek[j] = PazKiek[j + 1];

                for (int k = 0; k < MaxPaz; k++) {
                    Paz[j][k] = Paz[j + 1][k];
                }
            }

            MokKiek--;
            cout << "Mokinys pasalintas.\n";
        }
        } while (true);

    return 0;

}