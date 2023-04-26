/*
Author: Sejin Yoon
Date: Feb, 23. 2023.
filename: Assignment5_P3.cpp
*/

#include <iostream>

using namespace std;

//Mode Function prototype

int getMode(int*,int);

int main()
{

    int * number,SIZE;
    cout<<"Enter the number of integers:  ";
    cin>>SIZE;
    number=new int[SIZE];// memory allocation
    cout<<"\nEnter "<<SIZE<<" integer numbers greater than zero"<<endl;
    for(int i=0; i<SIZE; i++)
         cin>>*(number+i); //read the numbers

int mode = getMode(number,SIZE); //function call 

if(mode == -1)
   cout<<"\nThere is no mode of these numbers."<<endl;
else
    cout<<"Mode = "<<mode<<endl;
delete [] number;
number =nullptr;
}

//Mode Function definition

int getMode(int* arr, int SIZE) 
{
    int mode = -1; // initialize the mode to -1
    int maxFreq = 0; // initialize the maximum frequency to 0

    for (int i = 0; i < SIZE; i++) {
        int freq = 0; // initialize the frequency of the current element to 0
        for (int j = 0; j < SIZE; j++) {
            if (*(arr + j) == *(arr + i)) {
                freq++; // increment the frequency if the current element matches
            }
        }
        if (freq > maxFreq) { // if the current element has a higher frequency than the current mode
            mode = *(arr + i); // set the current element as the new mode
            maxFreq = freq; // update the maximum frequency
        }
    }

    if (maxFreq == 1) { // if there is no mode
        mode = -1;
    }

    return mode;
}