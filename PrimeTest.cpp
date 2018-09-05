#include <stdio.h>
#include<iostream>
#include <math.h>
#include <chrono>
#include <conio.h>

using namespace std;
using namespace std::chrono;

unsigned long long int check_for_prime(unsigned long long int num)
{
    unsigned long long int lowest_factor = num;

    if(num%2==0)
        lowest_factor=2;
    else if(num%3==0)
        lowest_factor=3;
                
    else
    {
        unsigned long long int sqr_root = floor(sqrt(num));
                          
        for (unsigned long long int i=5; i <= sqr_root; i+=6)
        {
            if(num%i == 0)
            {
                lowest_factor=i;
                break;
            }
            else if(num%(i+2) == 0)
            {
                lowest_factor=i+2;
                break;
            }
        }
    }

    return lowest_factor;
}

int main()
{
    //unsigned long long int num = 101012345678989;
    cout << "Enter the number to test: " << endl;
    unsigned long long num;
    cin >> num;
    cin.ignore();
    cout << endl;

    cout <<"\nTesting primality for the number: " << num;

    //start = time.time()
    high_resolution_clock::time_point start = high_resolution_clock::now();

    unsigned long long int lowest_factor = check_for_prime(num);

    if(num > lowest_factor)
        cout << "\n\n" << num << " is not a prime number. The lowest factor is: " << lowest_factor;
    else
        cout << "\n\n" << num << " is a prime number";

    //done = time.time()
   high_resolution_clock::time_point done = high_resolution_clock::now();

    //elapsed = done - start
    auto duration = duration_cast<microseconds>( done - start ).count();

    cout << "\n\nTime taken: " << duration*0.000001 << " seconds\n";

    //print("Time taken: ", elapsed)
   cout << "\n\nPress any key to exit: ";
   getch();
   return 0;
}