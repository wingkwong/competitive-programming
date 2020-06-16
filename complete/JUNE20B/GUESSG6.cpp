/*
CodeChef June Challenge 2020 Division 2 - Guessing Game
https://www.codechef.com/JUNE20B/problems/GUESSG
*/

/*
!!!THIS IS NOT AN AC SOLUTION !!!
Intuition: 
- ask every 2 questions to eliminate 25% of numbers
- if there is two disjoint set, it should combine them to find the numbers at 25%, 50% and 75% (See Python Version)

PS: I named this file as GUESSG6.cpp instead of GUESSG.cpp because this is my 6th version. 
*/

#include <bits/stdc++.h>
using namespace std;

//template<class OutputIterator, class Size, class Assignable>
//void iota_n(OutputIterator first, Size n, Assignable value)
//{
//	generate_n(first, n, [&value]() {
//		return value++;
//	});
//}

int findMedian(int a, int b, int c, int d){
	int m=b-a+1, n=d-c+1;
	int k=(m+n)/2;
	int mid = (k>m? c+(k-m) : a+k);
	return mid;
}

void solve(int l, int r);

void solve2(int a, int b, int c, int d)
{
//	vector<int> v1,v2,v3;
//	v1.reserve(b-a+1);
//	v2.reserve(d-c+1);
//	iota_n(back_inserter(v1),b-a+1, a);
//	iota_n(back_inserter(v2),d-c+1, c);
//	cout << v1.size() << endl;
//	cout << v2.size() << endl;
//	v3.reserve(v1.size()+v2.size());
//	v3.insert(v3.end(),v1.begin(),v1.end());
//	v3.insert(v3.end(),v2.begin(),v2.end());
//	cout << v3[v3.size()/2] << endl;
//	int l=v3.front();
//	int mid=v3[v3.size()/2];
//	int r=v3.back();
//	cout << mid << endl;  // 54
//	int mid=(a+d)/2;
	int m=b-a+1, n=d-c+1;
	int k=(m+n)/2;
//	printf("%d %d %d %d\n",c,b,k,m);
	int l=(k>m?c:a);
	int mid = (k>m? c+(k-m) : a+k);
	int r=(k>m?d:b);
	printf("%d\n",mid);
	fflush(stdout);
	char res[1]; scanf("%s",res);
	if(strcmp(res,"E")==0) exit(0);
	if(strcmp(res,"L")==0){
		int mid2 = (k>m? mid+(r-mid)/2: findMedian(mid+1,b,c,d));
//		int mid2=mid+(r-mid)/2; 
		printf("%d\n",mid2);
		fflush(stdout);
		char res2[1]; scanf("%s",res2);
		if(strcmp(res2,"E")==0) exit(0);
		if(strcmp(res2,"G")==0) {
			if(k>m) {
				solve(mid2+1,d);
				solve2(a,b,c,mid-1);
			} else{
				solve2(a,mid-1,mid2+1,d);  //1-49 76..100
			}
		} else {
			solve2(a,b,c,mid2-1); //1..74
		}
	} else {
		int mid2 = (k>m? findMedian(a,b,c,mid-1) : l+(mid-l)/2);
//		int mid2=l+(mid-l)/2;
		printf("%d\n",mid2);
		fflush(stdout);
		char res2[1]; scanf("%s",res2);
		if(strcmp(res2,"E")==0) exit(0);
		if(strcmp(res2,"G")==0) { 
			solve2(mid2+1,b,c,d); // 26..100
		} else {
			if(k>m) {
				solve2(a,mid2-1,mid+1,d);
			} else {
				solve(a,mid2-1);
				solve2(mid+1,b,c,d);
			}
//			solve2(a,mid2-1, mid+1,d); // 1..24   51..100
		}
	}
}

void solve(int l, int r)
{
	if(r>=l){
//		printf("Checking l:%d  r:%d \n", l,r);
		int mid=l+(r-l)/2; //50
		printf("%d\n",mid);
		fflush(stdout);
		char res[1]; scanf("%s",res);
		if(strcmp(res,"E")==0) exit(0);
		if(strcmp(res,"L")==0){
			int mid2=mid+(r-mid)/2; //75
			printf("%d\n",mid2);
			fflush(stdout);
			char res2[1]; scanf("%s",res2);
			if(strcmp(res2,"E")==0) exit(0);
			if(strcmp(res2,"G")==0) {
				solve2(l,mid-1,mid2+1,r); //1-49 76..100
			} else {
				solve(l,mid2-1); //1..74
			}
		} else {
//			int mid2=l+(r-mid)/2; //25
			int mid2=l+(mid-l)/2;
			printf("%d\n",mid2);
			fflush(stdout);
			char res2[1]; scanf("%s",res2);
			if(strcmp(res2,"E")==0) exit(0);
			if(strcmp(res2,"G")==0) { 
				// >25 >50, 
				solve(mid2+1,r);  // 26..100
			} else {
				// <25 .. >50 
				solve2(l,mid2-1, mid+1,r); // 1..24   51..100
			}
		}
	}
}

//1----------50(mid)-----------100(r)

int main()
{
//	solve2(34,49,51,72);
//	solve2(1,24,51,100);
	int n; scanf("%d",&n);
	solve(1, n);
	return 0;
}



// 34 35 36 37 38    39 40 41 42 43
// 44 45 [46] 47 48  49 |          51 52 53 [54]
// 55 56 57 58 59    60 61 62 63 64
// 65 66 67 68 69    70 71 72

// 34 35 36 37 38    39 40 41 42 43
// 44 45 46 47 48 	  49 | 51 52 53 [54]
// 55 56 57 58 59    60 [[61]] 62 63 64
// 65 66 67 68 69    70 71 72


// 34 35 36 37 38    39 40 [41] 42 43
// 44 45 46 47 [48]  49 | 51 52 53 [[54]]
// 55 56 57 58 59    60 61 62 63 64
// 65 66 67 68 69    70 71 72


// 34 35 36 37 38    [39] 40 41 42 43
// 44 45 46 [47] 48  49