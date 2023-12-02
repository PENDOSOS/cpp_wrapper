#pragma once

#include <unordered_map>
#include <string>
#include <vector>

template <typename Class, typename... Args>
class Wrapper
{
public:
	Wrapper(Class subject, Method method, std::unordered_map<std::string, int> const& args) : subject(subject), method(method), 
	{
		for (auto arg : args)
		{
			arg_names.push_back(arg.first);
			arg_values.push_back(arg.second);
		}
	}
private:
	using Method int(Class::*, Args...);

	Class subject;
	Method method;

	std::vector<int> arg_values;
	std::vector<std::string> arg_names;
};