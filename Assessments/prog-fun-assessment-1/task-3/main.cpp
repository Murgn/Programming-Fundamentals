#include <iostream>
#include<math.h>

using namespace std;

enum ErrorCodes
{
    // no 0
    ERROR_STRING_INPUT = 10, 
};

int main(int argc, char* argv[])
{
    float num = 0;
    
    cout << "Please enter a number: ";
    cin >> num;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cerr << "[!] Received a string instead on a number, restarting." << endl;
        return ErrorCodes::ERROR_STRING_INPUT;
    }

    cout << "neg(x): " << num * -1 << endl;
    cout << "abs(x): " << abs(num) << endl;
    cout << "pow2(x): " << powf(num, 2) << endl;
    // For these next ones, I believe we are meant to absolute the number even though it doesn't state to do so in the question.
    // Before I added the abs into my code, my console would output negative numbers and sqrt would result in a NaN,
    // So I added the abs in and now my console results in the same output for -5.5 as the output for Example 1.
    cout << "pow3(x): " << powf(abs(num), 3) << endl;
    cout << "sqrt(x): " << sqrtf(abs(num)) << endl;
    cout << "floor(x): " << floorf(abs(num)) << endl;
    cout << "ceil(x): " << ceilf(abs(num)) << endl;
    cout << "round(x): " << roundf(abs(num)) << endl;

    return 0;
}