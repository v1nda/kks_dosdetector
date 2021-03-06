#ifndef STATISTIC_H
#define STATISTIC_H

#include "../includes/sniffer.h"

#define PERCENTAGE_FOR_EXCESS 0.7

#define WARNING_DURING 0.6

#define WAIT_TRAINING_TIME 4
#define ANALISYS_TIME 5

class Statistic
{
private:
        int periodLength;
        int numberOfPeriods;
        bool analysisFlag;
        long long warningTime;
        long long alarmTime;

        float smoothingCoeff;
        int windowSize;
        int numberOfExcesses;
        long long standartDeviation;
        long long limit;

        long long smoothed;

        long long anomalysCount;
        bool fixingLimit;
        long long excessSeconds;
        long long maxExcessSeconds;
        long long maxAnomalyTraffic;
        long long averageAnomalyTraffic;

        long long averaging(std::vector<long long> &capture);
        long long smoothing(float smoothingCoeff, long long secondValue, long long firstValue);
        void smoothingCoeffCalculation(std::vector<long long> &capture);

        void anomalyChecking(long long excesses, long long traffic);

public:
        Statistic(int periodLength, int numberOfPeriods, long long warningTime, long long alarmTime, bool analysis);
        ~Statistic();

        void analysis(Timer &timer, std::vector<long long> &trainingCapture);
        void training(Timer &timer, Sniffer &sniffer);
        void detection(Timer &timer, Sniffer &sniffer);

        float getSmoothingCoeff();
        int getWindowSize();
        int getNumberOfExcesses();
        long long getWarningTime();
        long long getAlarmTime();

        long long getSmoothedValue();
        long long getLimit();
        long long getExcessSeconds();
        std::string getFixingLimit();
        long long getAnomalysCount();
        long long getMaxAnomalyTime();

};

#endif