#include<bits/stdc++.h>
using namespace std;

void copy(char *a, char *b,int m)
{
	char* p1 = a + m-1;
	char* p2 = b;
	while (*p1)
	{
		*p2++ = *p1++;
	}
	*p2 = '\0';
}
int main()
{
	char a[101]={0},b[101]={0}; gets(a);
	int m; cin>>m;
    if(m>strlen(a)){cout<<"error"; return 0;}
	copy(a, b, m);
	cout<<b;
	return 0;
}
