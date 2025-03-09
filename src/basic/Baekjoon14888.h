#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <tuple>
#include <functional>
#include <algorithm> 
#include <cmath>
#include <limits>

int main(int, char**)
{
    int N, add, sub, mul, div;
    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();
    std::vector<int> A;
    auto read_line = [&]()
   {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream ss(line);
        ss >> N;

        std::string line2;
        std::getline(std::cin, line2);
        std::istringstream ss2(line2);
        for (int i = 0; i < N; i++)
        {
            int a;
            ss2 >> a;
            A.push_back(a);
        }

        std::string line3;
        std::getline(std::cin, line3);
        std::istringstream ss3(line3);
        ss3 >> add >> sub >> mul >> div;
   };

   auto print_line = [&]()
   {
        std::cout << max << "\n" << min <<"\n";
   };
   
   std::function<void(int, int, int, int, int, int)> DFS = 
   [&DFS, &max, &min, &N, &A](int curr, int i, int add, int sub, int mul, int div) -> void
   {
       if (i == N)
       {
            if (max < curr) max = curr;
            if (min > curr) min = curr;
            return;
       }

       if (add > 0) DFS(curr + A[i], i + 1, add - 1, sub, mul, div);
       if (sub > 0) DFS(curr - A[i], i + 1, add, sub - 1, mul, div);
       if (mul > 0) DFS(curr * A[i], i + 1, add, sub, mul - 1, div);
       if (div > 0) DFS(curr / A[i], i + 1, add, sub, mul, div - 1);
   };

   auto solve = [&]()
   {
        DFS(A[0], 1, add, sub, mul, div);
   };

   read_line();
   solve();
   print_line();
}