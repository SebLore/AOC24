#pragma once

#include <vector>
#include <fstream>
#include <iostream>

#include "Utilities.h"
#include "Solution.h"

class Day1 : public Solution<int>
{
public:
	Day1() = default;
	~Day1() = default;

	void Solve()override;
	void Test()override;
	void Part1()override;
	void Part2()override;
	void PrintResults()const override;


private:
	void LoadDataFromFile();
	const char* m_input = "Day1.txt";
	int m_test = 0;
	int m_result1 = 0;
	int m_result2 = 0;
};

class Day2 : public Solution<std::string>
{
public:
	Day2() = default;
	~Day2() = default;
	void Solve()override;
	void Test()override;
	void Part1()override;
	void Part2()override;
	void PrintResults()const override;
private:
	void LoadDataFromFile();
	const char* m_input = "Day2.txt";
	int m_test = 0;
	int m_result1 = 0;
	int m_result2 = 0;
};
