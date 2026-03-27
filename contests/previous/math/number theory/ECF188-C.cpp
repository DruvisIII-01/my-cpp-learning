#include <iostream>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return (a / g) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll a, b, c, m;
        cin >> a >> b >> c >> m;

        ll A = m / a;
        ll B = m / b;
        ll C = m / c;

        ll AB = m / lcm(a, b);
        ll AC = m / lcm(a, c);
        ll BC = m / lcm(b, c);

        ll ABC = m / lcm(lcm(a, b), c);  
        
        ll WA = (A - AB - AC + ABC) * 6 + (AB + AC - 2 * ABC) * 3 + ABC * 2;
        ll WB = (B - AB - BC + ABC) * 6 + (AB + BC - 2 * ABC) * 3 + ABC * 2;
        ll WC = (C - AC - BC + ABC) * 6 + (AC + BC - 2 * ABC) * 3 + ABC * 2;

        cout << WA << " " << WB << " " << WC << "\n";
    }

    return 0;
}