//
// Created by Alysson Rocha on 10/04/2021.
//

#include "state.h"

State::State(string name, vector<float> deathsByDay) {
    setName(name);
    setDeathsByDay(deathsByDay);

}

void State::setName(string newName) {
    name = newName;
}

void State::setDeathsByDay(vector<float> newDeaths) {
    deathsByDay = newDeaths;
}

string State::getName() {
    return name;
}

float State::getMovingAverage(Utils::Days day) {
    return Utils::getMovingAverage(day, deathsByDay);;
}

Utils::MovingAverageStatus State::getMovingAverageStatuses() {
    return Utils::getMovingAverageStatus(deathsByDay);
}

float State::getAllDeaths() {
    float allDeaths = 0;
    for (size_t i = 0; i < deathsByDay.size(); i++) {
        allDeaths += deathsByDay[i];
    }
    return allDeaths;
}

vector<float> State::getDeathsByDay() {
    return deathsByDay;
}
