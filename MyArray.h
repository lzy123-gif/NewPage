#ifndef MYARRAY_H
#define MYARRAY_H

class MyArray {
private:
	int* p;
	int N;

public:
	MyArray();
	MyArray(int n, int initVal = 0);
	MyArray(const MyArray& other);

	~MyArray();

	MyArray merge(const MyArray& other) const;

	MyArray add(const MyArray& other) const;
	MyArray subtract(const MyArray& other) const;
	MyArray multiply(const MyArray& other) const;
	MyArray divide(const MyArray& other) const;

	int getLength() const { return N; }
	int getElement(int index) const;
};

#endif // MYARRAY_H