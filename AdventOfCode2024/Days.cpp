#include "Days.h"
#include <algorithm>
#include <map>
#include <sstream>


// Day 1
void Day1::Solve()
{
	LoadDataFromFile();
	Test();
	Part1();
	Part2();
	PrintResults();
}

void Day1::Test()
{
	int test_result = 0;
	std::vector<int> test = { 3, 4, 4, 3, 2, 5, 1, 3, 3, 9, 3, 3 };
	// one for each list
	std::vector<int> a, b;
	// divide the data into two parts
	for (int i = 0; i < test.size(); ++i) {
		if (i % 2 == 0)
			a.push_back(test[i]);
		else
			b.push_back(test[i]);
	}

	// sort the two lists
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	// get the difference between each number of the list
	for (size_t i = 0; i < test.size() / 2; ++i)
	{
		test_result += abs(a[i] - b[i]);
	}
	
	std::cout << "Test 1: " << test_result << std::endl;
	
}


// This first assignment is about comparing the first and second list and summing the delta between each for each index
void Day1::Part1()
{
	const auto& test = GetData();

	// one for each list
	std::vector<int> a, b;
	// divide the data into two parts
	for (int i = 0; i < test.size(); ++i) {
		if (i % 2 == 0)
			a.push_back(test[i]);
		else	
			b.push_back(test[i]);
	}

	// sort the two lists
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	// get the difference between each number of the list
	for (size_t i = 0; i < test.size()/2; ++i)
	{
		m_result1 += abs(a[i] - b[i]);
	}

}

// for this one, collect every occurrence of every number in the right list
// then add to m_result2 the sum of all occurrences for that number. 
// If a number appears in list a and not b it is not added to the sum
void Day1::Part2()
{
	const auto& test = GetData();

	// one for each list
	std::vector<int> a, b;
	// divide the data into two parts
	for (int i = 0; i < test.size(); ++i) {
		if (i % 2 == 0)
			a.push_back(test[i]);
		else
			b.push_back(test[i]);
	}

	// sort the two lists
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	// go over list b and count the occurrences
	
	std::map<int, int> occurrences;
	for(int i = 0; i< b.size(); ++i)
	{
		occurrences[b[i]]++;
	}
    // Now go through every index of list a
	for (int i = 0; i < a.size(); ++i)
	{
		// if the number is in the map, add the occurrences to the result
		if (occurrences.find(a[i]) != occurrences.end())
		{
			m_result2 += occurrences[a[i]]*a[i];
		}
	}
}

void Day1::PrintResults() const
{
	std::cout << "Part 1: " << m_result1 << std::endl;
	std::cout << "Part 2: " << m_result2 << std::endl;
}

void Day1::LoadDataFromFile()
{
	Solution::LoadDataFromFile(m_input);
}



// Day 2 
#define DAY2INRANGE (abs(delta) >= 1 && abs(delta) <= 3)
// returns true if the delta is following the growth direction (if increasing is false (decreasing) and delta < 0, then true).
#define DAY2FOLLOWINGTREND (increasing == (delta > 0))
void Day2::Solve()
{
	LoadDataFromFile();
	Test();
	PrintResults();
}

void Day2::Test()
{
	std::vector<std::string> testdata = {
		 "7 6 4 2 1",
		 "1 2 7 8 9",
		 "9 7 6 2 1",
		 "1 3 2 4 5",
		 "8 6 4 4 1",
		 "1 3 6 7 9"
	};

	
	// parse line each line as a report, each number entry as a level
	for (const auto& report : testdata)
	{
		bool safe = true;
		bool increasing = false;
		int current = 0, last = 0;

		std::istringstream iss(report);

		// get the first two numbers
		iss >> current;
		last = current;
		iss >> current;
		auto delta = current - last;
		last = current;
		// the first two numbers set the character for the rest of the report
		delta > 0 ? increasing = true : false;
		// if the diff is already outside the range 1<= delta <= 3, this is report is unsafe
		if (!DAY2INRANGE)
			safe = false;


		// loop until eof or report unsafe
		while(iss >> current && safe == true)
		{
			delta = current - last;
			// if the change is bigger than 3
			if(!DAY2INRANGE || !DAY2FOLLOWINGTREND)
				safe = false; 
			last = current;
		};

		if(safe == false)
			++m_test;
	}
	m_test = static_cast<int>(testdata.size() - m_test);
}

void Day2::Part1()
{
}

void Day2::Part2()
{
}

void Day2::PrintResults() const
{
	std::cout << "Test  : " << m_test << std::endl;
	std::cout << "Part 1: " << m_result1 << std::endl;
	std::cout << "Part 2: " << m_result2 << std::endl;
}

void Day2::LoadDataFromFile()
{
	Solution::LoadDataFromFile(m_input);
}
