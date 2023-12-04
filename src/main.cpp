#include <iostream>
#include "wrapper.h"
#include "engine.h"

class Subject
{
public:
	int f1(int first, int second)
	{
		std::cout << "This is f1 returns arg1 * arg2" << std::endl;
		return first * second;
	}

	int f2(int first, int second)
	{
		std::cout << "This is f2 with " << first << " as arg1 and " << second << " as arg2. Returns 0" << std::endl;
		return 0;
	}

	int f3(int first, int second)
	{
		std::cout << "This is f3 returns max{arg1, arg2}" << std::endl;
		return (first > second) ? first : second;
	}

	int f4(int first)
	{
		std::cout << "This is f4 returns arg1" << std::endl;
		return first;
	}
};

int main()
{
	try
	{
		Subject subj;

		Wrapper wrapper(&subj, &Subject::f4, {{"arg1", 0}, {"arg2", 0}});

		Engine engine;

		engine.register_command(&wrapper, "command1");

		std::cout << engine.execute("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;
	}
	catch (const std::exception& err)
	{
		std::cout << err.what();
	}

	return 0;
}