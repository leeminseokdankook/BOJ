#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void add_vector(vector<vector<int>>& dest, vector<vector<int>>& src, int dest_x, int dest_y)
{
    int src_y=src.size();
    int src_x=src[0].size();
    for(int i=0;i<src_y;i++)
    {
        for(int j=0;j<src_x;j++)
        {
            dest[dest_y+i][dest_x+j]+=src[i][j];
        }
    }
}
vector<vector<int>> make_odd_table(int n)
{
    vector<vector<int>> table;
    table.resize(n,vector<int>(n,0));
    int x=n>>1;
        int y=0;
        int total_num=n*n;
        for(int i=1;i<=total_num;i++)
        {
            table[y][x]=i;
            int next_x=(x+1)%n;
            int next_y=(y-1)<0?n-1:y-1;
            if(table[next_y][next_x]!=0)
            {
                next_x=x;
                next_y=(y+1)%n;
            }
            x=next_x;
            y=next_y;
        }
   return table;
}
int main()
{
    vector<vector<int>> table;
    int n;
    cin>>n;
    if(n&1==1)
    {
        //홀수 마방진
        table=make_odd_table(n);
    }
    else
    {
        table.resize(n,vector<int>(n,0));
        //짝수 마방진
        //1. 4의 배수
        if(n%4==0)
        {
            int val=1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    table[i][j]=val;
                    val++;
                }
            }
            //1:2:1 적용
            //위 아래 부터
            int start_x=n/4;
            int end_x=start_x*3;
            int start_y=0;
            int end_y=n/4;
            for(int y=start_y;y<end_y;y++)
            {
                for(int x=start_x;x<end_x;x++)
                {
                    swap(table[y][x], table[n-y-1][n-x-1]);
                }
            }
            //좌 우 전환
            start_x=0;
            end_x=n/4;
            start_y=n/4;
            end_y=start_y*3;
            for(int y=start_y;y<end_y;y++)
            {
                for(int x=start_x;x<end_x;x++)
                {
                    swap(table[y][x], table[n-y-1][n-x-1]);
                }
            }
        }
        else { 
            //2. 일반 짝수
            vector<vector<int>> sub_table=make_odd_table(n>>1);
            vector<vector<int>> part[2][2];
            int add=(n*n)/4;
            int part_n=n>>1;
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    part[i][j].resize(n>>1, vector<int>(n>>1));
                }
            }
            //왼쪽 위 채움
            for(int y=0;y<part_n;y++)
            {
                int x=(y==(n/4)?1:0);
                int cnt=0;
                while(cnt<(part_n/2))
                {
                    part[0][0][y][x]=3;
                    x++;
                    cnt++;
                }
            }
            //왼쪽 아래
            for(int y=0;y<part_n;y++)
            {
                for(int x=0;x<part_n;x++)
                {
                    part[1][0][y][x]=3-part[0][0][y][x];
                }
            }
            //오른쪽 위
            for(int x=0;x<part_n;x++)
            {
                int val=(x<=(part_n-(n/4)))?2:1;
                for(int y=0;y<part_n;y++)
                {
                    part[0][1][y][x]=val;
                }
            }
            //오른쪽 아래
            for(int x=0;x<part_n;x++)
            {
                for(int y=0;y<part_n;y++)
                {
                    part[1][1][y][x]=3-part[0][1][y][x];
                }
            }
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    for(int row=0;row<part_n;row++)
                    {
                        for(int col=0;col<part_n;col++)
                        {
                            part[i][j][row][col]*=add;
                        }
                    }
                }
            }
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    add_vector(table,part[i][j],j*part_n, i*part_n);
                    add_vector(table,sub_table,j*part_n, i*part_n);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
