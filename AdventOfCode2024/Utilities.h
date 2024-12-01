#pragma once
#include <vector>
#include <fstream>
#include <iostream>

// load a file into a vector of type T

template <typename T>
std::vector<T> LoadFile(const std::string& filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return {};
	}
	std::vector<T> test;
	T temp{};
	while (file >> temp)
	{
		test.push_back(temp);
	}
	return test;
}