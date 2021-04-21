#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

/*

풀이

모든 Xi opi Xi+1 에 대하여 우선순위에 따라 큐에 삽입
i번째 수의 왼쪽 수와 오른 쪽 수의 위치를 저장하는 배열 m
i번째 수의 왼쪽 연산자와 오른쪽 연산자의 위치를 저장하는 배열 k

우선순위에서 팝
만약 사용한 연산자이거나 큐에 있던 연산 결과가 현재와 다르다면 스킵

아니라면 xi와 xi+1에 결과를 저장

xi의 왼쪽 수와 결과를 xi의 왼쪽 연산자를 통한 결과를 큐에 저장

결과와 xi+1의 오른 쪽 수를 xi+1의 오른쪽 연산자를 통한 결과를 큐에 저장

m[i] 의 오른 쪽은 xi+1의 오른 쪽으로 갱신
m[xi+1의 오른 쪽] 은 i로 갱신
k[i]의 오른 쪽 연산자 위치는 k[xi+1의 오른 쪽]의 왼쪽 연산자 위치로 갱신
*/
typedef struct matching
{
    int left, right;
};
typedef struct _data
{
    int left;
    int right;
    int index;
    char oper;
    char rank;
    long long val;
}pdata;

using ll = long long;

struct cmp
{
    bool operator()(pdata& d1, pdata& d2)
    {
        if (d1.val != d2.val)
        {
            return d1.val < d2.val;
        }
        else if (d1.rank != d2.rank)
        {
            return d1.rank < d2.rank;
        }
        else
        {
            return d1.index > d2.index;
        }
    }
};

ll cal(const ll& v1, const ll& v2, const char& oper)
{
    if (oper == '/')
    {
        return v1 / v2;
    }
    if (oper == '+')
    {
        return v1 + v2;
    }
    if (oper == '-')
    {
        return v1 - v2;
    }
    if (oper == '*')
    {
        return v1 * v2;
    }
}

/*
match[i] -> 왼 쪽 수와 오른 쪽 수의 위치
operation[i] -> i번째 operation을 수행할 수의 위치

pop;

*/
int main()
{
    vector<matching> match, oper_match;
    vector<char> oper;
    vector<bool> used;
    vector<ll> num;
    map<char, char> ranking;
    int n, start, end;
    ll ans, value;
    string str;
    priority_queue<pdata, vector<pdata>, cmp> pq;

    ranking['*'] = ranking['/'] = 1;
    ranking['+'] = ranking['-'] = 1;
    start = 0;
    cin >> str;
    value = 0;
    for (int i = 0; i<str.size(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9') 
        {
            value *= 10;
            value += static_cast<ll>(str[i] - '0');
        }
        else
        {
            oper.push_back(str[i]);
            num.push_back(value);
            value = 0LL;
        }
    }
    num.push_back(value);
    for (int i = 0; i < num.size(); ++i)
    {
        match.push_back({ i - 1, i + 1 });
        //i번쨰 수의 왼쪽 수 오른쪽 수
        oper_match.push_back({ i - 1,i });
        //i번째 수의 왼쪽 연산자 오른쪽 연산자
    }
    for (int i = 0; i < oper.size(); ++i)
    {
        used.push_back(false);
        pq.push({ i,i + 1,i,oper[i],ranking[oper[i]],cal(num[i],num[i + 1], oper[i]) });
    }
    ans = num[0];
    while (pq.empty() == false)
    {
        auto top = pq.top();
        pq.pop();
        if (used[top.index])
        {
            //사용한 연산자면 스킵
            continue;
        }
        if (match[top.left].right!=top.right||top.left!=match[top.right].left||cal(num[top.left], num[top.right], top.oper)!=top.val)
        {
            //현재 연산결과와 큐에 있는 내용이 다름
            continue;
        }
        used[top.index] = true;
        int li = top.left;
        int ri = top.right;
        ll val = top.val;
        //연산 결과를 왼 쪽에 저장
        num[li] = val;
        ans = val;
        //저장된 결과에 왼쪽 항에 수가 존재한다면
        if (match[li].left != -1)
        {
            //왼쪽 항의 연산 결과 저장
            int lli = match[li].left;
            int oper_index = oper_match[lli].right;
            char operat = oper[oper_index];
            pq.push({ lli, li, oper_index,operat,ranking[operat],cal(num[lli], num[li], operat) });
        }
        //오른 쪽
        if (match[ri].right < num.size() && match[ri].right >= 0)
        {
            int rri = match[ri].right;
            int oper_index = oper_match[rri].left;
            char operat = oper[oper_index];
            pq.push({ li, rri, oper_index,operat,ranking[operat],cal(num[li], num[rri], operat) });
            match[li].right = rri;
            match[rri].left = li;
            oper_match[li].right = oper_match[ri].right;
        }
    }
    cout << ans;
    return 0;
}
