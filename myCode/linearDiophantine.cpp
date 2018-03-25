ll x,y,d;

void solve(ll a,ll b){
	if(b == 0){
		x = 1;
		y = 0;
		d = a;
		return ;
	}
	solve(b, a%b);
	ll x1 = y;
	ll y1 = x -(a/b)*y;
	x = x1;
	y = y1;
}

int main()
{
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ll a,b,n;
	cin >> n >> a >> b;
	
	solve(a,b);

	if(n % d!=0){
		cout << "NO";
	}
	else{
		ll zmax,zmin;
		ll p,q;
		//cout << x << " " << y << " " << d << "\n";
		ll xres1,yres1,xres2,yres2;
		p = (n*x)/d;
		q = (n*y)/d;
		//cout << a*p + b*q << "\n";
		//cout << p << " " << q << "\n";
		zmax = (q*d)/a;
		zmin = -1*(p*d)/b;
		//cout << zmin << " " << zmax << "\n";
		xres1 = p+((b/d)*zmin);
		yres1 = q-((a/d)*zmin);
		xres2 = p+((b/d)*zmax);
		yres2 = q-((a/d)*zmax);
		if(xres1 >= 0 && yres1 >= 0){
			cout << "YES\n" << xres1 << " " << yres1; 
		}
		else if(xres2 >=0 && yres2 >= 0){
			cout << "YES\n" << xres2 << " " << yres2; 	
		}
		else{
			cout << "NO\n";
		}
	}

	return 0;
}