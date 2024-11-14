#include "Intro.h"

void Intro::main()
{
	Logging::LogRepeat("Welcome to:", 150);

	std::vector<std::string> ascii1 = AsciiGenerator::Generate("Wisteria\'s", { Colors::BrightPurple, false });
	std::vector<std::string> ascii2 = AsciiGenerator::Generate("Labyrinth", { Colors::Purple, false });
	ascii1.insert(ascii1.end(), ascii2.begin(), ascii2.end());

	Logging::LogRepeat(ascii1, 300);

	
		std::cin;

}
