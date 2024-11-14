#include "logging.h"

const void Logging::LogError(const std::string& output)
{
	std::cout << Colors::Red << "[!] " << Colors::None << output << std::endl;
}

const void Logging::LogWarning(const std::string& output)
{
	std::cout << Colors::Yellow << "[!] " << Colors::None << output << std::endl;
}
