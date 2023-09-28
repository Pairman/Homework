#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct myclass
{
    int x1,y1,x2,y2;
    int num;
    int no;
};
bool cmp(myclass a, myclass b)
{
 if(a.num > b.num)
    return true;
 else
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    myclass Myclass[n];
    for(int i = 0; i < n; i++)
    {
        cin >> Myclass[i].x1 >> Myclass[i].y1 >> Myclass[i].x2 >> Myclass[i].y2;
        Myclass[i].num = i+1;
        Myclass[i].no = i+1;
    }
    int x, y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        int temp = 0;
        int cnt = 0;
        sort(Myclass, Myclass+n, cmp);
        for(int j = 0; j < n; j++)
        {
            if(x <= Myclass[j].x2 && x >= Myclass[j].x1 && y <= Myclass[j].y2 && y >= Myclass[j].y1)
            {
                cout << Myclass[j].no << endl;
                temp = Myclass[j].num;
                cnt = 1;
                break;
            }
        }
        if(cnt == 0)
        {
            cout << "IGNORED" << endl;
        }
        else if(temp != n)
        {
           for(int j = 0; j < n; j++)
            {
                if(Myclass[j].num > temp)
                {
                    Myclass[j].num -=1;
                }
                else if(Myclass[j].num == temp)
                {
                    Myclass[j].num = n;
                }
            }
        }
 
    }
    return 0;
}