#pragma once

#include <functional>
#include "wrapper.h"

class Engine
{
public:
	template <typename Class, typename... Args>
	void register_command(Wrapper<Class, Args...>* wrapper, std::string const& command_name)
	{
		if (commands.find(command_name) == commands.end())
		{
			commands[command_name] = [wrapper](std::unordered_map<std::string, int> args)
			{
				return wrapper->registerValues(std::move(args));
			};
		}
		else
		{
			throw std::runtime_error("Command " + command_name + " has already registered");
		}
	}

	int execute(std::string const& command_name, std::unordered_map<std::string, int> args)
	{
		auto iterator = commands.find(command_name);
		if (iterator != commands.end())
		{
			auto method = &iterator->second;
			return (*method)(std::move(args));
		}
		else
		{
			throw std::runtime_error("Command not found");
		}
	}
private:
	std::unordered_map<std::string, std::function<int(std::unordered_map<std::string, int>)>> commands;
};