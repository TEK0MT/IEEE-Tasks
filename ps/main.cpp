#include <iostream>
#include <cmath>
using namespace std;

int main() {
int x = 0;
cin >> x;

long long sum = (static_cast<long long>(x) * (x + 1) * (2 * x + 1)) / 6;
cout << sum;
    return 0;
}
