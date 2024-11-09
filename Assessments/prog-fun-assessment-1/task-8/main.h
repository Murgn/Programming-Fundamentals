#pragma once

// Today I wanted to challenge myself by utilising header files and cleaning up my code.

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

#define warn "\033[31m[!]\033[0m "

using namespace std;

// Creating a simple Vector2 class to pass data easily
struct Vector2
{
    int x;
    int y;
};

struct Command
{
    string name = "";
    vector<string> parameters = {};
    string description = "";
};

int inventorySize = 0;
const Command commands[] = {
    {"view", {"number"}, "Prints out the full details of the inventory slot index, specified by <number>."},
    {"show_all", {}, "Shows all the slots in the inventory and information about each."},
    {"set", {"index", "item_id"}, "Sets the inventory slot <index> to the item index <item_id>."},
    {"search_item", {"str"}, "Searches the item list for any item whose name contains <str> and shows a list of results."},
    {"items", {}, "Shows all the items you can possibly set a slot to, along with their ids."},
    {"exit", {}, "Exits the tool."},
    {"restart", {}, "Restarts the session and goes back to the first step."},
    {"help", {}, "Shows the list of available commands."},
    {"clear", {}, "Clears the inventory."}
};

const string items[] = {
    "Empty", "Shield", "Potion", "Gloves"
};

// I'm researching how to use vectors so I can complete one of the task's challenges
// to use a suitable dynamic data structure.
vector<int> inventory;

void ClearInput();

// Creating a generic ErrorCheck that can be used in several Check functions for different
// datatypes.
bool ErrorCheck();

// Implementation includes the above ErrorCheck to create a more detailed IntCheck function
// that can check if your int is within a range. Can be easily expanded for more functionality
bool IntCheck(int input, int min, int max);

// Changing this implementation to return an int instead of a boolean.
// This lets me return the type of command the user has requested alongside
// being able to return -1 if the check has failed at any point.
int CommandCheck(string input);

// Creating a ToLower function to convert strings to lowercase to make commands & searching easier
string ToLower(string input);