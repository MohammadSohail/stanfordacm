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
string s;
struct Segment
{
	int a=0,b=0,c=0;
} tree[4000002];

void build_tree(int start,int end,int i)
{
	if(start==end)
	{
		if(s[start]=='(')
		{
			tree[i].b = 1;
		}
		else
		{
			tree[i].c = 1;
		}
		return;
	}
	int mid = (start+end)>>1;
	build_tree(start,mid,2*i+1);
	build_tree(mid+1,end,2*i+2);
	int t = min(tree[2*i+1].b,tree[2*i+2].c);
	tree[i].a = tree[2*i+1].a + tree[2*i+2].a + t;
	tree[i].b = tree[2*i+1].b + tree[2*i+2].b - t;
	tree[i].c = tree[2*i+1].c + tree[2*i+2].c - t;
}
Segment query(int l,int r,int start,int end,int i)
{
	if(start>=l && end<=r) return tree[i];
	int mid = (start+end)>>1;
	if(mid>=r) return query(l,r,start,mid,2*i+1);
	else if(mid<l) return query(l,r,mid+1,end,2*i+2);
	else
	{
		Segment q1 = query(l,r,start,mid,2*i+1),q2 = query(l,r,mid+1,end,2*i+2);
		Segment ans;
		int t = min(q1.b,q2.c);
		ans.a = q1.a + q2.a + t;
		ans.b = q1.b + q2.b - t;
		ans.c = q1.c + q2.c - t;
		return ans;
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
	cin>>s;
	int n = s.length();
	build_tree(0,n-1,0);
	int m;
	cin>>m;
	rep(i,m)
	{
		int l,r;
		cin>>l>>r;
		cout<<2*query(l-1,r-1,0,n-1,0).a<<endl;
	}
	return 0;
}
