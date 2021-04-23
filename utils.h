//
// Created by Alysson Rocha on 13/04/2021.
//

#ifndef EXERCICIO1_UTILS_H
#define EXERCICIO1_UTILS_H

#include <string>
#include <vector>

using namespace std;

class Utils {
    public:
        enum Days {TODAY, YESTERDAY, BEFORE_YESTERDAY};
        enum MovingAverageStatus{UPTREND, DOWNTREND, SIDEWAY};
        static string getStringFromMovingAverageStatuses(MovingAverageStatus status);
        static const int daysInMovingAverage = 7;
        static float getMovingAverage(Days day, vector<float> deathsByDay);
        static MovingAverageStatus getMovingAverageStatus(vector<float> deathsByDay);
        static float percentageVariation(vector<float> deathsByDay);
};


#endif //EXERCICIO1_UTILS_H
