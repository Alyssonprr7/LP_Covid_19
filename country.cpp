//
// Created by Alysson Rocha on 10/04/2021.
//

#include "country.h"
#include <iostream>
#include <iomanip>

void Country::addState(State state) {
    states.push_back(state);
}

void Country::setName(string newName) {
    name = newName;
}

Country::Country(string name) {
    setName(name);
}

string Country::getName() {
    return name;
}

float Country::getAllDeaths() {
    float allDeaths = 0;
    for (size_t i = 0; i < states.size(); i++) {
        allDeaths += states[i].getAllDeaths();
    }
    return allDeaths;
}

////Leva em consideração que todos os estados possuem dados desde um D0 comum
vector<float> Country::getDeathsByDay() {
    vector<float> deathsByDay;
    size_t daysPassed = 0;
    while (daysPassed < states[0].getDeathsByDay().size()) {
        float deathInDay = 0;
        for (size_t i = 0; i < states.size(); i++) {
            deathInDay += states[i].getDeathsByDay().at(daysPassed);
        }
        deathsByDay.push_back(deathInDay);
        daysPassed++;
    }

    return deathsByDay;
}

void Country::printStatesGroupedByStatus() {
    vector<State> uptrend;
    vector<State> downtrend;
    vector<State> sideway;
    for (size_t i = 0; i < states.size(); i++) {
        Utils::MovingAverageStatus status = states[i].getMovingAverageStatuses();

        if (status == Utils::UPTREND) {
            uptrend.push_back(states[i]);
        } else if (status == Utils::DOWNTREND) {
            downtrend.push_back(states[i]);
        } else {
            sideway.push_back(states[i]);
        }
    }

    cout << "Em alta" << endl;
    printGroupedVector(uptrend);

    cout << "Em estabilidade" << endl;
    printGroupedVector(sideway);

    cout << "Em queda" << endl;
    printGroupedVector(downtrend);
}

void Country::printGroupedVector(vector<State> states) {
    for (size_t i = 0; i < states.size(); i++) {
        cout << states[i].getName() << endl;
    }
    cout << " " << endl;
}

void Country::printMaxAndMinPercentageVariation() {
    State maxVariationState = states[0];
    State minVariationState = states[0];

    for (size_t i = 0; i < states.size(); i++) {
        if (Utils::percentageVariation(states[i].getDeathsByDay()) >
            Utils::percentageVariation(maxVariationState.getDeathsByDay())) {
            maxVariationState = states[i];
        } else if (Utils::percentageVariation(states[i].getDeathsByDay()) <
                   Utils::percentageVariation(minVariationState.getDeathsByDay())) {
            minVariationState = states[i];
        }
    }

    cout << maxVariationState.getName() << " teve a maior alta com " << setprecision(4)
         << Utils::percentageVariation(maxVariationState.getDeathsByDay()) << "%" << endl;
    cout << minVariationState.getName() << " teve a maior baixa com " << setprecision(4)
         << Utils::percentageVariation(minVariationState.getDeathsByDay()) << "%" << endl;
}

void Country::printMovingAveragesByDay(Utils::Days day) {
    cout << "" << endl;
    cout << name << ": " << Utils::getMovingAverage(day, getDeathsByDay()) << endl;
    cout << endl;
    cout << "Estados:" << endl;

    for (size_t i = 0; i < states.size(); i++) {
        cout << states[i].getName() << ": " << states[i].getMovingAverage(day) << endl;
    }
}

string Country::getCountryMovingAverageStatus() {
    vector<float> deathsByDay = getDeathsByDay();
    Utils::MovingAverageStatus status = Utils::getMovingAverageStatus(deathsByDay);

    return Utils::getStringFromMovingAverageStatuses(status);
}

void Country::selectMovingAverageByDay(int option) {
    if (option == 1) {
        printMovingAveragesByDay(Utils::TODAY);
    } else if (option == 2) {
        printMovingAveragesByDay(Utils::YESTERDAY);
    } else if (option == 3) {
        printMovingAveragesByDay(Utils::BEFORE_YESTERDAY);
    } else {
        cout << " " << endl;
        cout << "Opção Invalida" << endl;
    }
}

void Country::printCountryMovingAverageStatus() {
    cout << getName() << ": " << getCountryMovingAverageStatus() << endl;
}

void Country::printAllDeaths() {
    cout << "Total de mortes no " << getName() << ": " << setprecision(20) << getAllDeaths() << endl;
}








