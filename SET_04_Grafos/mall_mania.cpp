#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int EMPTY = -1;  // empty cell
const int GOAL = -2;   // goal cell
const int MAXSIZE = 2010;  // maximum size of the maze
vector<vector<int>> grid;   // the maze

vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // directions

int main() {
    int p;  // number of test cases
    while (cin >> p, p) {  // for each test case
        grid.assign(MAXSIZE, vector<int>(MAXSIZE, EMPTY)); // initialize the maze

        int a, s;  // number of rows and columns
        queue<pair<int, int>> q;  // queue of cells to be processed
        while (p--) {  // for each person
            cin >> a >> s; // read the number of rows and columns
            grid[a][s] = 0; // mark the cell as visited
            q.push({a, s}); // add the cell to the queue
        }
        cin >> p; // read the number of goals
        while (p--) { // for each goal
            cin >> a >> s; // read the coordinates of the goal
            grid[a][s] = GOAL;  // mark the cell as goal
        }

        int distance;   // distance from the starting cell
        bool found_path = false;  // flag to indicate if a path was found
        while (!q.empty() && !found_path) {  // while the queue is not empty and no path was found
            pair<int, int> u = q.front();  // get the first cell in the queue
            q.pop();  // remove the cell from the queue

            for (auto&& d : dirs) {  // for each direction
                pair<int, int> v = {u.first + d.first, u.second + d.second};  // get the next cell

                if (0 <= v.first && v.first < MAXSIZE &&   // if the cell is inside the maze
                    0 <= v.second && v.second < MAXSIZE) {  // and
                        if (grid[v.first][v.second] == EMPTY) {  // if the cell is empty
                            grid[v.first][v.second] = grid[u.first][u.second] + 1;  // mark the cell as visited
                            q.push(v);     // add the cell to the queue
                        } else if (grid[v.first][v.second] == GOAL) {  // if the cell is a goal
                            distance = grid[u.first][u.second] + 1;  // get the distance
                            found_path = true;    // mark that a path was found
                        }
                    }
            }
        }

        cout << distance << endl;  // print the distance
    }
}