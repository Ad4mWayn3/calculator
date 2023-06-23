#include <iostream>
#include <string>
#include <vector>

int pow(int base, int exp)
{
	int power{1};
	for (int i{0}; i < exp; ++i) power *= base;
	return power;
}

int numLength(int num)
{
	if (num < 0) num = -num;
	int size{0};
	for (int exp{0}; pow(10, exp) <= num; ++exp, ++size);

	return size;
}

short digitIn(long long int num, int index)
{
	if (index < 0) index = -index;

	if (index >= numLength(num)) return 0;
	else
		return (num % pow(10, index+1) - num % pow(10, index)) / pow(10, index);
}

struct Button
{
	std::string_view label{};
	double (*unaryOp)(double);
};

double target(int baseNum, long long targetSequence, std::vector<Button> buttons)
{
	short length{(short)numLength(targetSequence)};
	double target{(double)baseNum};

	for (int i{length-1}; i >= 0; --i)
	{
		short button{digitIn(targetSequence, i)};
		target = buttons[button].unaryOp(target);
	}

	return target;
}

void calcGame(int baseNum, short attempts, long long targetSequence,
	std::vector<Button>& buttons)
{
	if (buttons.size() > 10) buttons.resize(10);
	short length{numLength(targetSequence)};
	if (attempts < length) attempts = length;
}

int main()
{

	return 0;
}