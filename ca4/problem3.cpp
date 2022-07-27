#include<iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>* make_team(int V, vector<vector<int>> adjacent) {
    vector<int>* team = new vector<int>(V);
    vector<int> col(V, -1);
    queue<pair<int, int> > q;
    for (int i = 0; i < V; i++) {
        if (col[i] == -1) {
            q.push({ i, 0 });
            col[i] = 0;
            (*team)[i] = 0;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int v = p.first;
                int c = p.second;
                for (auto j : adjacent[v]) {
                    if (col[j] == c)
                        return NULL;
                    if (col[j] == -1) {
                        col[j] = (c) ? 0 : 1;
                        (*team)[j] = (col[j]);
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
    return team;
}

int main() {
    int n, num_enemy_pair;
    cin >> n >> num_enemy_pair;
    vector<vector<int>> enenmy_pairs(n);
    for (int i = 0; i < num_enemy_pair; i++) {
        int first, second;
        cin >> first >> second;
        enenmy_pairs[first - 1].push_back(second - 1);
        enenmy_pairs[second - 1].push_back(first - 1);
    }
    vector<int>* final_team = make_team(n, enenmy_pairs);
    if (final_team != NULL) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++)
            cout << (*final_team)[i] << ' ';
    }
    else
        cout << "No\n";
    return 0;
}