#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char a[n];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                cnt++;
                i++;
            }
        }
        cout << n - cnt << endl;

    }
    return 0;
}