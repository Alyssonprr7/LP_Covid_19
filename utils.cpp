//
// Created by Alysson Rocha on 13/04/2021.
//

#include "utils.h"

string Utils::getStringFromMovingAverageStatuses(Utils::MovingAverageStatus status) {
    string statusString = " Nao encontrado";
    switch (status) {
        case UPTREND:
            statusString = "Em Alta";
        case SIDEWAY:
            statusString = "Em estabilidade";
        case DOWNTREND:
            statusString = "Em Queda";
    }
    return statusString;
}

float Utils::getMovingAverage(Utils::Days day, vector<float> deathsByDay) {
    float sum = 0;
    int initCountOnVector;

    if (day == Utils::TODAY) {
        initCountOnVector = deathsByDay.size() - 1;
    } else if (day == Utils::YESTERDAY) {
        initCountOnVector = deathsByDay.size() - 2;
    } else {
        initCountOnVector = deathsByDay.size() - 3;
    }

    for (int i = initCountOnVector; i > initCountOnVector - daysInMovingAverage; i--) {
        sum += deathsByDay[i];
    }
    return sum / daysInMovingAverage;
}

///Geralmente, para se concluir que um Estado (ou país) está em Alta, estabilidade ou queda,
///Utiliza-se a comparação da média móvel de hoje com a de 14 dias atrás
///Porém, como s trata de uma PoC, utilizaremos a comparação baseada no dia anterior.
Utils::MovingAverageStatus Utils::getMovingAverageStatus(vector<float> deathsByDay) {
    const int parameterToPercentage = 15;
    float percentageDifference = percentageVariation(deathsByDay);

    if (percentageDifference > parameterToPercentage) {
        return Utils::UPTREND;
    } else if (percentageDifference <= -parameterToPercentage) {
        return Utils::DOWNTREND;
    } else {
        return Utils::SIDEWAY;
    }
}

float Utils::percentageVariation(vector<float> deathsByDay) {
    float todayMovingAverage = getMovingAverage(Utils::TODAY, deathsByDay);
    float yesterdayMovingAverage = getMovingAverage(Utils::YESTERDAY, deathsByDay);

    float percentageDifference = (todayMovingAverage - yesterdayMovingAverage) * 100 / yesterdayMovingAverage;

    return percentageDifference;
}
