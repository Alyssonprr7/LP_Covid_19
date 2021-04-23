//
// Created by Alysson Rocha on 10/04/2021.
//

#ifndef EXERCICIO1_COUNTRY_H
#define EXERCICIO1_COUNTRY_H

#include <vector>
#include "state.h"
#include <string>

using namespace std;

class Country {
    public:
        Country(string name);
        void addState(State state);
        void setName(string newName);
        string getName();
        float getAllDeaths();
        vector<float> getDeathsByDay();
        void printStatesGroupedByStatus();
        void printMaxAndMinPercentageVariation();
        void printMovingAveragesByDay(Utils::Days day);
        void selectMovingAverageByDay(int option);
        void printCountryMovingAverageStatus();
        void printAllDeaths();
        string getCountryMovingAverageStatus();



private:
        vector <State> states;
        string name;
        void printGroupedVector(vector<State> states);
};

#endif //EXERCICIO1_COUNTRY_H
