#include <bits/stdc++.h>
using    namespace std;
#define  lli long long int
#define  ulli unsigned lli
#define  ld  long double
#define  vi  vector<int>
#define  vl  vector<lli>
#define  pb  push_back
#define  all(v) v.begin(),v.end()

lli stoi( string &s ){
    lli ans=0;
    for( int i=0 ;i<s.size() ;i++ ){
        ans = ans*10 + ( s[i] - '0' );   }
    return ans;                          }

vector<int> get_max_profit( vector<int> &v ){
    vector<int> ans(3);
    int mn = INT_MAX ,n = v.size() ,profit = 0 ,t1 = 9 ,t2 = 30  ,sell = -1;

    for( int i=0 ;i<n ;i++ ){
        if( mn > v[i] ){
            mn = v[i];
        }else{
            if( ans[0] < v[i] - mn ){
                ans[0] = v[i] - mn;
                ans[1] = t1;
                ans[2] = t2;
            }
        }

        t2+=10;
        if( t2 == 60 ){
            t1++;
            if(t1 == 13) t1 = 1;
            t2 = 0;
        }
    }
    return ans;
}

string fix_time(int n){
    if( n/10 == 0 ){
        cout << "0" << n%10;
    }else{
        cout << (n/10)%10 << n%10;
    }
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

        auto ans = get_max_profit( v );
        cout << '[' << ans[0] << ',';

        fix_time(ans[1]);
        cout << '.';
        fix_time(ans[2]);
        cout << "]\n";
    }    
}