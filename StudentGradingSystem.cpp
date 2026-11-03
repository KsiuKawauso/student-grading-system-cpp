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
}