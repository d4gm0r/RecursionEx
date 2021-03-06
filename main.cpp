#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "TestCases.hpp"

//
// Nathan Larsen - A01532780
// Assignment 6 - Recursive Exercises
//

std::string collapseSpaces(std::string s);
std::vector<std::string> split(std::string s);
bool isPalindrome(std::string word, int start, int end);
bool isWordSymmetric(const std::vector<std::string>& words, int start, int end);
long vectorSum(const std::vector<int>& data, unsigned int position);
int vectorMin(const std::vector<int>& data, unsigned int position);
void quickSort(std::vector<int>& data, int start, int end);
void selectionSort(std::vector<int>& data, int start, int end);

int main()
{
    TestCases::runTestCases();

   /*std::vector<int> *data = new std::vector<int> {1,2,3,4,5,6,7,8,9};
    unsigned int position = 0;
    std::cout << vectorSum(*data, position) << std::endl;
    return 0;*/


    /*std::string value = "";
    bool pal = isPalindrome(value, 0, value.length() - 1);
    std::cout << pal << std::endl;*/

    /*std::string input = "you are you";
    auto words = split(input);	// Split into words
    bool result = isWordSymmetric(words, 0, words.size() - 1);
    std::cout << result << std::endl;*/

    /*std::vector<int> vec = {5, 3, 2, 4, 5};
    int actual = vectorMin(vec, 0);
    std::cout << actual << std::endl;*/
/*
    std::vector<int> input = {5, 4, 3, 2, 1, 6, 7, 8, 9, 2, 4, 3, 1};
    quickSort(input, 0, input.size() - 1);
    for(auto in : input)
    {
        std::cout << in << std::endl;
    }*/

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
void selectionSort(std::vector<int>& data, int start, int end)
{
    for(start; start < end; start++)
    {
        int minPos = start;

        for(int scan = start + 1; scan < end + 1; scan++)
        {
            if(data[minPos] > data[scan]){
                minPos = scan;
            }
        }
        std::swap(data[start], data[minPos]);
    }
}

void quickSort(std::vector<int>& data, int start, int end)
{
    if (start < end)
    {
        if ((end - start) <= 10)
        {
            selectionSort(data, start, end);
        }
        else
        {
            int pivot = partition(data, start, end);
            quickSort(data, start, pivot - 1);
            quickSort(data, pivot + 1, end);
        }
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

bool isPalindrome(std::string word, int start, int end)
{
    if (word.empty())
    {
        std::cout << "string was empty" << std::endl;
        return false;
    }
    if (start == end)
    {
       return true;
    }
    if (start > end)
    {
        return true;
    }
    if (word[start] != word[end])
    {
        return false;
    }

    bool pal = isPalindrome(word, start + 1, end - 1);
    return pal;
}

bool isWordSymmetric(const std::vector<std::string>& words, int start, int end)
{
    if (words.empty())
    {
        std::cout << "string was empty" << std::endl;
        return false;
    }
    if (start == end)
    {
        return true;
    }
    if (start > end)
    {
        return true;
    }
    if (words[start] != words[end])
    {
        return false;
    }

    bool sym = isWordSymmetric(words, start + 1, end - 1);
    return sym;
}

int vectorMin(const std::vector<int>& data, unsigned int position)
{
    if(position >= data.size())
    {
        return data[position - 1];
    }
    if(data.size() == 0)
    {
        return 0;
    }

    int min = data[position];
    int num = vectorMin(data, position + 1);
    if(num < min)
    {
        min = num;
    }

    return min;
}