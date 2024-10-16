#include <iostream>
#include<math.h>

using namespace std;

static enum class ErrorCodes
{
    // no 0
    ERROR_STRING_INPUT = 10, 
};

int main(int argc, char* argv[])
{
    long num = 0;
    
    cout << "Please enter a number: ";
    cin >> num;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cerr << "Received a string instead on a number, restarting." << endl;
        return (int)ErrorCodes::ERROR_STRING_INPUT;
    }

    cout << "neg(x): " << num * -1 << endl;
    cout << "abs(x): " << abs(num) << endl;
    cout << "pow2(x): " << powf(num, 2) << endl;
    cout << "pow3(x): " << powf(num, 3) << endl;
    cout << "sqrt(x): " << sqrtl(num) << endl;
    cout << "floor(x): " << floorf(num) << endl;
    cout << "ceil(x): " << ceilf(num) << endl;
    cout << "round(x): " << roundf(num) << endl;

    return 0;
}