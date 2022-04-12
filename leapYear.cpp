// Copyright (c) 2022 Nicolas Riscalas All rights reserved.
//
// Created by: Nicolas Riscalas
// Created on: April 12 2022
// This program figures out if you can date the grand child

///////////////////////////////////////////////////////////////
// LIBRARIES
///////////////////////////////////////////////////////////////
#include <iostream>

///////////////////////////////////////////////////////////////
// STD::SHORTCUTS
///////////////////////////////////////////////////////////////
using std::cout;
using std::cin;
using std::string;


int main() {
    // variables
    string dayStr, monthStr, yearStr;
    int day, month, year, dayWeekNum;
    // inputs
    cout << "What day of the month is it: ";
    cin >> dayStr;
    cout << "Enter the number value of the month: ";
    cin >> monthStr;
    cout << "What year is it: ";
    cin >> yearStr;
    // try catch
    try {
        day = std::stoi(dayStr);
        month = std::stoi(monthStr);
        year = std::stoi(yearStr);
    } catch (std::invalid_argument) {
        cout << "You have to input an integer greater than 0\n";
        main();
    }
    // check if lower than 0
    if (day < 0 || month < 0 || year < 0) {
        cout << "You have to input an integer greater than 0";
        main();
    }
    // doomsday
    static int doomsday[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    dayWeekNum = (year + year / 4 - year / 100 +
             year / 400 + doomsday[month - 1] + day) % 7;
    // switch case for displaying
    switch (dayWeekNum) {
        case 1:
            cout << "The day of the week is Monday\n";
            break;
        case 2:
            cout << "The day of the week is Tuesday\n";
            break;
        case 3:
            cout << "The day of the week is Wednesday\n";
            break;
        case 4:
            cout << "The day of the week is Thursday\n";
            break;
        case 5:
            cout << "The day of the week is Friday\n";
            break;
        case 6:
            cout << "The day of the week is Saturday\n";
            break;
        case 7:
            cout << "The day of the week is Sunday\n";
            break;
    }
    // logic for checking if leap year
    if (year % 4 == 0) {
        if (year % 100 == 0 && year % 400 != 0) {
            cout << "This year is not a leap year";
        } else {
            cout << "This year is a leap year";
        }
    } else {
        cout << "This year is not a leap year";
    }
}
