/*
CodeChef June Challenge 2020 Division 2 - Operations on a Tuple 
https://www.codechef.com/JUNE20B/problems/TTUPLE
*/

/*
!!!THIS IS NOT AN AC SOLUTION !!!
Intuition: 
- Trying to use brute force approach
- There should be solved mathematically 
*/

#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()  
{ 
    FAST_INP;
    int t,p,q,r,a,b,c,aa,bb,cc,pp,qq,rr;
    cin >> t;
    while(t--){
    	cin >> p >> q >> r >> a >> b >> c;
    	
    	// all s same
    	if(p==a&&q==b&&r==c) {
    		cout << 0 << endl;
    		continue;
		}
		
		// 2 r same
		if(
			( p==a && q==b ) ||
			( q==b && r==c ) ||
			( p==a && r==c )
		) {
			cout << 1 << endl;
			continue;
		}
		
		// multiply all values 1 time
		if( 
			p!=0 && q!=0 && r!=0 && ( (a%p==0) && (a/p) == (b/q) ) && ( (b%q==0) && (b/q) == (c/r) ) && ( (c%r==0) && (a/p) == (c/r) ) 
		) {
			cout << 1 << endl;
    		continue;
		}
		
		// multiply all values 1 time - upside down
		if( 
			a!=0 && b!=0 && c!=0 && ( (p%a==0) && (p/a) == (q/b) ) && ( (q%b==0) && (q/b) == (r/c) ) && ( (r%c==0) && (p/a) == (r/c) ) 
		) {
			cout << 1 << endl;
    		continue;
		}
		
		int ap=abs(p);
		int aq=abs(q);
		int ar=abs(r);
		if( 
			ap!=0 && aq!=0 && ar!=0 && ( (a%ap==0) && (a/ap) == (b/aq) ) && ( (b%aq==0) && (b/aq) == (c/ar) ) && ( (c%ar==0) && (a/ap) == (c/ar) ) 
		) {
			cout << 1 << endl;
    		continue;
		}
		
		// upside down
		if( 
			a!=0 && b!=0 && c!=0 && ( (ap%a==0) && (ap/a) == (aq/b) ) && ( (aq%b==0) && (aq/b) == (ar/c) ) && ( (ar%c==0) && (ap/a) == (ar/c) ) 
		) {
			cout << 1 << endl;
    		continue;
		}
    	
		int d1=a-p, d2=b-q, d3=c-r;
		// multiply 2 values 1 time and add 1 value 0/1 time
		
		if(p!=0 && q!=0 && (a%p==0) && (b%q==0) && (a/p) == (b/q)){
			if(d3==0){
				cout << 1 << endl;
			}else {
				cout << 2 << endl;
			}
			continue;
		}
		
		// upside down
		if(a!=0 && b!=0 && (p%a==0) && (q%b==0) && (p/a) == (q/b)){
			if(d3==0){
				cout << 1 << endl;
			}else {
				cout << 2 << endl;
			}
			continue;
		}
		
		if(b!=0 && c!=0 && (q%b==0) && (r%c==0) && (q/b) == (r/c)){
			if(d1==0){
				cout << 1 << endl;
			}else {
				cout << 2 << endl;
			}
			continue;
		}
		
		// upside down
		if(q!=0 && r!=0 && (b%q==0) && (c%r==0) && (b/q) == (c/r)){
			if(d1==0){
				cout << 1 << endl;
			}else {
				cout << 2 << endl;
			}
			continue;
		}
		
		if(a!=0 && c!=0 && (p%a==0) && (r%c==0) && (p/a) == (r/c) ){
			if(d2==0){
				cout << 1 << endl;
			}else {
				cout << 2 << endl;
			}
			continue;
		}
		
		// upside down
		if(p!=0 && q!=0 && (a%q==0) && (c%r==0) && (a/p) == (c/r) ){
			if(d2==0){
				cout << 1 << endl;
			}else {
				cout << 2 << endl;
			}
			continue;
		}
		
		// multiply to the closest and add once
		
		// take a & b
		if(p!=0 && q!=0 && a/p!=0 && b/q!=0 && a/p == b/q){
			int f = a/p;
			int pp=p*f;
			int qq=q*f;
			int rr=r*f;
//			cout << pp << " " << qq << " " << r << endl;
//			cout << a << " " << b << " " << c << endl;
			if(pp-a==qq-b&&qq-b==rr-c) {
				cout << 2 << endl;
				continue;
			}
			
			// dont multiply r
			if(pp-a==qq-b&&qq-b==r-c){
				cout << 2 << endl;
				continue;
			}
			
			if(pp-a==0&&qq-b==0) {
				cout << 2 << endl;
				continue;
			}
			
		}
		
		// take a & b
		if(a!=0 && b!=0 && p/a!=0 && q/b!=0 && p/a == q/b){
			int f = p/a;
			int aa=a*f;
			int bb=b*f;
			int cc=c*f;
			if(p-aa==q-bb&&q-bb==r-cc) {
				cout << 2 << endl;
				continue;
			}
			
			// dont multiply c
			if(p-aa==q-bb&&q-bb==r-c) {
				cout << 2 << endl;
				continue;
			}
			
			if(p-aa==0&&q-bb==0) {
				cout << 2 << endl;
				continue;
			}
		}
		
		// take b & c
		else if(q!=0 && r!=0 && b/q!=0 && c/r!=0 && c/r == b/q){
			int f = b/q;
			int pp=p*f;
			int qq=q*f;
			int rr=r*f;
			if(pp-a==qq-b&&qq-b==rr-c) {
				cout << 2 << endl;
				continue;
			}
			// dont multiply p
			if(p-a==qq-b&&qq-b==rr-c) {
				cout << 2 << endl;
				continue;
			}
			
			if(rr-c==0&&qq-b==0) {
				cout << 2 << endl;
				continue;
			}
		}
		
		// take b & c
		else if(b!=0 && c!=0 && q/b!=0 && r/c!=0 && r/c == q/b){
			int f = q/b;
			int aa=a*f;
			int bb=b*f;
			int cc=c*f;
			if(p-aa==q-bb&&q-bb==r-cc) {
				cout << 2 << endl;
				continue;
			}
			
			// dont multiply a
			if(p-a==q-bb&&q-bb==r-cc) {
				cout << 2 << endl;
				continue;
			}
			
			if(r-cc==0&&q-bb==0) {
				cout << 2 << endl;
				continue;
			}
		}
		
		// take a&c
		else if(p!=0 && r!=0 && a/p!=0 && c/r!=0 && c/r == a/p){
			int f = a/p;
			int pp=p*f;
			int qq=q*f;
			int rr=r*f;
			if(pp-a==qq-b&&qq-b==rr-c) {
				cout << 2 << endl;
				continue;
			}
			
			// dont multiply q
			if(pp-a==q-b&&q-b==rr-c) {
				cout << 2 << endl;
				continue;
			}
			
			if(pp-a==0&&rr-c==0) {
				cout << 2 << endl;
				continue;
			}
		}
		
		// take a&c - upside down
		else if(a!=0 && c!=0 && p/a!=0 && r/c!=0 && r/c == p/a){
			int f = p/a;
			int aa=a*f;
			int bb=b*f;
			int cc=c*f;
			if(p-aa==q-bb&&q-bb==r-cc) {
				cout << 2 << endl;
				continue;
			}
			// dont multiply b
			if(p-aa==q-b&&q-b==r-cc) {
				cout << 2 << endl;
				continue;
			}
			
			if(p-aa==0&&r-cc==0) {
				cout << 2 << endl;
				continue;
			}
		}

		int g;
		if(a!=0&&b!=0&&c!=0){
			g = __gcd(a,__gcd(b,c));
			if(g!=1){
				int aa=a/g;
				int bb=b/g;
				int cc=c/g;
				
				if(p==aa&&q==bb&&r==cc) {
		    		cout << 2 << endl;
		    		continue;
				}
				
				// 3 diffs r same
				if(p-aa==q-bb&&q-bb==r-cc) {
					cout << 2 << endl;
		    		continue;
				}
				
				// a:0 b,c non-zero
				if(p-aa==0&&q-bb==r-cc) {
					cout << 2 << endl;
		    		continue;
				}
				
				// b:0 a,c non-zero
				if(q-bb==0&&p-aa==r-cc) {
					cout << 2 << endl;
		    		continue;
				}
				
				// c:0 a,b non-zero
				if(r-cc==0&&q-bb==p-aa) {
					cout << 2 << endl;
		    		continue;
				}
			}
		}else if(a!=0&&b!=0){
			g = __gcd(a,b);
			if(g!=1){
				int aa=a/g;
				int bb=b/g;
				if(
					( p==aa&&q==bb&&r==c ) || 
					( p==aa&&q==bb&&c==0 )
				) {
		    		cout << 2 << endl;
		    		continue;
				}
				
				if(aa-p==bb-q&&bb-q==c-r) {
		    		cout << 2 << endl;
		    		continue;
				}
			}
		}else if(a!=0&&c!=0){
			g = __gcd(a,c);
			if(g!=1){
				int aa=a/g;
				int cc=c/g;
				if(
					( p==aa&&q==b&&r==cc ) || 
					( p==aa&&b==0&&r==cc )
				) {
		    		cout << 2 << endl;
		    		continue;
				}
				
				if(aa-p==cc-r&&cc-r==b-q) {
		    		cout << 2 << endl;
		    		continue;
				}
			}
		}else if(b!=0&&c!=0){
			g = __gcd(b,c);
			if(g!=1){
				int bb=b/g;
				int cc=c/g;
				if(
					( p==a&&q==bb&&r==cc ) || 
					( a==0&&q==bb&&r==cc )
				) {
		    		cout << 2 << endl;
		    		continue;
				}
				
				if(bb-q==cc-r&&cc-r==a-p) {
		    		cout << 2 << endl;
		    		continue;
				}
				
				
			}
		}
		
		
    	// add 1 time
    	if(d1==d2&&d2==d3&&d3==d1) {
    		cout << 1 << endl;
    		continue;
		}
		
		if(d1==d2){
			if(d3==0) {
				cout << 1 << endl;
			} else {
				cout << 2 << endl;
			}
			continue;
		}
		
		if(d2==d3){
			if(d1==0) {
				cout << 1 << endl;
			} else {
				cout << 2 << endl;
			}
			continue;
		}
		
		if(d1==d3){
			if(d2==0) {
				cout << 1 << endl;
			} else {
				cout << 2 << endl;
			}
			continue;
		}
		
		// add 2 times
		
		if(d1==0&&d2!=d3){
			cout << 2 << endl;
			continue;
		} else if(d2==0&&d1!=d3) {
			cout << 2 << endl;
			continue;
		} else if (d3==0&&d1!=d2){
			cout << 2 << endl;
			continue;
		}
		
		// add first multiply later
//		1
//		5 10 15
//		0 50 100

		// case a:
		int pp=p+d1;
		int qq=q+d1;
		int rr=r+d1;
		
//		printf("%d %d %d %d\n", b,qq,c,rr);
		
		if(qq!=0 && rr!=0 && b%qq==0 && c%rr==0 && b/qq == c/rr) {
			cout << 2 << endl;
			continue;
		}
		
		// case b:
		pp=p+d2;
		qq=q+d2;
		rr=r+d2;
		
		if(pp!=0 && rr!=0 && a%pp==0 && c%rr==0 && a/pp == c/rr) {
			cout << 2 << endl;
			continue;
		}
		
		// case c:
		pp=p+d3;
		qq=q+d3;
		rr=r+d3;
		
		if(pp!=0 && qq!=0 && a%pp==0 && b%qq==0 && a/pp == b/qq) {
			cout << 2 << endl;
			continue;
		}
		
		
		cout << 3 << endl;
    }
}
