#include <bits/stdc++.h>
using    namespace std;
#define  lli long long int
#define  vi  vector<int>
#define  vl  vector<lli>
#define  pb  push_back
#define  all(v) v.begin(),v.end()

lli stoi( string &s ){
    lli ans=0;
    for( int i=0 ;i<s.size() ;i++ ){
        ans = ans*10 + ( s[i] - '0' );   }
    return ans;                          }

bool is_subsequence( vi &v ,vi &order ){
    int j=0;
    for( int i=0 ;i<order.size() ;i++ ){
        if( v[j] == order[i] ){
            j++;
        }
    } 

    if( j == v.size() ){
        return true;
    }else{
        return false;
    }
}

vector<int> get_input(){
    string s;
    getline(cin ,s);

    vector<int> v;
    int sz = s.size();
    int j = 1;
    while( j < sz ){
        string temp;
        while( j<sz and s[j] != ',' and s[j] != ']' ){
            temp.pb(s[j]);
            j++;
        }
        v.pb(stoi(temp));
        if( s[j] == ']' ) break;
        j++;
    }
    return v;
}


// @uthor : Dhruv_Vavliya
int32_t main(){
    cin.tie(0), cin.sync_with_stdio(0);

    freopen( ".\\input.txt", "r" , stdin);
    freopen( ".\\output.txt", "w", stdout);

    string d;
    getline(cin ,d);
    int n = stoi(d);

    for( int i=1 ;i<=n ;i++ ){
        vi online = get_input();
        vi offline = get_input();
        vi orders = get_input();

        if( is_subsequence( online ,orders) and is_subsequence(offline ,orders) ){
            cout << "Valid\n";
        }else{
            cout << "Invalid\n";
        }
    }
}