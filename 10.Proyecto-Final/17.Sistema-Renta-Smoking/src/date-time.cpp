#include <iostream>
#include <string>
#include <ctime>
#include "../headers/date-time.hpp"
using namespace std;

int day(tm *ltm){
    return ltm->tm_mday;  
}

int month(tm *ltm){
    return 1 + ltm->tm_mon;
}

int year(tm *ltm){
    return 1900 + ltm->tm_year;
}

int hour(tm *ltm){
    return ltm->tm_hour;
}

int minutes(tm *ltm){
    return ltm->tm_min;
}

int seconds(tm *ltm){
    return ltm->tm_sec;
}