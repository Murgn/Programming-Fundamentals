#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include "colors.h"

// Errors are for players, Warnings are for me
class Logging
{
public:
	template <typename T> static const void Log(const T& output, const bool endLine = true);
	static const void LogError(const std::string& output);
	static const void LogWarning(const std::string& output);
	static const void LogRepeat(const std::string& output, const int delay, const bool endLine = true);
	static const void LogRepeat(const std::vector<std::string>& output, const int delay, const bool endLine = true);
	static const void EndLine();
};

template<typename T>
inline const void Logging::Log(const T& output, const bool endLine)
{
	std::cout << output;
	if (endLine) std::cout << std::endl;
}