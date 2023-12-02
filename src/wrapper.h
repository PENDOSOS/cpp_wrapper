#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <tuple>

template <typename Class, typename... Args>
class Wrapper
{
private:
	using Method = int (Class::*)(Args...);
public:
	Wrapper(Class* subject, Method method, std::unordered_map<std::string, int> const& args) : subject(subject), method(method) 
	{
		for (auto arg : args)
		{
			arg_names.push_back(arg.first);
			arg_values.push_back(arg.second);
		}
	}
private:
	Class* subject;
	Method method;

	std::vector<int> arg_values;
	std::vector<std::string> arg_names;
};