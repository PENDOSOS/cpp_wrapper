#include <iostream>
#include "wrapper.h"

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
};

int main()
{
	Subject subj;

	Wrapper wrapper(&subj, &Subject::f3, { {"arg1", 0}, {"arg2", 0}});

	return 0;
}