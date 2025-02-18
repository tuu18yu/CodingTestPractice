#include "../config.h"

class Baekjoon2501
{
public:
    Baekjoon2501() {}
    void Solve();
private:
    int N, K;
    int ans;
    void readInput();
    void solution();
    void printOutput();
};

void Baekjoon2501::Solve()
{
    readInput();
    solution();
    printOutput();
}

void Baekjoon2501::readInput()
{
    std::string input;
    std::getline(std::cin, input);
    std::istringstream line;
    line.str(input);
    line >> N >> K;
}

void Baekjoon2501::printOutput()
{
    std::cout << ans << "\n";
}

void Baekjoon2501::solution()
{
    // find Kth smallest factor of N
    // if doesn't exist return 0
    int total = 0, curr = 0;

    for (int i = 1; i < N + 1; i++)
    {
        if (total == K || total > K) break;

        if (N % i == 0)
        {
            total += 1;
            curr = i;
        }
    }

    if (total == K) ans = curr;
}