/*
5 7
0 0
4 3
S..#...
.#...#.
.#.....
..##...
#.#E.#.
*/

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

ll shortestPath(vector<string>& v, ll start_x, ll start_y, ll end_x, ll end_y, ll r, ll c) {
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    vector<ll> dr = {-1,1,0,0};
    vector<ll> dc = {0,0,1,-1}; // left, right, up, down
    queue<ll> x; queue<ll> y; // queues to store x and y coordinates
    ll ct_path = 0, nodes_left_in_layer = 1, nodes_in_next_layer = 0;
    x.push(start_x);
    y.push(start_y);
    visited[start_x][start_y]=true;
    bool reached_end = false;
    while (!x.empty()) {
        ll sq_x = x.front(), sq_y = y.front();
        x.pop(); y.pop();
        if (v[sq_x][sq_y]=='E') {
            reached_end=true;
            break;
        }
        for (ll i=0;i<4;i++) {
            ll next_row = sq_x+dr[i];
            ll next_col = sq_y+dc[i];
            if (next_row<0 or next_col<0 or next_row>=r or next_col>=c) continue;
            if (visited[next_row][next_col]) continue;
            if (v[next_row][next_col]=='#') continue;
            x.push(next_row); y.push(next_col);
            visited[next_row][next_col]=true;
            nodes_in_next_layer++;
        }
        nodes_left_in_layer--;
        if (nodes_left_in_layer==0) {
            ct_path++;
            nodes_left_in_layer=nodes_in_next_layer;
            nodes_in_next_layer=0;
        }
    }
    if (reached_end) return ct_path;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r,c,start_x, start_y, end_x, end_y;
    cin>>r>>c>>start_x>>start_y>>end_x>>end_y;
    vector<string> v(r,"");
    repl(i,0,r) cin>>v[i];
    print(shortestPath(v, start_x,start_y,end_x,end_y,r,c));
    return 0;
}