#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <tuple>
#include <exception>

template <typename Class, typename... Args>
class Wrapper
{
private:
	using Method = int (Class::*)(Args...);
public:
	Wrapper(Class* subject, Method method, std::unordered_map<std::string, int> const& args) : subject(subject), method(method) 
	{
		for (auto const& arg : args)
		{
			arg_names.push_back(arg.first);
		}
	}

	int fillValues(std::unordered_map<std::string, int> args)
	{
		for (auto const& name : arg_names)
		{
			if (args.find(name) == args.end())
				throw std::runtime_error("No matched argument found");

			arg_values.push_back(args[name]);
		}

		return callFunc(std::make_index_sequence<sizeof...(Args)>{});
	}
private:
	Class* subject;
	Method method;

	std::vector<int> arg_values;
	std::vector<std::string> arg_names;

	template <std::size_t... Is>
	int callFunc(std::index_sequence<Is...>)
	{
		return (subject->*method)(arg_values[Is]...); 	//unpacking a tuple of arguments
	}
};