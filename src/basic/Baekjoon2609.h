#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <tuple>
#include <functional>
#include <algorithm> 
#include <cmath>

int main(int, char**)
{
    int n1, n2;
    int gcd, lcm;
    auto read_line = [&n1, &n2]()
   {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream ss(line);
        ss >> n1 >> n2;
   };

   auto print_line = [&gcd, &lcm]()
   {
        std::cout << gcd << "\n";
        std::cout << lcm << "\n";
   };
   
  
   auto solve = [&]()
   {
        // smallest factor cannot be greater than its square root
        auto isPrime = [](int n) -> bool
        {
            if (n == 1) return true;
            if (n == 2) return true;

            int root = (int) std::sqrt(n);
            for (int i = 2; i < root + 1; i++)
            {
                if (n % i == 0)
                {
                    return false;
                }
            }
            return true;
        };

        auto primeFactorization = [&isPrime](int n) -> std::vector<int>
        {
            std::vector<int> factors;
            int curr_prime = 2;
            int curr = n;

            while (!isPrime(curr))
            {
                if (curr % curr_prime == 0)
                {
                    factors.push_back(curr_prime);
                    curr = curr / curr_prime;
                }
                
                else
                {   // get next prime
                    curr_prime += 1;
                    while (!isPrime(curr_prime))
                    {
                        curr_prime += 1;
                    }
                }
            }
            factors.push_back(curr);
            return factors;
        };

        auto _GCD = [](std::vector<int> n1Factors, std::vector<int> n2Factors) -> int
        {
            int ans = 1;
            int i1 = 0, i2 = 0;

            while (i1 < n1Factors.size() && i2 < n2Factors.size())
            {
                if (n1Factors[i1] == n2Factors[i2])
                {
                    ans *= n1Factors[i1];
                    i1 += 1;
                    i2 += 1;
                }

                else
                {
                    if (n1Factors[i1] < n2Factors[i2]) i1 += 1;
                    else i2 += 1;
                }
            }

            return ans;
        };

        auto _LCM = [](std::vector<int> n1Factors, std::vector<int> n2Factors) -> int
        {
            int ans = 1;
            int i1 = 0, i2 = 0;

            while (i1 < n1Factors.size() && i2 < n2Factors.size())
            {
                if (n1Factors[i1] == n2Factors[i2])
                {
                    ans *= n1Factors[i1];
                    i1 += 1;
                    i2 += 1;
                }

                else
                {
                    if (n1Factors[i1] < n2Factors[i2])
                    {
                        ans *= n1Factors[i1];
                        i1 += 1;
                    }
                    else
                    {
                        ans *= n2Factors[i2];
                        i2 += 1;
                    }
                }
            }

            while (i1 < n1Factors.size())
            {
                ans *= n1Factors[i1];
                i1 += 1;
            }

            while (i2 < n2Factors.size())
            {
                ans *= n2Factors[i2];
                i2 += 1;
            }

            return ans;
        };

        std::vector<int> n1Factors = primeFactorization(n1);
        std::vector<int> n2Factors = primeFactorization(n2);

        gcd = _GCD(n1Factors, n2Factors);
        lcm = _LCM(n1Factors, n2Factors);
   };

   read_line();
   solve();
   print_line();
}