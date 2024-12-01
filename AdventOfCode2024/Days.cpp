#include "Days.h"
#include <algorithm>
#include <map>

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
