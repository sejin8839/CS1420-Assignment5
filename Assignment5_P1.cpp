/*
Author: Sejin Yoon
Date: Feb, 23. 2023.
filename: Assignment5_P1.cpp
*/

#include <iostream>

using namespace std;


int main()
{
const int SIZE = 10;
int i, max_pos, min_pos;
float *p, max, min, arr[SIZE];
max = -1;
min = 11;

    for (i = 0, p = arr; i < SIZE; i++, p++)
    {
        do {
            cout << "Enter grade for student " << i+1 << " (0-10): ";
            cin >> *p;
        } while (*p < 0 || *p > 10); // Force the user to enter grades within [0, 10]
    
        if (*p > max) {
            max = *p;
            max_pos = i;
        }
        if (*p < min) {
            min = *p;
            min_pos = i;
        }
    }

    // Display the best and the worst grade and the positions of their first occurrences in the array
    
    cout << "The best grade is " << max << ", which is the grade of student " << max_pos+1 << endl;
    cout << "The worst grade is " << min << ", which is the grade of student " << min_pos+1 << endl;

    return 0;

}