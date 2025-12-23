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
	return 0;
}