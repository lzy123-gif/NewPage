#include "MyArray.h"
#include <iostream>
using namespace std;

void printArray(const MyArray& arr, const string& arrName) {
	cout << arrName << "（长度：" << arr.getLength() << "）：";
	for (int i = 0; i < arr.getLength(); i++) {
		cout << arr.getElement(i) << " ";
	}
	cout << endl;
}

int main() {
	MyArray arr1;
	MyArray arr2(3, 5);
	MyArray arr3(4, 2);
	cout << "=== 测试1：构造函数 ===" << endl;
	printArray(arr1, "arr1（空数组）");
	printArray(arr2, "arr2");
	printArray(arr3, "arr3");
	cout << endl;

	MyArray arr4 = arr2;
	cout << "=== 测试2：拷贝构造 ===" << endl;
	printArray(arr4, "arr4（拷贝arr2）");
	cout << endl;

	MyArray arrMerge = arr2.merge(arr3);
	cout << "=== 测试3：数组合并 ===" << endl;
	printArray(arrMerge, "arrMerge（arr2+arr3）");
	cout << endl;

	MyArray arrAdd = arr2.add(arr3);
	MyArray arrSub = arr2.subtract(arr3);
	MyArray arrMul = arr2.multiply(arr3);
	MyArray arrDiv = arr2.divide(arr3);
	cout << "=== 测试4：四则运算 ===" << endl;
	printArray(arrAdd, "arrAdd（arr2+arr3）");
	printArray(arrSub, "arrSub（arr2-arr3）");
	printArray(arrMul, "arrMul（arr2*arr3）");
	printArray(arrDiv, "arrDiv（arr2/arr3）");
	cout << endl;

	return 0;
}