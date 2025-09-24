
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &maze, int sR, int sC, int row, int col, vector<vector<bool>> &visited)
{
    if ((sR >= 0) && (sR < row) && (sC >= 0) && (sC < col) && (maze[sR][sC] == 1) && (visited[sR][sC] == 0))
    {
        return true;
    }

    return false;
}

void runRat(vector<vector<int>> &maze, int sR, int sC, int row, int col, vector<vector<bool>> &visited, string &temp, vector<string> &ans)
{

    int r[] = {0, 1, 0, -1};
    int c[] = {1, 0, -1, 0};
    char ch[] = {'R', 'D', 'L', 'U'};

    // base case
    if (sR >= row - 1 && sC >= col - 1)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int newsR = sR + r[i];
        int newsC = sC + c[i];
        if (isSafe(maze, newsR, newsC, row, col, visited))
        {

            // if isSafe mark visited, push in ans and try for next
            // mark
            visited[newsR][newsC] = true;

            // push-in temp string
            temp.push_back(ch[i]);

            // try next
            runRat(maze, newsR, newsC, row, col, visited, temp, ans);

            // if fails backtrack by marking un-visited, and pop the char from temp string
            visited[newsR][newsC] = false;
            temp.pop_back();
        }
    }
}

int main()
{

    vector<vector<int>> maze = {{1, 0, 1, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 1, 1}};

    int n = 4;
    // have to do-> find all possible soln -> need to check=> was it in range of matrix, does possible to visit and does already visited -> if yes then visit and go on else backtrack

    // initial Condition-> if maze[0][0] is 0

    int row = n, col = n;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<string> ans;
    string temp;

    if (maze[0][0] == 0)
    {
        cout << "No possiblities initial pos. is 0";
        return 0;
    }
    else
    {
        visited[0][0] = true;
    }

    runRat(maze, 0, 0, row, col, visited, temp, ans);

    printf("Printing- \n");
    for (string x : ans)
    {
        cout << x << endl;
    }

    return 0;
}