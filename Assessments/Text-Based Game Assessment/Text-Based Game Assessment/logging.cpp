#include "logging.h"

const void Logging::LogError(const std::string& output)
{
	Logging::Log(std::string(Colors::Red) + "[!] " + Colors::None + output, true);
}

const void Logging::LogWarning(const std::string& output)
{
	Logging::Log(std::string(Colors::Yellow) + "[!] " + Colors::None + output, true);
}

const void Logging::LogRepeat(const std::string& output, const int delay, const bool endLine)
{
	for (char c : output)
	{
		Logging::Log(c, false);
		Sleep(delay);
	}
	Logging::EndLine();
}

const void Logging::LogRepeat(const std::vector<std::string>& output, const int delay, const bool endLine)
{
	for (std::string s : output)
	{
		Logging::Log(s);
		Sleep(delay);
	}
}

const void Logging::EndLine()
{
	std::cout << std::endl;
}
