#include<iostream>
#include <vector>
#include<cmath>
#include <string>

using namespace std;

const int row_delta[4] = { 1, 0, -1, 0 };
const int col_delta[4] = { 0, 1, 0, -1 };

void count_neighbor(vector<vector<int>>& map, int current_row, int current_col, int& count) {
    for (int move = 0; move < 4; move++) {
        int new_row = current_row + row_delta[move];
        int new_col = current_col + col_delta[move];
        if (new_row < 0 || new_row >= map.size() || new_col < 0 || new_col >= map[0].size())
            continue;
        if (map[new_row][new_col] == 1) {
            map[new_row][new_col] = -1;
            count++;
            count_neighbor(map, new_row, new_col, count);
        }
    }
}
void ins_sort(vector <int>& a) {
    int key;
    int k;
    for (int i = 1; i < a.size(); i++) {
        key = a[i];
        for (k = i - 1; k > -1 && a[k] > key; k--)
            a[k + 1] = a[k];
        a[k + 1] = key;
    }
}
void print_largest_k(vector<int>& band_num, int k) {
    int sum = 0;
    int size = band_num.size();
    ins_sort(band_num);
    for (int i = size - 1; (i > size - k - 1) && i > -1; i--) {
        sum += band_num[i];
    }
    cout << sum;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string input;
    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++)
            map[i][j] = (int)input[j] - 48;
    }
    vector <int> band_num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                int count = 1;
                map[i][j] = -1;
                count_neighbor(map, i, j, count);
                band_num.push_back(count);
            }
        }
    }
    print_largest_k(band_num, k);
    return 0;
}