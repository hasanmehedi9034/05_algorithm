/*
calculate the nth fibonacchi number:
*/

#include <bits/stdc++.h>
using namespace std;

int fibo(int n) {
    // base case
    if (n == 0) return 0;
    if (n == 1) return 1;

    // general case
    return fibo(n - 1) + fibo(n - 2);
}

int main() {

}






