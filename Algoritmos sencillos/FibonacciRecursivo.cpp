#include <bits/stdc++.h>

using namespace std;

long fibonacci (int n){
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
