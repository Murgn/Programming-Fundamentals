#include <iostream>
#include <iomanip>
#include <string>
#include <clocale>
using namespace std;

char pound = 156; // The pound symbol isn't supported by typing "£", so I use this workaround instead.

int main()
{
    cout << fixed << setprecision(2); // Caps the numbers at two decimal places to represent money.

    int income;
    cout << "What's your yearly salary?" << endl << pound;
    cin >> income;

    int taxable = income - 12570;
    int tax = taxable * 0.2;

    int cSize = 15; // Column Size
  

    cout << left << setw(cSize) << ""
         << right << setw(cSize) << "Yearly"
         << right << setw(cSize) << "Monthly"
         << right << setw(cSize) << "Weekly"
         << right << setw(cSize) << "Daily" << endl;

    cout << left << setw(cSize) << "Gross Income"
         << right << setw(cSize) << pound << income
         << right << setw(cSize) << pound << income / 12.0
         << right << setw(cSize) << pound << income / 12.0 / 4.333
         << right << setw(cSize) << pound << income / 12.0 / 4.333 / 5.0 << endl;
    
    
    cout << left << setw(cSize) << "Taxable Income"
         << right << setw(cSize) << pound << taxable
         << right << setw(cSize) << pound << taxable / 12.0
         << right << setw(cSize) << pound << taxable / 12.0 / 4.333
         << right << setw(cSize) << pound << taxable / 12.0 / 4.333 / 5.0 << endl;

    cout << left << setw(cSize) << "Tax"
         << right << setw(cSize) << pound << tax
         << right << setw(cSize) << pound << tax / 12.0
         << right << setw(cSize) << pound << tax / 12.0 / 4.333
         << right << setw(cSize) << pound << tax / 12.0 / 4.333 / 5.0 << endl;

    cout << left << setw(cSize) << "Take Home"
         << right << setw(cSize) << pound << (income - tax)
         << right << setw(cSize) << pound << (income - tax) / 12.0
         << right << setw(cSize) << pound << (income - tax) / 12.0 / 4.333
         << right << setw(cSize) << pound << (income - tax) / 12.0 / 4.333 / 5.0 << endl;
}

/*
*   I had a lot of trouble trying to get the table alignment working,
    I was looking through documentation and forum posts but this was the best i could do.

    I learnt that I could use "left" and "right" alongside "setw" to change the alignment
    of my text and change the width of the cells that text occupies.
*/

