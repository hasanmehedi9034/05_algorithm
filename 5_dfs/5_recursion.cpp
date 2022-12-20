/*

1. can we solve the smallest problem?
2. can we solve the larger problem given the smaller problem is already solved?
3. generalize the relation into an formula

*/

#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    if (n == 1) return 1;
    return sum(n - 1) + n;
}

bool is_palindrom(string str) {
    int n = str.size();
    int l = 0, r = n - 1;

    while(l < r) {
        if (str[l] != str[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

bool is_palindrom2(string str) {
    if (str == "" || str.size() == 1) return true;

    int n = str.size();
    string small_str = str.substr(1, n - 2);
    
    return is_palindrom2(small_str) && (str[0] == str.back());
}

int main() {
    // int n = 10;

    cout << sum(10) << endl;
}





