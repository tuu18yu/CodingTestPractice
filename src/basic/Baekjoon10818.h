#include "../config.h"

class Baekjoon10818
{
public:
    Baekjoon10818() {}
    void Solve();
private:
    int N;
    std::vector<int> data;
    std::tuple<int, int> ans;
    void readInput();
    void solution();
    void printOutput();
};

void Baekjoon10818::Solve()
{
    readInput();
    solution();
    printOutput();
}

void Baekjoon10818::readInput()
{
    // read N
    std::string input;
    std::getline(std::cin, input);
    std::istringstream line;
    line.str(input);
    line >> N;

    // read list of numbers in a line
    std::string read_data;
    std::getline(std::cin, read_data);
    std::istringstream nums;
    nums.str(read_data);

    while (!nums.eof())
    {
        int num;
        nums >> num;
        data.push_back(num);
    }
}

void Baekjoon10818::printOutput()
{
    std::cout << std::get<0>(ans) << " " << std::get<1>(ans) << "\n";
}

void Baekjoon10818::solution()
{
   int max = INT_MIN;
   int min = INT_MAX;

   for (auto &num : data)
   {
    if (num > max) max = num;
    if (num < min) min = num;
   }

    ans = std::make_tuple(min, max);
}