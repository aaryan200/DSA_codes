#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define repi(i,a,b) for (int i=a;i<b;i++)
#define repl(i,a,b) for (ll i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)

ll shortestPath(vector<string>& v, ll r, ll c) {
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    vector<ll> dr = {1,0};
    vector<ll> dc = {0,1}; // right, down
    queue<ll> x; queue<ll> y; // queues to store x and y coordinates
    ll ct_room = 0;
    x.push(0);
    y.push(0);
    visited[0][0]=true;
    while (!x.empty()) {
        ll sq_x = x.front(), sq_y = y.front();
        x.pop(); y.pop();
        for (ll i=0;i<2;i++) {
            ll next_row = sq_x+dr[i];
            ll next_col = sq_y+dc[i];
            if (next_row<0 or next_col<0 or next_row>=r or next_col>=c) continue;
            if (v[next_row][next_col]=='.') continue;
            if (visited[next_row][next_col]) {
                ct_room++;
                continue;
            }
            x.push(next_row); y.push(next_col);
            visited[next_row][next_col]=true;
        }
    }
    return ct_room;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r,c;
    cin>>r>>c;
    vector<string> v(r,"");
    repl(i,0,r) cin>>v[i];
    print(shortestPath(v,r,c));
    return 0;
}