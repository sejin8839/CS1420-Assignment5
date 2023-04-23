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

int getMode(int* arr, int size)
{
    int mode = -1, maxCount = 0;
    for(int i = 0; i < size; i++)
    {
        int count = 0;
        for(int j = 0; j < size; j++)
        {
            if(*(arr + j) == *(arr + i)) // Compare values using pointer notation
                count++;
        }
        if(count > maxCount) // Check if the current count is greater than the previous maximum count
        {
            maxCount = count;
            mode = *(arr + i); // Update mode with the current value
        }
    }
    if(maxCount < 2) // If no value occurs more than once, return -1
        mode = -1;
    return mode;
}