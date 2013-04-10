#include<cstring>
#include<iostream>
#define LEN 10
using namespace std;
char elem[LEN] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
char result[LEN];
bool filled[LEN];
void permutation(int k, int n) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			cout << result[i] << " ";

		}
		cout << endl;
	} else {
		for (int i = 0; i < n; i++) {
			if (!filled[i]) {
				filled[i] = true;
				result[k] = elem[i];
				permutation(k + 1, n);
				filled[i] = false;
			}
		}
	}
}
int main() {
	memset(result, 0, sizeof(result));
	memset(filled, false, sizeof(filled));
	permutation(0, LEN);
	return 0;
}