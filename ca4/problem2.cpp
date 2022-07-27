#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int row_delta[8] = { 1, 0, -1, 0, 1, -1, 1, -1};
const int col_delta[8] = { 0, 1, 0, -1, 1, -1, -1, 1};

struct Point {
    int row;
    int col;
};
struct queue_node {
    Point pt;
    int dist;
};
bool is_valid(int row, int col, int n, int m) {
    return (row >= 0) && (row < n) &&
        (col >= 0) && (col < m);
}
int BFS(vector<vector<char>>& map, Point src, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[src.row][src.col] = true;
    queue<queue_node> q;
    queue_node s = { src, 0 };
    q.push(s); 
    while (!q.empty()) {
        queue_node curr = q.front();
        Point pt = curr.pt;
        if (pt.row == 0 || pt.col == 0 || pt.row == n - 1 || pt.col == m - 1)
            return curr.dist + 1;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int row = pt.row + row_delta[i];
            int col = pt.col + col_delta[i];
            if (is_valid(row, col, n, m) && map[row][col] == '@' &&
                !visited[row][col]) {
                visited[row][col] = true;
                queue_node adj_cell = { {row, col}, curr.dist + 1 };
                q.push(adj_cell);
            }
        }
    }
    return -1;
}
int main() {
    int n, m;
    cin >> n >> m;
    string input;
    Point crystal;
    vector<vector<char>> map(n, vector<char>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++) {
            map[i][j] = input[j];
            if (input[j] == '$') {
                crystal.row = i;
                crystal.col = j;
            }
        }
    }
    cout << BFS(map, crystal, n, m);
}