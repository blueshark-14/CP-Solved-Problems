#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;
using namespace std;

#define pb                     push_back
#define ll                     long long
#define forn(i,n)              for(int i=0; i<(int)n; i++)
#define forn1(i,n)              for(int i=1; i<=(int)n; i++)

#define sfd(a)                 scanf("%d", &a)
#define sffd(a,b)              scanf("%d%d", &a, &b)
#define sffl(a,b)              scanf("%lld%lld", &a,&b)
#define sfl(a)                 scanf("%lld", &a)

#define pii                    pair<int , int>
#define pll                    pair<ll , ll>
#define ff                     first
#define ss                     second
#define mem(a, val)            memset(a, val, sizeof(a))
#define all(x)                 (x).begin(), (x).end()

#define INF_mx                 1e18
#define gcd(a,b)               __gcd(a, b)
#define lcm(a,b)               (a*b)/__gcd(a,b)
#define PRINT                  cout<<"hi"<<endl
#define PI acos(-1)
#define fast_in_out          ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Q    int q; cin>>q; while(q--)
///###### adj move #####
int fx[4] = {0 , 0 , 1 , -1};
int fy[4] = {1 , -1 , 0 , 0};
///----------------------------

const int INF = 0x3f3f3f3f;
int N, M ; ll sum;
int grid[101][101];
bool vis[101][101];
///------MIN HEAP -----------
priority_queue <pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>> > pq;
///-----
bool valid(int x, int y, int L){
   if(x>=0 && x<N && y>=0 && y<M && !vis[x][y] && grid[x][y]<=L) return true;
   else
    return false;
}

void dfs(int ux, int uy, int L){

    vis[ux][uy]=true;

    for(int i=0; i<4; i++){
        int vx = ux+fx[i];
        int vy = uy+fy[i];
        if(valid(vx, vy, L)){
            sum+=(ll)(L-grid[vx][vy]);
            dfs(vx, vy, L);
        }else if(grid[vx][vy]>L && !vis[vx][vy]){
           pq.push({grid[vx][vy], {vx, vy} }); /// new boundary push
        }
    }

}
int main()
{
    Q
    {
        sffd(N,M);

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                sfd(grid[i][j]);
                if(i==0 || i==N-1 || j==0 || j==M-1) pq.push( { grid[i][j] ,{i,j} } );
            }
        }
        ll ans=0;
        while(!pq.empty()){
                auto x = pq.top(); pq.pop();
            sum=0;
            int i,j,val;
            val = x.ff; i=x.ss.ff; j=x.ss.ss;
            if(!vis[i][j]){
                dfs(i, j, val);
            }
            ans+=sum;
        }
        printf("%lld\n", ans);
       mem(vis, false);

    }
    return 0;
}

