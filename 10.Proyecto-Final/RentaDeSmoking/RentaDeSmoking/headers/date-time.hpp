#pragma once

int day(tm *);
int month(tm *);
int year(tm *);
int hour(tm *);
int minutes(tm *);
int seconds(tm *);
std::string getDate(tm *);
std::string getTime(tm *);
void returnDate(int &, int &, int &);
void validDate(int &, int &, int &);
