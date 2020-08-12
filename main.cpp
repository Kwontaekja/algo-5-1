#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;
typedef pair<int, int> point;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        // initialization
        int num = 0;
        int ROW = grid.size();
        if (ROW == 0)
            return 0;
        int COL = grid[0].size();
        if (COL == 0)
            return 0;
        visited = new bool *[ROW];
        for (int row = 0; row < ROW; row++)
        {
            visited[row] = new bool[COL];
        }
        for (int row = 0; row < ROW; row++)
        {
            for (int col = 0; col < COL; col++)
            {
                visited[row][col] = false;
            }
        }
        // count '1' points
        for (int row = 0; row < ROW; row++)
        {
            for (int col = 0; col < COL; col++)
            {
                if (grid[row][col] == '1')
                    lands.push_back({row, col});
            }
        }
        for (int chk = 0; chk < lands.size(); chk++)
        {
            point land = lands[chk];
            if (!visited[land.first][land.second])
            {
                stack<point> s;
                s.push({land.first, land.second});
                visited[land.first][land.second] = true;
                num++;

                while (!s.empty())
                {
                    point curr = s.top();
                    s.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        if (curr.first + fixed_x[k] < 0 || curr.first + fixed_x[k] >= ROW || curr.second + fixed_y[k] < 0 || curr.second + fixed_y[k] >= COL)
                            continue;
                        else
                        {
                            if (!visited[curr.first + fixed_x[k]][curr.second + fixed_y[k]])
                            {
                                if (grid[curr.first + fixed_x[k]][curr.second + fixed_y[k]] == '0')
                                    continue;
                                s.push({curr.first + fixed_x[k], curr.second + fixed_y[k]});
                                visited[curr.first + fixed_x[k]][curr.second + fixed_y[k]] = true;
                            }
                        }
                    }
                }
            }
        }
        return num;
    }
    bool **visited;
    vector<point> lands;
    int fixed_x[4] = {0, 1, 0, -1};
    int fixed_y[4] = {-1, 0, 1, 0};
};

int main()
{
    Solution sol;
    vector<vector<char>> tmp({{}});
    int num = sol.numIslands(tmp);
    return 0;
}