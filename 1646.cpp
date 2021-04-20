#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

void fun(ll start, ll end, int n, vector<pair<ll, ll>>& fibo_tree)
{
	if(start==0LL||end==0LL)
	{
		return;
	}
	if(start==end)
	{
		//출발지와 도착지가 같다면 위로 올라가야함
		return;
	}
	else if(start==1)
	{
		//root에서 시작
		if(end<=(fibo_tree[n].first+1))
		{
			//end가 left_sub tree에 존재
			cout<<"L";
			fun(1, end-1,n-2, fibo_tree);
		}
		else
		{
			//end가 right subtree에 존재
			cout<<"R";
			fun(1, end-(fibo_tree[n].first+1), n-1, fibo_tree);
		}
	}
	else if(end==1)
	{
		//root가 종점
		if(start<=(fibo_tree[n].first+1))
		{
			//start가 left_sub tree에 존재
			fun(start-1, 1, n-2, fibo_tree);
		}
		else
		{
			//start가 right subtree에 존재
			fun(start-(fibo_tree[n].first+1), 1, n-1, fibo_tree);
		}
		cout<<"U";
	}
	else
	{
		//start가 left_subtree인 경우
		if(start<=(fibo_tree[n].first+1))
		{
			//end도 left_subtree인 경우
			if(end<=(fibo_tree[n].first+1))
			{
				fun(start-1, end-1, n-2, fibo_tree);
			}
			else
			{
				//end가 right sub_tree
				fun(start, 1, n,fibo_tree);
				fun(1,end,n,fibo_tree);
			}
		}
		else
		{
			//end가 right_subtree인 경우
			if(end>(fibo_tree[n].first+1))
			{
				fun(start-(fibo_tree[n].first+1), end-(fibo_tree[n].first+1), n-1, fibo_tree);
			}
			else
			{
				//end가 left_sub_tree
				fun(start, 1, n,fibo_tree);
				fun(1,end,n,fibo_tree);
			}
		}
	}
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cout.tie(0);
	vector<pair<ll,ll>> fibo_tree;
	int n;
	ll s,e;
	cin>>n>>s>>e;
	fibo_tree.resize(4);
	fibo_tree[1]=fibo_tree[0]={0,0};
	fibo_tree[2]={1,1};
	fibo_tree[3]={1LL,3LL};
	for(int i=4;i<=n;i++)
	{
		fibo_tree.push_back({fibo_tree[i-2].first+fibo_tree[i-2].second+1, fibo_tree[i-1].first+fibo_tree[i-1].second+1});
	}
	fun(s,e,n,fibo_tree);
	return 0;
}
