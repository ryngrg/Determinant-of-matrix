#include <iostream>
#include <conio.h>
using namespace std;

int determinant(int [10][10], int);

int main()

{
    int i,j;
    int a[10][10], n;
    cout << "enter the order (<=10) : ";
    cin >> n;
    cout << endl<<"enter the matrix :"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[j][i];
        }
    }
    cout <<endl<<"its determinant is : "<< determinant(a,n)<<endl;
    getch();
    return 0;
}

int determinant(int a[10][10],int n)
{
    int val=0, b[10][10],f=0,g=0,x,y,i;
    if(n>1)
    {
        for(i=0;i<n;i++)
        {
            f=0;g=0;
            for(x=0;x<n;x++)
            {
                for(y=1;y<n;y++)
                {
                    if(x!=i)
                    {
                        b[f][g]=a[x][y];
                        if(f==(n-2))
                        {
                            f=0;g++;
                        }
                        else
                        {
                            f++;
                        }
                    }
                }
            }
            if(i%2==0)
            {
                val = val + (a[i][0]*(determinant(b,n-1)));
            }
            else
            {
                val = val - (a[i][0]*(determinant(b,n-1)));
            }
        }
        return val;
    }
    else
    {
        return a[0][0];
    }
}
