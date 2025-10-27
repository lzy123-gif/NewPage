#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string name;
	double chinese, math, english, average;

	for (int i = 0; i < n; i++) {
		cin >> name >> chinese >> math >> english;
		average = (chinese + math + english) / 3.0;

		cout << fixed << setprecision(2);
		cout << name << " " << chinese << " " << math << " " << english << " " << average;
		if (average >= 90) {
			cout << " Excellent";
		}
		cout << endl;
	}

	return 0;
}