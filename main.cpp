#include <iostream>
#include "state.h"
#include <vector>
#include "country.h"

Country initData();

void pressEnterToContinue();

void menu();

using namespace std;

int main() {
    Country brazil = initData();

    int choice;
    do {
        menu();
        cin >> choice;
        cout << " " << endl;

        if (choice == 0) {
            cout << "" << endl;
            cout << "Encerrando programa..." << endl;
            cout << "" << endl;

        } else if (choice == 1) {
            int option;
            cout << "Escolha o dia: " << endl;
            cout << "(1) Hoje" << endl;
            cout << "(2) Ontem" << endl;
            cout << "(3) Antes de ontem" << endl;
            cout << " " << endl;

            cin >> option;
            brazil.selectMovingAverageByDay(option);

        } else if (choice == 2) {
            brazil.printStatesGroupedByStatus();

        } else if (choice == 3) {
            brazil.printCountryMovingAverageStatus();

        } else if (choice == 4) {
            brazil.printMaxAndMinPercentageVariation();

        } else if (choice == 5) {
            brazil.printAllDeaths();

        } else {
            cout << "Opcao invalida" << endl;
        }

        if( choice != 0) {
            pressEnterToContinue();
        }


    } while (choice != 0);
    return 0;
}

void menu() {
    cout << "*---- MENU -----*" << endl;
    cout << "(1) Media Movel do Brasil e dos estados" << endl;
    cout << "(2) Status das medias moveis dos estados" << endl;
    cout << "(3) Status da media movel do Brasil" << endl;
    cout << "(4) Estado com maior alta e maior baixa" << endl;
    cout << "(5) Total de mortes" << endl;
    cout << "(0) Finalizar programa" << endl;
    cout << "" << endl;
    cout << "Selecione uma opcao: " << endl;
}

void pressEnterToContinue() {
    cout << "" << endl;
    cout << "Aperte enter para continuar..." << endl;
    cin.ignore();
    cin.get();
    cout << "" << endl;
}

Country initData() {
    Country brazil("Brasil");
    vector<float> deathsByDayRJ{200, 00, 200, 400, 120, 200, 700, 300, 300};
    vector<float> deathsByDaySP{100, 700, 200, 400, 120, 200, 700, 300, 280};
    vector<float> deathsByDayBA{3023, 134, 312, 432, 122, 432, 1280, 312, 323};
    vector<float> deathsByDayRS{50, 10, 10, 20, 33, 23, 150, 32, 232};
    vector<float> deathsByDayAM{232, 323, 312, 321, 12, 66, 86, 76, 54};
    State RJ("Rio de Janeiro", deathsByDayRJ);
    State SP("Sao Paulo", deathsByDaySP);
    State BA("Bahia", deathsByDayBA);
    State RS("Rio Grande do Sul", deathsByDayRS);
    State AM("Amazonas", deathsByDayAM);

    brazil.addState(RJ);
    brazil.addState(SP);
    brazil.addState(BA);
    brazil.addState(RS);
    brazil.addState(AM);
    return brazil;
}

