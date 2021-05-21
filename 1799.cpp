#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
time complexiy=O(2^(N^2))
*/

int solution(vector<vector<int>>& board, int row, int col, int n, vector<bool>& check_left_to_right, vector<bool>& check_right_to_left)
{
    if(row==n)return 0;
    int next_col=col+2;
    int next_row=row;
    if(next_col==n)
    {
        next_row=row+1;
        next_col=(n&1)?0:1;
    }
    else if(next_col>n)
    {
        next_row=row+1;
        next_col=(n&1)?1:0;
    }
    if(board[row][col]==0)
    {
        return solution(board,next_row, next_col,n,check_left_to_right, check_right_to_left);
    }
    int ret=0;
    if(check_left_to_right[col-row+n]==false&&check_right_to_left[col+row]==false)
    {
        check_left_to_right[col-row+n]=true;
        check_right_to_left[col+row]=true;
        ret=max(ret,solution(board,next_row,next_col,n,check_left_to_right,check_right_to_left)+1);
        check_left_to_right[col-row+n]=false;
        check_right_to_left[col+row]=false;
    }
    ret=max(ret, solution(board, next_row,next_col,n,check_left_to_right,check_right_to_left));
    return ret;
}
 
int main()
{
    vector<vector<int>> borad;
    vector<bool> check_left_to_right,check_right_to_left;
    int n,ans;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    borad.resize(n,vector<int>(n));
    check_left_to_right.resize(2*n+2,false);
    check_right_to_left.resize(2*n+2,false);
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>borad[i][j];
        }
    }
    ans=solution(borad,0,0,n,check_left_to_right,check_right_to_left);
    for(int i=0;i<check_right_to_left.size();++i)
    {
        check_left_to_right[i]=check_right_to_left[i]=false;
    }
    ans+=solution(borad,0,1,n,check_left_to_right,check_right_to_left);
    cout<<ans;
    return 0;
}
