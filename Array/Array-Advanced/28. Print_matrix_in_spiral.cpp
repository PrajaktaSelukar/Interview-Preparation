#include<bits/stdc++.h>
using namespace std;

void printSpiralMatrix(int **mat, int R, int C)
{
    int top=0, down=R-1, left=0, right=C-1;
    //direction of the flow
    //0 (right-->)  1(down)  2(left<--)  3(up)
    int dir=0;

    while(top <= down && left<=right)
    {
        if(dir==0)
        {
            for(int move=left; move<=right; move++)
                cout<<mat[top][move]<<" ";
            top++;
        }
        else if(dir==1)
        {
            for(int move=top; move<=down; move++)
                cout<<mat[move][right]<<" ";
            right--;
        }
        else if(dir==2)
        {
            for(int move=right; move>=left; move--)
                cout<<mat[down][move]<<" ";
            down--;
        }
        else if(dir==3)
        {
            for(int move=down; move>=top; move--)
                cout<<mat[move][left]<<" ";
            left++;;
        }
        dir = (dir+1)%4;
    }
}

int main()
{
    int R, C;
    cin>>R>>C;

    //vector<vector<int> > mat;
    int **mat = new int*[R];

    for(int i=0; i<R; i++)
        mat[i]= new int[C];

    //int tmp;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            /*cin>>tmp;
            mat[i].push_back(tmp);*/
            cin>>mat[i][j];
        }
    }

    printSpiralMatrix(mat, R, C);
}
