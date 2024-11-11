#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <array>
#include "colors.h"

class AsciiGenerator
{
private:
	static const int lineHeight = 5;
public:

	struct GeneratorSettings
	{
		const char* color = Colors::White;
		bool autoPrint = true;
	};

	static const std::map<char, std::array<std::string, lineHeight>> charToAscii;

	static std::vector<std::string> Generate(const std::string& input, GeneratorSettings settings = {});
	static void PrintAscii(const std::vector<std::string>& input);
};