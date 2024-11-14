#include <iostream>
#include "colors.h"
#include "AsciiGenerator.h"
#include <string>
#include <Windows.h>

int main()
{
    HWND hWnd = ::GetConsoleWindow();
    if (hWnd) ::SendMessage(hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
    // All the different ways you can output the ASCII art.

    std::vector<std::string> ascii1 = AsciiGenerator::Generate("QWERTYUIOPASDFGHJKLZXCVBNM", { Colors::White, false });
    AsciiGenerator::PrintAscii(ascii1);

    std::vector<std::string> ascii2 = AsciiGenerator::Generate("qwertyuiopasdfghjklzxcvbnm", { Colors::White, false });
    for (std::string line : ascii2)
    {
        std::cout << line << std::endl;
    }

    AsciiGenerator::Generate("0123456789");
    AsciiGenerator::Generate("£$%()-=+_[];:'@#,<.>\\|/?!\"");

    // ----------------------------------------------------

    AsciiGenerator::Generate("Hello World.");
    AsciiGenerator::Generate("HELLO WORLD", { Colors::Red });
    AsciiGenerator::Generate("hello world", { Colors::Green });
    AsciiGenerator::Generate("HELLO world", { Colors::Blue });
}