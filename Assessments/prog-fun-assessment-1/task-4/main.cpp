#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    while (true)
    {
        string input = "";

        cout << "Please enter some text: ";
        getline(cin, input);

        int counter = 0;
        for (char whatever : input)
        {
            counter++;
            cout << counter << " : " << whatever << endl;
        }


        // Error Handling
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            
            cerr << "[!] Invalid input, try again." << endl;

            continue;
        }

        if (input == "")
        {
            cerr << "[!] Invalid input, received an empty string, try again." << endl;
            continue;
        }
        

        int i = 0;
        string lines[] = { "", "", "" };
        for (char c : input)
        {
            // Using a ternary statement, if we are on the first iteration we include the left pipe character.
            // Here I also have to convert the c character into a string so it can concatenate correctly using the + symbol
            // without any errors occuring between types.
            lines[1] += ((i == 0 ? "|  " : "  ") + string(1, c) + "  |"); 
            i++;
        }


        // Originally I was going to approach this by calculating whether the current iteration was odd or even,
        // Then depending on the result, either adding a - or an =. But I realised the approach I used in the end
        // Was much simpler.
        for (int j = 0; j < i; j++)
        {
            lines[0] += "+=-=-=";
            lines[2] += "+=-=-=";

            if (j == i - 1)
            {
                lines[0] += "+";
                lines[2] += "+";
            }
        }

        for (string s : lines) { cout << s << endl; } // Printing out our array of lines

        cout << endl;
    }

    return 0;
}