#include<bits/stdc++.h>
using namespace std;
#define fl(i,a,n) for(int i=a;i<(n);++i)
#define rfl(i,a,n) for(int i=(n-1);i>a-1;i--)
#define rep(i,n) for(int i=1;i<=n;i++)
#define rrep(i,n) for(int i=n;i>0;i--)
#define srt(a,n) sort(a+1,a+n+1)
#define li long
#define ll long long
#define ull unsigned long long
#define clr(a) memset(a,0,sizeof(a))
#define vi vector <int>
#define vll vector <long long>
#define pii pair <int,int>
#define mod 1000000007
#define pb push_back
#define fr first
#define sc second
#define loop(i,n) for(int i=0;i<n;i++)
#define pi 3.1415926535
#define maxn 100005

int depth[maxn],s[maxn],table[maxn][20] = {0};
vi graph[maxn];
pii edges[maxn];

void dfs1(int x)
{
	loop(i,graph[x].size())
	{
		if(graph[x][i]!=table[x][0])
		{
			depth[graph[x][i]] = depth[x] + 1;
			table[graph[x][i]][0] = x;
			dfs1(graph[x][i]);
		}
	}
}

void build_table(int n)
{
	rep(i,19)
	{
		rep(j,n)
		{
			table[j][i] = table[table[j][i-1]][i-1];
		}
	}
}

int lca(int x,int y)
{
	if(depth[x]>depth[y]) swap(x,y);
	for(int i=19;~i;i--)
	{
		if(depth[table[y][i]]>=depth[x]) y = table[y][i];
	}
	//cout<<y<<endl;
	if(x==y) return x;
	for(int i=19;~i;i--)
	{
		if(table[x][i]!=table[y][i])
		{
			x = table[x][i];
			y = table[y][i];
		}
	}
	return table[x][0];
}

void dfs2(int x)
{
	loop(i,graph[x].size())
	{
		if(graph[x][i]!=table[x][0]) dfs2(graph[x][i]),s[x]+=s[graph[x][i]];
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	rep(i,n-1)
	{
		int x,y;
		cin>>x>>y;
		graph[x].pb(y);
		graph[y].pb(x);
		edges[i] = {x,y};
		//cout<<x<<" "<<y<<endl;
	}
	dfs1(1);
	// rep(i,n)
	// {
	// 	cout<<depth[i]<<endl;
	// }
	build_table(n);
	int m;
	cin>>m;
	loop(i,m)
	{
		int x,y;
		cin>>x>>y;
		s[x]++;
		s[y]++;
		s[lca(x,y)]-=2;
	}
	dfs2(1);
	rep(i,n-1)
	{
		if(depth[edges[i].fr]>depth[edges[i].sc])
		{
			cout<<s[edges[i].fr]<<' ';
		}
		else cout<<s[edges[i].sc]<<' ';
	}
	cout<<endl;
	return 0;
}
