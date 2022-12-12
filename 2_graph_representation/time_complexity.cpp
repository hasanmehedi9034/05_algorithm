#include <bits/stdc++.h>
using namespace std;

// constant time algorithm
int main() {
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    cout << sum << endl;

    // variable time algorithm
    int sum2 = 0;
    for (int i = 0; i <= n; i++) {
        sum2 += i;
    }
    cout << sum2 << endl;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            cout << "Hello" << endl;
        }
    }


    return 0;
}














