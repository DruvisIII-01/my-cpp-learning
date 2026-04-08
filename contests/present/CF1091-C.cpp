#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;

        long long g1 = gcd(n, a);
        long long g2 = gcd(m, b);
        long long g = gcd(n, m);

        if (g1 == 1 && g2 == 1 && g <= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}