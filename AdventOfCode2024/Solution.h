#pragma once

// generalized solution class to be inherited for every day of the calendar

template <typename T>
class Solution
{
public:
	Solution() = default;
	virtual ~Solution() = default;
	virtual void Test() = 0;
	virtual void Solve() = 0;
	virtual void Part1() = 0;
	virtual void Part2() = 0;

	virtual void PrintResults() const = 0;
	std::vector<T>& GetData() { return m_data; }
	void LoadDataFromFile(const std::string& filename)
	{
		m_data = LoadFile<T>(filename);
	}
private:
	std::vector<T> m_data;
};