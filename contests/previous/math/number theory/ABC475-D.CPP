#include <bits/stdc++.h>
using namespace std ;

#define int long long
signed main() {
    //pre
    const int N = 100000000 ;
    //comp[i] = 1 means i * 2 + 1 is not an odd prime
    //o.w. comp[i] = 0 means i * 2 + 1 is an odd prime
    int lim = (int)sqrt(N) ;
    vector<bool> he(N) ;

    for(int i = 3 ; i <= lim ; i += 2){
        if(!he[i / 2]){
            for(int j = i * i ; j <= N ; j += 2 * i){
                he[j / 2] = 1 ;
            }
        }
    }

    vector<vector<int>> primes(10, vector<int>()) ;
    primes[1].push_back(2) ;
    for(int p = 3 ; p <= N ; p += 2){
        if(!he[p / 2])
        primes[to_string(p).size()].push_back(p) ;
    }

    //formal
    string s ; cin >> s ; 
    bool find = false ;

    for(int p : primes[s.size()]){
        string pstr = to_string(p) ;
        vector<int> hsh1(26, -1) ;
        vector<int> hsh2(10, -1) ;

        bool cur1 = true ;
        for(int i = 0 ; i < s.size() ; i++){
            if(hsh1[s[i] - 'a'] == -1)
            hsh1[s[i] - 'a'] = pstr[i] - '0' ;
            else if(hsh1[s[i] - 'a'] != pstr[i] - '0') {
                cur1 = false ;
                break ;
            }
        }

        bool cur2 = true ;
        for(int i = 0 ; i < pstr.size() ; ++i){
            if(hsh2[pstr[i] - '0'] == -1)
            hsh2[pstr[i] - '0'] = s[i] - 'a' ;
            else if(hsh2[pstr[i] - '0'] != s[i] - 'a'){
                cur2 = false ;
                break ;
            }
        }

        if(cur1 && cur2){
            find = true ;
            cout << p ;
            break ;
        }
    }if(!find) cout << "-1" ;
    return 0;
}