#include <iostream>
using namespace std;

int recu(int start, int end, char* str, int* pair_index);
int main() {
	int index_stack[51] = { 0, };
	int pair_index[51] = { -1 };
	int top = -1;
	char str[51];
	cin >> str;
	int i;
	for (i = 0; str[i]; i++) {
		if (str[i] == '(') {
			index_stack[++top] = i;
		}
		else if (str[i]==')'){
			pair_index[i] = index_stack[top--];
			pair_index[pair_index[i]] = i;
		}
	}
	cout << recu(0,i,str,pair_index);
	return 0;
}

int recu(int start, int end, char* str, int* pair_index) {
	int ret = 0;
	for (int index = start; index < end; index++) {
		if (str[index] == '(') {
			int K = str[index - 1] - '0';
			ret += K * recu(index + 1, pair_index[index],str, pair_index) - 1;
			index = pair_index[index];
		}
		else {
			ret++;
		}
	}
	return ret;
}
