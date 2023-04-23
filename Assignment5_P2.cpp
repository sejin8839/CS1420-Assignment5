/*
Author: Sejin Yoon
Date: Feb, 23. 2023.
filename: Assignment5_P2.cpp
*/

#include <iostream>

using namespace std;
int main()
{
int a, b, c, *p[3] = {&a, &b, &c};
// It is not allowed to use again the a, b, c.

    // Read the lengths of the sides from the user
    for (int i = 0; i < 3; i++) {
        do {
            cout << "Enter the length of side " << i+1 << ": ";
            cin >> *p[i];
        } while (*p[i] <= 0); // Force the user to enter a positive value
    }

    // Check if the triangle is valid (c must be greater than a and b)
    if (c < a + b) {
        // Determine the type of the triangle based on the converse of the Pythagorean Theorem
        if (a*a + b*b == c*c) {
            cout << "The triangle is right." << endl;
        } else if (a*a + b*b < c*c) {
            cout << "The triangle is obtuse." << endl;
        } else {
            cout << "The triangle is acute." << endl;
        }
    } else {
        cout << "The lengths of the sides do not form a valid triangle." << endl;
    }

    return 0;
}