#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pqdata{
    int left;        //현재 위치에서 가장 짧은 왼쪽 지점
    int right;       //현재 위치에서 가장 짧은 오른쪽 지점
    int len;         //현재 지점을 시작점으로 하여 가장 짧은 길이
};

struct cmp{
	bool operator()(struct pqdata& d1, struct pqdata& d2)
	{
    	return d1.len>d2.len;
	}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<struct pqdata> v;
    vector<int> length;
    priority_queue<struct pqdata, vector<struct pqdata>, cmp> pq;
    int n,k, ans=0;
    cin>>n>>k;
    v.resize(n+2);
    length.resize(n+2);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].len;
        v[i].left=i-1;
        v[i].right=i+1;
    }
    for(int i=1;i<n;i++)
    {
        struct pqdata node;
        node.left=i;
        node.right=i+1;
        node.len=v[i+1].len-v[i].len;
        length[i]=v[i+1].len-v[i].len;
        pq.push(node);
    }
    for(int i=0;i<k;)
    {
        struct pqdata top=pq.top();
        pq.pop();
        if(top.left<1||top.right>n||top.left!=v[top.right].left||top.right!=v[top.left].right)
        {
            continue;
        }
        //중복 제거 과정
        ans+=top.len;
        i++;
        int next_l=v[top.left].left;
        int next_r=v[top.right].right;
        length[next_l]=length[next_l]+length[top.right]-top.len;
        v[next_l].right=next_r;
        v[next_r].left=next_l;
        top.left=next_l;
        top.right=next_r;
        top.len=length[next_l];
        pq.push(top);
    }
    cout<<ans;
    return 0;
}
