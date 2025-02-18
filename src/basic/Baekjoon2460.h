#include "../config.h"

class Baekjoon2460
{
public:
    Baekjoon2460() {}
    void Solve();
private:
    int curr = 0;
    int ans = 0;
    std::vector<std::tuple<int, int>> data;
    void readInput();
    void solution();
    void printOutput();
};

void Baekjoon2460::Solve()
{
    readInput();
    solution();
    printOutput();
}

void Baekjoon2460::readInput()
{
    for (int i = 0; i < 10; i++)
    {
        std::string read_data;
        int in, out;

        std::getline(std::cin, read_data);
        std::istringstream read;
        read.str(read_data);
        read >> in >> out;

        data.push_back(std::make_tuple(in, out));
    }
}

void Baekjoon2460::printOutput()
{
    std::cout << ans << "\n";
}

void Baekjoon2460::solution()
{
   for (auto &station : data)
   {
        curr += std::get<1>(station);    
        curr -= std::get<0>(station);

        if (ans < curr)
        {
            ans = curr;
        }
   }
}