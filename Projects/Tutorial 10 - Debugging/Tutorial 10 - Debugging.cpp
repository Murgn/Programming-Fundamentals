#include <iostream>
#include <string>

using namespace std;
int CountPunctuation(string str);
void PrintArray(int* arr, int size);

int main()
{
    int numbers[] = { 3,4,5 };
    // this is printing the amount of bytes this array is, changing it to print out how many items it has
    PrintArray(numbers, sizeof(numbers) / sizeof(numbers[0]));
}

// Added str as a parameter
int CountPunctuation(string str)
{
    int counter = 0;
    
    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
            counter += 1;
    }

    return counter;
}

void PrintArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << endl;
}
