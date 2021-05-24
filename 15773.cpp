#include <iostream>
#include <queue>
using namespace std;
using ll=long long;
int main()
{
    priority_queue<pair<ll, ll>,vector<pair<ll, ll>>, greater<pair<ll ,ll>>> ballon_list;
    //데드라인이 빠르고 올라가는 폭이 적은 순으로 구성
    priority_queue<ll> boom_ballon;
    //지금까지 터트린 풍선 중, 용량이 높은 것을 우선으로 저장
    int n;
    ll height_now=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--)
    {
        ll l, d;
        cin>>l>>d;
        ballon_list.push({l+d,d});
    }
    boom_ballon.push(ballon_list.top().second);
    height_now=ballon_list.top().second;
    ballon_list.pop();
    while(ballon_list.empty()==false)
    {
        auto ballon=ballon_list.top();ballon_list.pop();
        ll altitude_limit=ballon.first-ballon.second;
        ll volumm=ballon.second;
        if(altitude_limit>=height_now)
        {
            //현재 고도에서 풍선을 터트릴 수 있다면 터트ㄹ
            height_now+=volumm;
            boom_ballon.push(volumm);
        }
        else
        {   //불가능
            //현재까지 터트린 풍선중, 가장 많이 올라가게 한 풍선을 고름
            ll max_up_ballon=boom_ballon.top();
            if(height_now-max_up_ballon<=altitude_limit&&max_up_ballon>volumm)
            {
                //지금 터트릴 풍선이 더 적게 올라간다면
                //이전에 터트린 풍선을 터트리지 말고 현재 풍선을 터트림
                boom_ballon.pop();
                height_now-=max_up_ballon;
                boom_ballon.push(volumm);
                height_now+=volumm;
            }
        }
    }
    cout<<boom_ballon.size();
    return 0;
}
