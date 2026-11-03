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
        cout << "\n--- MOKYNIU PAZYMIU SYSTEMA ---\n";
        cout << "1. Įvesti mokinį ir jo pažymius.\n";
        cout << "2. Peržiūrėti visų mokinių pažymius.\n";
        cout << "3. Peržiūrėti konkretaus mokinio pažymius.\n";
        cout << "4. Atnaujinti pažymį.\n";
        cout << "5. Apskaičiuoti mokinio vidurkį.\n";
        cout << "6. Pašalinti mokinį.\n";
        cout << "7. Įvesti mokinį ir jo pažymius.\n";
        cin >> pasirinkimas;

        if (pasirinkimas , 1 || pasirinkimas > 7) {
            cout << "Klaida! Pasirinkite skaiciu nuo 1 iki 7.\n";
            continue;
        }
        if (pasirinkimas == 7) {
            cout << "Programa baigta.\n";
            break;
        }

        // 1. Mokinio ir pazymiu ivedimas
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

        else if (pasirinkimas == 3) {
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
}