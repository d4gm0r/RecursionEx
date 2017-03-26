#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "TestCases.hpp"

std::string collapseSpaces(std::string s);
std::vector<std::string> split(std::string s);
bool isPalindrome(std::string word, int start, int end);
bool isWordSymmetric(const std::vector<std::string>& words, int start, int end);
long vectorSum(const std::vector<int>& data, unsigned int position);
int vectorMin(const std::vector<int>& data, unsigned int position);
void quickSort(std::vector<int>& data, int start, int end);

int main()
{
    //TestCases::runTestCases();
    std::vector<int> *data = new std::vector<int> {1,2,3,4,5,6,7,8,9};
    unsigned int position = 0;
    int num = vectorSum(*data, position);
    std::cout << num << std::endl;

    return 0;
}

// ------------------------------------------------------------------
//
// Provided code to remove spaces from a string (and capitalize it)
//
// ------------------------------------------------------------------
std::string collapseSpaces(std::string s)
{
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
    std::transform(s.begin(), s.end(), s.begin(), toupper);	// Capitalize all
    return s;
}

// ------------------------------------------------------------------
//
// Solution string split code
//
// ------------------------------------------------------------------
std::vector<std::string> split(std::string s)
{
    std::istringstream is(s);
    std::vector<std::string> words;

    do
    {
        std::string word;
        is >> word;
        if (word.length() > 0)
        {
            words.push_back(word);
        }
    } while (is);

    return words;
}

bool isPalindrome(std::string word, int start, int end)
{
}

// ------------------------------------------------------------------
//
// Provided quicksort partition code
//
// ------------------------------------------------------------------
int partition(std::vector<int>& data, int start, int end)
{
    int middle = (start + end) / 2;
    std::swap(data[start], data[middle]);
    int pivotIndex = start;
    int pivotValue = data[start];
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (data[scan] < pivotValue)
        {
            pivotIndex++;
            std::swap(data[scan], data[pivotIndex]);
        }
    }

    std::swap(data[pivotIndex], data[start]);

    return pivotIndex;
}

// ------------------------------------------------------------------
//
// Provided quicksort code
//
// ------------------------------------------------------------------
void quickSort(std::vector<int>& data, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(data, start, end);
        quickSort(data, start, pivot - 1);
        quickSort(data, pivot + 1, end);
    }
}

long vectorSum(const std::vector<int>& data, unsigned int position)
{
    if(position >= data.size())
    {
        return 0;
    }
    if(data.size() == 0)
    {
        return 0;
    }

    long num = data[position];
    return num + vectorSum(data, position + 1);
}