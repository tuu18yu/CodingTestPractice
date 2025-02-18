#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <tuple>
#include <functional>

int main(int, char**)
{
    int N, ans;

    auto read_line = [&N]()
   {
        // read line from cin
        std::string line;
        std::getline(std::cin, line);

        std::istringstream ss(line);
        ss >> N;
   };

   auto print_line = [&ans]()
   {
        std::cout << ans << "\n";
   };
   
   // returns int and takes 1 int value
   std::function<int(int)> solve = [&](int curr) -> int
   {
        // base case
        if (curr == 0) return 0;
        else if (curr == 1) return 1;

        // recursive case
        else return solve(curr - 1) + solve(curr - 2);
   };

   read_line();
   ans = solve(N);
   print_line();
}