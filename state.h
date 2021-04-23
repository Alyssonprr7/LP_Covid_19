//
// Created by Alysson Rocha on 10/04/2021.
//

#ifndef EXERCICIO1_STATE_H
#define EXERCICIO1_STATE_H

#include <vector>
#include <string>
#include "utils.h"

using namespace std;

class State {
    private:
        string name;
        vector <float> deathsByDay;
        static const int daysInMovingAverage = 7;

    public:
       State(string name, vector<float> deathsByDay);
       void setName(string newName);
       void setDeathsByDay(vector<float> newDeaths);
       string getName();
       float getMovingAverage(Utils::Days day);
       Utils::MovingAverageStatus getMovingAverageStatuses();
       float getAllDeaths();
       vector<float> getDeathsByDay();
};


#endif //EXERCICIO1_STATE_H
