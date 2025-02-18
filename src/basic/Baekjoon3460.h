#include "../config.h"

class Baekjoon3460
{
public:
    Baekjoon3460() {}
    void Solve();
private:
    int D;
    std::vector<int> data;
    std::vector<std::string> ans;
    void readInput();
    void solution();
    void printOutput();
};

void Baekjoon3460::Solve()
{
    readInput();
    solution();
    printOutput();
}

void Baekjoon3460::readInput()
{
    std::string input;

    std::getline(std::cin, input);
    std::istringstream line;
    line.str(input);
    line >> D;

    for (int i = 0; i < D; i++)
    {
        std::string read_data;
        int int_data;

        std::getline(std::cin, read_data);
        std::istringstream num;
        num.str(read_data);
        num >> int_data;

        data.push_back(int_data);
    }
}

void Baekjoon3460::printOutput()
{
    for (auto &a :ans)
    {
        std::cout << a << "\n";
    }
}

void Baekjoon3460::solution()
{
    for (auto &int_data : data)
    {
        int n = int_data;
        std::vector<int> binary;
        while (n > 0)
        {
            int digit = n % 2 == 0 ? 0 : 1;
            n /= 2;
            binary.push_back(digit);
        }

        std::string a = "";
        for (int i = 0; i < binary.size(); i++)
        {
            if (binary[i] == 0) continue;

            a += std::to_string(i) + " ";
        }
        ans.push_back(a);
    }
}