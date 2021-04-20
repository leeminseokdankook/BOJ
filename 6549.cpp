#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/*
백준 6549

stack 사용

stack의 top은 현재 가장 높은 사각형의 index와 높이가 저장

1. 0~(n-1) 까지 순회

2-1. stack이 비었거나 top 보다 높은 사각형을 만나면 index와 height 푸쉬

2-2. 같거나 낮은 사각형이면 top의 높이가 현재 높이 보다 작아질때 까지 
    pop 을 하고 넓이 구함 -> 끝남ㄴ push


*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long ans, n;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        ans = -1LL;
        stack<pair<long long, long long>> st;
        for(long long int i=0;i<n;i++)
        {
            int h;
            cin >> h;
            if (st.empty())
            {
                st.push({ i,h });
            }
            else
            {
                if (st.top().second < h)
                {
                    st.push({ i,h });
                }
                else {
                    int index;
                    while (st.empty() == false && st.top().second >= h)
                    {
                        pair<long long int, long long int> t = st.top();
                        ans = max(ans, t.second * (i - t.first));
                        index = t.first;
                        st.pop();
                    }
                    st.push({ index, h });
                }
            }
        }
        while (st.empty() == false)
        {
            ans = max(ans, (n - st.top().first) * st.top().second);
            st.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}
