#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <tuple>
#include <functional>
#include <algorithm> 

int main(int, char**)
{
    std::vector<int> heights{};
    std::vector<int> sums;

    int N = 9;
    int totalSum = 0;
    int goal = 100;
    std::tuple<int, int> pop_index = std::make_tuple(-1, -1);

    auto read_line = [&heights, &totalSum](int i)
   {
        // read line from cin
        std::string line;
        std::getline(std::cin, line);

        int h;
        std::istringstream ss(line);
        ss >> h;

        totalSum += h;
        heights.push_back(h);
   };

   auto print_line = [&]()
   {
        std::vector<int> ans;
        for (auto &h : heights)
        {   
            std::cout << h << "\n";
        }
   };
   
  
   auto solve = [&]()
   {
        for (auto &h : heights)
        {
            sums.push_back(totalSum - h);
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j) continue;

                int sum = sums[i] - heights[j];
                if (sum == goal)
                {
                    std::get<0>(pop_index) = i;
                    std::get<1>(pop_index) = j;
                    break;
                }
            }
            if (std::get<0>(pop_index) != -1) break;
        }

        heights.erase(heights.begin() + std::get<0>(pop_index));
        heights.erase(heights.begin() + std::get<1>(pop_index) - 1);

        std::sort(heights.begin(), heights.end());
   };

   for (int i = 0; i < N; i++)
   {
        read_line(i);
   }
   solve();
   print_line();
}