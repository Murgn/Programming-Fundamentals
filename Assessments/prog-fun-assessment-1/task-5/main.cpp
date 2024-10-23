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

        bool isAlpha = false;
        for (char c : input) if (!isAlpha) isAlpha = isalpha(c);
        if(!isAlpha) 
        {
            cerr << "[!] Invalid input, received no alphanumeical characters, try again." << endl;
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
            sentenceInput += shouldUpper ? toupper(c) : tolower(c);

            // If we receive punctuation, sets shouldUpper to true for the next character.
            // If the character is alphanumeric, we know the next character shouldn't be capitalised.
            // This check also makes sure we persist shouldUpper through whitespaces.
            if (c == '.' || c == '!' || c == '?') shouldUpper = true;
            else if(isalpha(c)) shouldUpper = false;
        }

        cout << "Sentence Case\t => " << sentenceInput << endl;


        // -- Alternate Case -------------------------------------

        string alternateInput = "";
        shouldUpper = true; // Reusing the previous shouldUpper variable.

        for (char c : input)
        {
            alternateInput += shouldUpper ? toupper(c) : tolower(c);
            if (isalpha(c)) shouldUpper = !shouldUpper;
        }

        cout << "Alternate Case\t => " << alternateInput << endl;
    }
    // Experimenting with how isalpha works.
    //for (char c : input) cout << c << (isalpha(c) ? " is" : " is not") << " alphanumeric" << endl;
    return 0;
}