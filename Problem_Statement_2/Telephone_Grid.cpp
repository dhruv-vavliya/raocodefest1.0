#include <bits/stdc++.h>
using    namespace std;
#define  lli long long int
#define  ulli unsigned lli
#define  ld  long double
#define  vi  vector<int>
#define  vl  vector<lli>
#define  pb  push_back
#define  all(v) v.begin(),v.end()

void display( vector<vi> &ans ,int n ){
    cout << '[';
    for( int i=1 ;i<=n ;i++ ){
        cout << '[';
        for( int j=1 ;j<=n ;j++ ){
            if( j == n ) cout << ans[i][j] << ']';
            else cout << ans[i][j] << ',';
        }
        if( i < n ) cout << ',';
    }
    cout << "]\n";
}

void go( int i ,int j ,int n ,vector<vi> &row ,vector<vi> &col ,vector<vi> &ans ){
    if( i > n ){
        display(ans ,n);
        return;
    }

    for( int k=1 ;k<=n ;k++ ){
        if( !row[i][k] && !col[j][k] ){
            ans[i][j] = k;
            row[i][k] = 1 ,col[j][k] = 1;
            if( j+1 <= n ){
                go( i ,j+1 ,n ,row ,col ,ans );
            }else{
                go( i+1 ,2 ,n ,row ,col ,ans );
            }
            row[i][k] = 0 ,col[j][k] = 0;
        }        
    }
}

// @uthor : Dhruv_Vavliya
int32_t main(){
    cin.tie(0), cin.sync_with_stdio(0);

    freopen( ".\\input.txt", "r" , stdin);
    freopen( ".\\output.txt", "w", stdout);
    
    int n;
    cin >> n;  

    vector<vi> row(n+1 ,vi(n+1)) ,col( n+1 ,vi(n+1) ) ,ans(n+1 ,vi(n+1));
    for( int i=1 ;i<=n ;i++ ){
        ans[i][1] = n-i+1;
        row[i][n-i+1] = 1;
        col[1][n-i+1] = 1;
    }
    go( 1 ,2 ,n ,row ,col ,ans );
}