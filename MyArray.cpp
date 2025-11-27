#include "MyArray.h"
#include <iostream>
using namespace std;

MyArray::MyArray() : p(nullptr), N(0) {}

MyArray::MyArray(int n, int initVal) {
	if (n <= 0) {
		p = nullptr;
		N = 0;
		return;
	}
	p = new int[n];
	N = n;
	for (int i = 0; i < N; i++) {
		p[i] = initVal;
	}
}

MyArray::MyArray(const MyArray& other) {
	N = other.N;
	if (N == 0) {
		p = nullptr;
		return;
	}
	p = new int[N];
	for (int i = 0; i < N; i++) {
		p[i] = other.p[i];
	}
}

MyArray::~MyArray() {
	if (p != nullptr) {
		delete[] p;
		p = nullptr;
		N = 0;
	}
}

int MyArray::getElement(int index) const {
	if (index < 0 || index >= N) {
		cout << "警告：索引" << index << "越界！" << endl;
		return 0;
	}
	return p[index];
}

MyArray MyArray::merge(const MyArray& other) const {
	int newLen = N + other.N;
	MyArray newArr(newLen);

	for (int i = 0; i < N; i++) {
		newArr.p[i] = p[i];
	}
	for (int i = 0; i < other.N; i++) {
		newArr.p[N + i] = other.p[i];
	}
	return newArr;
}

MyArray MyArray::add(const MyArray& other) const {
	int newLen = (N < other.N) ? N : other.N;
	MyArray newArr(newLen);

	for (int i = 0; i < newLen; i++) {
		newArr.p[i] = p[i] + other.p[i];
	}
	return newArr;
}

MyArray MyArray::subtract(const MyArray& other) const {
	int newLen = (N < other.N) ? N : other.N;
	MyArray newArr(newLen);

	for (int i = 0; i < newLen; i++) {
		newArr.p[i] = p[i] - other.p[i];
	}
	return newArr;
}

MyArray MyArray::multiply(const MyArray& other) const {
	int newLen = (N < other.N) ? N : other.N;
	MyArray newArr(newLen);

	for (int i = 0; i < newLen; i++) {
		newArr.p[i] = p[i] * other.p[i];
	}
	return newArr;
}

MyArray MyArray::divide(const MyArray& other) const {
	int newLen = (N < other.N) ? N : other.N;
	MyArray newArr(newLen);

	for (int i = 0; i < newLen; i++) {
		if (other.p[i] == 0) {
			cout << "警告：第" << i << "个元素除数为0，结果设为0" << endl;
			newArr.p[i] = 0;
		}
		else {
			newArr.p[i] = p[i] / other.p[i];
		}
	}
	return newArr;
}