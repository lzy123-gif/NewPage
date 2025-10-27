#include <iostream>
#include <string>  // 添加这个头文件
using namespace std;

int countVowels(const char* p) {
	int count = 0;
	while (*p) {
		char ch = tolower(*p);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			count++;
		}
		p++;
	}
	return count;
}

int main() {
	string str;
	getline(cin, str);  // 现在 getline 有定义了
	cout << "Number of vowels: " << countVowels(str.c_str()) << endl;
	return 0;
}