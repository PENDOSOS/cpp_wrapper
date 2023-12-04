#pragma once

#include <functional>
#include "wrapper.h"

class Engine
{
public:
	template <typename Class, typename... Args>
	void register_command(Wrapper<Class, Args...> wrapper, std::string const& command_name)
	{

	}

	int execute(std::string const& command_name, std::unordered_map<std::string, int> args)
	{

	}
private:
	std::unordered_map<std::string, std::function<int(std::unordered_map<std::string, int>)>> commands;
};