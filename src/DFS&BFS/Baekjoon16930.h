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

using namespace std;

int main(int, char**)
{
    int N, M, maxK, x1, y1, x2, y2;
    vector<vector<char>> map;
    int ans;

    auto read_line = [&]()
    {
        string line;
        getline(std::cin, line);
        istringstream ss(line);
        ss >> N >> M >> maxK;

        for (int i = 0; i < N; i++)
        {
            string line1;
            getline(cin, line1);
            vector<char> row;
            for (int j = 0; j < N; j++)
            {
                row.push_back(line1[j]);
            }
            map.push_back(row);           
        }

        string line2;
        getline(std::cin, line2);
        istringstream ss2(line2);
        ss2 >> x1 >> y1 >> x2 >> y2;
    };

   auto print_line = [&ans]()
   {
        std::cout << ans <<"\n";
   };

   auto solve = [&]()
   {
        vector<vector<int>> visited(N, vector<int> (M, -1));    
        function<void(int, int, int)> DFS = [&](int x, int y, int steps)
        {
            int i = y - 1;
            int j = x - 1;

            if (visited[i][j] != -1)
            {
                if (steps < visited[i][j]) visited[i][j] = steps;
                return;
            }

            if (i == y2 && j == x2)
            {
                if (steps < visited[i][j]) visited[i][j] = steps;
                return;
            }

            visited[i][j] = steps;
            for (int k = 1; k < maxK + 1; k++)
            {
                // up
                if (i-k >= 0)
                {
                    if (map[i-k][j] == '.') DFS(i-k, j, steps + 1);
                }

                // down
                if (i+k < N)
                {
                    if (map[i+k][j] == '.') DFS(i+k, j, steps + 1);
                }

                // left
                if (j-k >= 0)
                {
                    if (map[i][j-k] == '.') DFS(i, j-k, steps + 1);
                }

                // right
                if (j+k < M)
                {
                    if (map[i][j+k] == '.') DFS(i, j+k, steps + 1);
                }
            }
        };

        DFS(x1, y1, 0);
        ans = visited[y2][x2];
    };

   read_line();
   solve();
   print_line();
}
