#include <iostream>
#include <conio.h>
using namespace std;
void floyds(int b[][4])
{
    int i, j, k;
    for (k = 0; k < 4; k++)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        cout<<"\nMinimum Cost With Respect to Node:"<<i<<endl;
        for (j = 0; j < 4; j++)
        {
            cout<<b[i][j]<<"\t";
        }

    }
}
int main()
{
    int b[4][4];
    cout<<"ENTER VALUES OF ADJACENCY MATRIX\n\n";
    for (int i = 0; i < 4; i++)
    {
        cout<<"enter values for "<<(i+1)<<" row"<<endl;
        for (int j = 0; j < 4; j++)
        {
            cin>>b[i][j];
        }
    }
    floyds(b);
    getch();
}
