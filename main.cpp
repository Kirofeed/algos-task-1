#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> mosquitos(n);
    for (int i = 0; i < n; ++i) {
        cin >> mosquitos[i];
    }

    vector<int> all_eaten(n, -1);
    vector<int> prev(n, -1);

    all_eaten[0] = mosquitos[0];

    for (int i = 0; i < n; ++i) {
        if (all_eaten[i] != -1) {
            if (i + 2 < n && all_eaten[i + 2] < all_eaten[i] + mosquitos[i + 2]) {
                all_eaten[i + 2] = all_eaten[i] + mosquitos[i + 2];
                prev[i + 2] = i;
            }
            if (i + 3 < n && all_eaten[i + 3] < all_eaten[i] + mosquitos[i + 3]) {
                all_eaten[i + 3] = all_eaten[i] + mosquitos[i + 3];
                prev[i + 3] = i;
            }
        }
    }

    if (all_eaten[n - 1] == -1) {
        cout << -1 << endl;
    } else {
        cout << all_eaten[n - 1] << endl;

        vector<int> path;
        for (int i = n - 1; i != -1; i = prev[i]) {
            path.push_back(i + 1);
        }
        reverse(path.begin(), path.end());

        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
