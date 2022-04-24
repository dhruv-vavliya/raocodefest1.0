#include <bits/stdc++.h>
using    namespace std;
#define  lli long long int
#define  vi  vector<int>
#define  pb  push_back
#define  all(v) v.begin(),v.end()

lli stoi( string &s ){
    lli ans=0;
    for( int i=0 ;i<s.size() ;i++ ){
        ans = ans*10 + ( s[i] - '0' );   }
    return ans;                          }

// @uthor : Dhruv_Vavliya
int32_t main(){
    cin.tie(0), cin.sync_with_stdio(0);

    freopen( ".\\input.txt", "r" , stdin);
    freopen( ".\\output.txt", "w", stdout);

    string d;
    getline(cin ,d);
    int n = stoi(d);

    vector<pair<lli,int>> v;
    for( int i=1 ;i<=n ;i++ ){
        string s;
        getline(cin ,s);

        set<lli> st;
        int sz = s.size();
        int j = 1;
        while( j < sz ){
            string temp;
            while( j<sz and s[j] != ',' and s[j] != ']' ){
                temp.pb(s[j]);
                j++;
            }
            st.insert(stoi(temp));
            if( s[j] == ']' ) break;
            j++;
        }

        lli sm =0;
        for( auto &val : st){
            sm += val;
        }
        v.pb({sm,i});
    }

    sort(all(v));
    reverse(all(v));
    cout << '[';
    for( int i=0 ;i<n ;i++ ){
        if( i == n-1 ) cout << v[i].second << ',' << v[i].first << ']';
        else cout << v[i].second << ',' << v[i].first << ',';
    }
}