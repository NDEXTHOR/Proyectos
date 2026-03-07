#include <bits/stdc++.h>

using namespace std;

int n;

int factorial(int n){
    return (n == 1 || n == 0) ? 1 : n * factorial(n-1);
}

int main(){
    cout << "Ingresa un numero: ";
    cin >> n;
    cout << factorial(n);
    return 0;
}

