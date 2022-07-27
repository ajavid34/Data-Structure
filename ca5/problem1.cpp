#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_common(string base, string str_max, int s_max, int divisor) {
    for (int i = 0; i < s_max; i += divisor)
        if (str_max.substr(i, divisor) != base)
            return false;
    return true;
}
void find_divisors(int s_max, int s_min, vector<int>& divisor) {
    for (int i = 1; i <= s_max; i++)
        if (s_max % i == 0 && s_min % i ==0)
            divisor.push_back(i);
}
int main() {
    string x, y, str_max, str_min;
    int s_min, s_max;
    cin >> x >> y;
    if (x.size() > y.size()) {
        s_min = y.size();
        s_max = x.size();
        str_max = x;
        str_min = y;
    }
    else {
        s_min = x.size();
        s_max = y.size();
        str_max = y;
        str_min = x;
    }
    vector<int> divisor;
    find_divisors(s_max, s_min, divisor);
    int cnt = 0;
    for (int i = 0; i < divisor.size(); i++) {
        string base = x.substr(0, divisor[i]);
        if (is_common(base, str_max, s_max, divisor[i]))
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}