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

        // -- Uppercase ------------------------------------------

        string upperInput = "";

        for (char c : input) upperInput += toupper(c);

        cout << "Uppercase\t => " << upperInput << endl;

        // -- Lowercase ------------------------------------------

        string lowerInput = "";

        for (char c : input) lowerInput += tolower(c);

        cout << "Lowercase\t => " << lowerInput << endl;

        // -- Sentence Case --------------------------------------

        string sentenceInput = "";
        bool shouldUpper = true;

        for (char c : input)
        {
            if (c == '.' || c == '!' || c == '?') shouldUpper = true;

            sentenceInput += shouldUpper ? toupper(c) : tolower(c);

            // Need to include a check to make sure the character isnt a whitespace, if it is, don't disable shouldupper.

            shouldUpper = false;
        }

        cout << "Sentence Case\t => " << sentenceInput << endl;


        // -- Alternate Case -------------------------------------

        cout << "Alternate Case\t => " << endl;
        for (char c : input) cout << c << (isalpha(c) ? " is" : " is not") << " alphanumeric" << endl;
    }
    return 0;
}