#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef struct _index {
    int ptr, data_i;
    
}index;

void Match_Pair(string& instr, vector<int>& p);
int Excute(string& instr, vector<unsigned char>& v, string& data, vector<int>& p, index& index_info, int oper_index);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,m,c,i, oper_index,cnt;
    string instr, input;
    cin >> t;
    while (t--) {
        vector<int> p;
        vector<unsigned char> v;
        index index_info = { 0,0 };
        cin >> m >> c >> i;
        cin >> instr;
        cin >> input;
        p.resize(c, 0);
        v.resize(m, 0);
        Match_Pair(instr, p);
        for(oper_index=0, cnt=0;oper_index<c&&cnt<=50000000;cnt++){
            oper_index = Excute(instr,v, input, p, index_info, oper_index);
        }
        if (oper_index == c) {
            cout << "Terminates\n";
        }
        else {
            int ans = oper_index;
            while (oper_index!=c&&cnt--) {
                oper_index = Excute(instr, v, input, p, index_info, oper_index);
                ans = max(oper_index, ans);
            }
            if(oper_index==c)
            {
                cout << "Terminates\n";
            }
            else
            {
                cout << "Loops " << p[ans] << ' ' << ans << '\n';
            }
        }
    }
    // your code goes here
    return 0;
}

void Match_Pair(string& instr, vector<int>& p) {
    stack<int> st;
    int end = instr.size();
    for (int i = 0; i < end; i++) {
        if (instr[i] == '[') {
            st.push(i);
        }
        else if (instr[i] == ']') {
            p[st.top()] = i;
            p[i] = st.top();
            st.pop();
        }
    }
}

int Excute(string& instr, vector<unsigned char>& v, string& data, vector<int>& p, index& index_info, int oper_index) {
    switch (instr[oper_index]) {
        case '-':
            v[index_info.ptr]--;
            break;
        case '+':
            v[index_info.ptr]++;
            break;
        case '>':
            index_info.ptr = index_info.ptr + 1 == v.size() ? 0 : index_info.ptr + 1;
            break;
        case '<':
            index_info.ptr = index_info.ptr == 0 ? v.size() - 1 : index_info.ptr - 1;
            break;
        case '[':
            if (v[index_info.ptr] == 0) {
                return p[oper_index];
            }
            break;
        case ']':
            if (v[index_info.ptr] != 0) {
                return p[oper_index];
            }
            break;
        case ',':
            if (data.size() == index_info.data_i) {
                v[index_info.ptr] = 255;
            }
            else {
                v[index_info.ptr] = data[index_info.data_i++];
            }
            break;
        case '.':
            break;
    }
    return oper_index + 1;
}
