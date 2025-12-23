#include <iostream>
#include <cmath>
using namespace std;

class Point2D {
private:
	int x;
	int y;
public:
	Point2D() : x(0), y(0) {}
	Point2D(int x, int y) : x(x), y(y) {}
	~Point2D() {}
	Point2D& move(int dx, int dy) {
		this->x += dx;
		this->y += dy;
		return *this;
	}
	void show() const {
		cout << "二维点坐标：(" << x << ", " << y << ")" << endl;
	}
	int getX() const { return x; }
	int getY() const { return y; }
	friend double distance(const Point2D& p1, const Point2D& p2);
};

double distance(const Point2D& p1, const Point2D& p2) {
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}

class Point3D : public Point2D {
private:
	int z;
public:
	Point3D() : Point2D(), z(0) {}
	Point3D(int x, int y, int z) : Point2D(x, y), z(z) {}
	~Point3D() {}
	Point3D& move(int dx, int dy, int dz) {
		Point2D::move(dx, dy);
		this->z += dz;
		return *this;
	}
	void show() const {
		cout << "三维点坐标：(" << getX() << ", " << getY() << ", " << z << ")" << endl;
	}
	friend double distance(const Point3D& p1, const Point3D& p2);
};

double distance(const Point3D& p1, const Point3D& p2) {
	int dx = p1.getX() - p2.getX();
	int dy = p1.getY() - p2.getY();
	int dz = p1.z - p2.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

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
	cout << "==================== 任务二：点类功能测试 ====================" << endl;
	Point2D p2d1(1, 2), p2d2(4, 6);
	cout << "初始二维点：" << endl;
	p2d1.show();
	p2d2.show();
	cout << "p2d1与p2d2的欧式距离：" << distance(p2d1, p2d2) << endl;

	p2d1.move(2, 3);
	cout << "p2d1移动后：" << endl;
	p2d1.show();
	cout << "移动后p2d1与p2d2的欧式距离：" << distance(p2d1, p2d2) << endl;

	Point3D p3d1(1, 2, 3), p3d2(4, 6, 8);
	cout << "\n初始三维点：" << endl;
	p3d1.show();
	p3d2.show();
	cout << "p3d1与p3d2的欧式距离：" << distance(p3d1, p3d2) << endl;

	p3d1.move(2, 3, 4);
	cout << "p3d1移动后：" << endl;
	p3d1.show();
	cout << "移动后p3d1与p3d2的欧式距离：" << distance(p3d1, p3d2) << endl;

	cout << "\n\n==================== 任务三：继承特性测试 ====================" << endl;
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