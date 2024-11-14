#include "Intro.h"

void Intro::main()
{
	Logging::LogRepeat("Welcome to", 150);

	std::vector<std::string> ascii1 = AsciiGenerator::Generate("Wisteria\'s", { Colors::BrightPurple, false });
	std::vector<std::string> ascii2 = AsciiGenerator::Generate("Labyrinth", { Colors::Purple, false });
	ascii1.insert(ascii1.end(), ascii2.begin(), ascii2.end());

	Logging::LogRepeat(ascii1, 300);
	
	Logging::Log("- \t(1) New Game");
	Logging::Log("- \t(2) Load Game", Colors::BrightBlack);
	Logging::Log("- \t(3) Quit");

	while (true)
	{
		int input = 0;
		Input::Get<int>(input);

		if (HandleMenuCommand(input))
			continue;
		Logging::Log("Received input: " + std::to_string(input));
	
	}
}

bool Intro::HandleMenuCommand(const int command)
{
	if (ErrorHandler::HandleError()) return true;
	else if (!Utilities::within(command, 1, 3))
	{
		ErrorHandler::ClearInput();
		Logging::LogError("Input out of range, try again.");

		return true;
	}
	return false;
}
