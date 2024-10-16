#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

double factorial(double n);


int main()
{
    cout << 5 + 5 << "\n"; // Results in 10

    cout << 355 / 133 << "\n"; // Results in 2

    cout << 355.0f / 133.0f << "\n"; // Results in 2.66917 because the numbers can now have decimal points

    cout << 503 * 92 << "\n"; // 46276

    // Print out the numbers 1 to 10 using only the + operator and without loops (    WHAAAAAAAAAT    )
    cout << 0 + 1 << "\n";
    cout << 1 + 1 << "\n";
    cout << 2 + 1 << "\n";
    cout << 2 + 2 << "\n";
    cout << 2 + 3 << "\n";
    cout << 3 + 3 << "\n";
    cout << 3 + 4 << "\n";
    cout << 4 + 4 << "\n";
    cout << 4 + 5 << "\n";
    cout << 5 + 5 << "\n";

    cout << 5 * 4 * 3 * 2 * 1 << "\n"; // 5! (5 factorial)

    // THE SIX TIMES TABLES!!
    cout << "6 * 1 = " << 6 * 1 << "\n";
    cout << "6 * 2 = " << 6 * 2 << "\n";
    cout << "6 * 3 = " << 6 * 3 << "\n";
    cout << "6 * 4 = " << 6 * 4 << "\n";
    cout << "6 * 5 = " << 6 * 5 << "\n";
    cout << "6 * 6 = " << 6 * 6 << "\n";
    cout << "6 * 7 = " << 6 * 7 << "\n";
    cout << "6 * 8 = " << 6 * 8 << "\n";
    cout << "6 * 9 = " << 6 * 9 << "\n";
    cout << "6 * 10 = " << 6 * 10 << "\n";
    cout << "6 * 11 = " << 6 * 11 << "\n";
    cout << "6 * 12 = " << 6 * 12 << "\n";

    // And as a loop
    for (int i = 1; i <= 12; i++)
    {
        cout << "6 * " << i << " = " << 6 * i << "\n";
    }

    cout << ((919 * -1) - 6) / 2.56 << "\n"; // -361.328

    cout << (15 + 20 + 25 + 30) / 4 << "\n"; // Mean of all numbers = 22

    cout << 0.5f + 0.75f << "\n"; // Add the two fractions ½ and ¾ together and print out the result = 1.25

    cout << powf(73.0f, 2.0f) << "\n"; // Calculate 73 to the power of 2 and print it out = 5329
    cout << powf(73.0f, 4.0f) << "\n"; // Calculate 73 to the power of 2 and print it out = 2.83982e+07

    // The formula for linear interpolation is: p = a + (b – a) * t, where t is in the range [0, 1]. 
    // Calculate what the value p is when: a = 10, b = 20, and t = 0.35, and print it out.

    cout << 10 + (20 - 10) * 0.35 << "\n"; // 13.5

    cout << 18.0f * 0.43f << "\n"; // 7.74

    // Convert, and print out what 65 degrees are in radians. Print this out in the format “65 degrees = {radians here} radians”,
    // using std::cout.

    cout << "65 degrees = " << 65 * (M_PI / 180) << " radians" << "\n"; // 1.13446 radians

    // I COULDNT GET FACTORIAL WORKING!!!!!!!!!!!!!!!!
    /*double e = 0;
    e = 1.0 + (1.0 / factorial(1)) + (2.0 / factorial(2)) + (3.0 / factorial(3)) + (4.0 / factorial(4));
    cout << e << "\n";

    cout << factorial(57);*/


    
}

// I COULDNT GET FACTORIAL WORKING!!!!!!!!!!!!!!!!
// Code "stolen" from stackoverflow :P
//double factorial(double n)
//{
//    if (n == 0)
//        return 1;
//    int i = n, fact = 1;
//    while (n / i != n) {
//        fact = fact * i;
//        i--;
//    }
//    return fact;
//}

