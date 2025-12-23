#include <iostream>
using namespace std;

class base {
public:
	int a;
protected:
	int b;
private:
	int c;
	static int count;
public:
	base(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {
		count++;
		cout << "base构造函数调用，当前对象个数：" << count << endl;
	}
	~base() {
		count--;
		cout << "base析构函数调用，当前对象个数：" << count << endl;
	}
	void print() {
		cout << "base: a=" << a << ", b=" << b << ", c=" << c << endl;
	}
	static int Manage() {
		return count;
	}
};

int base::count = 0;

class derived1 : public base {
public:
	derived1(int a = 0, int b = 0, int c = 0) : base(a, b, c) {
		cout << "derived1（公有继承）构造函数调用" << endl;
	}
	~derived1() {
		cout << "derived1（公有继承）析构函数调用" << endl;
	}
	void printDerived() {
		cout << "derived1: a=" << a << ", b=" << b << "（c为基类私有，子类不可直接访问）" << endl;
	}
};

class derived2 : private base {
public:
	derived2(int a = 0, int b = 0, int c = 0) : base(a, b, c) {
		cout << "derived2（私有继承）构造函数调用" << endl;
	}
	~derived2() {
		cout << "derived2（私有继承）析构函数调用" << endl;
	}
	void printDerived() {
		cout << "derived2: a=" << a << ", b=" << b << "（c为基类私有，子类不可直接访问）" << endl;
	}
};

class derived3 : protected base {
public:
	derived3(int a = 0, int b = 0, int c = 0) : base(a, b, c) {
		cout << "derived3（保护继承）构造函数调用" << endl;
	}
	~derived3() {
		cout << "derived3（保护继承）析构函数调用" << endl;
	}
	void printDerived() {
		cout << "derived3: a=" << a << ", b=" << b << "（c为基类私有，子类不可直接访问）" << endl;
	}
};

int main() {
	cout << "==================== 任务三：继承特性测试 ====================" << endl;
	cout << "\n1. 构造/析构顺序与对象计数测试：" << endl;
	derived1 d1(10, 20, 30);
	cout << "当前对象总数：" << base::Manage() << endl;
	derived2 d2(40, 50, 60);
	cout << "当前对象总数：" << base::Manage() << endl;
	derived3 d3(70, 80, 90);
	cout << "当前对象总数：" << base::Manage() << endl;

	cout << "\n2. 派生类内部访问基类成员测试：" << endl;
	d1.print();
	d1.printDerived();
	d2.printDerived();
	d3.printDerived();

	cout << "\n3. 类外访问基类成员测试：" << endl;
	cout << "derived1（公有继承）类外访问a：" << d1.a << endl;

	cout << "\n对象销毁过程（析构顺序与构造相反）：" << endl;
	return 0;
}