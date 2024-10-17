#include "Console.h"
#pragma once

void SetCursor(int x, int y)
{
	cout << "\x1b[" << y << ";" << x << "H";
}

void ClearRows(int rows)
{
	cout << "\x1b[" << rows << "M";
}

//void SetWindowColor(string color)
//{
//	cout << "\x1b]" << "rgb:" << color << "\\";
//}
