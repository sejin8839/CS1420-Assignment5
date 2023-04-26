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

int getMode(int *arr, int SIZE)
{
    // Create an array to store the frequency of each number
    int freq[100] = {0};
    // Initialize the max frequency and mode to -1
    int maxFreq = -1, mode = -1;
    
    // Loop through the array of integers
    for (int i = 0; i < SIZE; i++)
    {
        // Increment the frequency of the current integer
        freq[arr[i]]++;
        // Update the mode and max frequency if a new maximum frequency is found
        if (freq[arr[i]] > maxFreq)
        {
            maxFreq = freq[arr[i]];
            mode = arr[i];
        }
    }
    
    // Check if there is no mode
    if (maxFreq == 1)
        return -1;
    else
        return mode;
}