#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int initseg(int s, int e, int index, vector<int>& seg);
int query(int p, int s, int e, int index,vector<int>& seg);

int main()
{
    vector<int> height,seg,order,ans;
    int n;
    scanf("%d", &n);
    height.resize(n);
    order.resize(n);
    ans.resize(n);
    seg.resize(4*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &height[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d", &order[i]);
    }
    sort(height.begin(),height.end());
    initseg(0,n-1,1,seg);
    for(int i=n-1;i>=0;i--)
    {
        ans[i]=query(order[i]+1, 0,n-1,1,seg);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n", height[ans[i]]);
    }
    return 0;
}

int initseg(int s, int e, int index, vector<int>& seg)
{
	if(s==e)
	{
		return seg[index]=1;
	}
	int mid=(s+e)/2;
	int left_seg=initseg(s,mid, index<<1, seg);
	int right_seg=initseg(mid+1, e, (index<<1)+1, seg);
	seg[index]=left_seg+right_seg;
	return seg[index];
}

int query(int p, int s, int e, int index,vector<int>& seg)
{
	seg[index]--;
	if(s==e)
	{
		return s;
	}
	int left_seg=seg[index<<1];
	int mid=(s+e)/2;
	if(p<=left_seg)return query(p,s,mid,index<<1, seg);
	else return query(p-left_seg,mid+1, e, (index<<1)+1, seg);
}
