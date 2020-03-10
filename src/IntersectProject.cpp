// IntersectProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>  
#include <math.h>

using namespace std;

#define eps 1e-12

class Point {
public:
	double x, y;
	Point(double a, double b) {
		x = a;
		y = b;
	}
	bool operator<(const Point& p) const {
		if (fabs(x - p.x) < eps && fabs(y - p.y) < eps)
			return false;
		if (fabs(x - p.x) >= eps)
			return x < p.x;
		else
			return y < p.y;
	}

};

class Line {
public:
	// use Ax+By+C=0 to describe a line
	double A, B, C;
	Line(double x1, double y1, double x2, double y2);
	Line(double a, double b, double c);
	Point calintpoint1(Line line1);
};

class Circle {
public:
	double x0, y0, r0;//describe a circle
	Circle(double x0, double y0, double r0);
};

Circle::Circle(double x, double y, double r) {
	x0 = x;
	y0 = y;
	r0 = r;
}

vector<Line> linevec;
vector<Circle> circlevec;
set<Point> pointset;


Line::Line(double x1, double y1, double x2, double y2) {
	A = y2 - y1;
	B = x1 - x2;
	C = x2 * y1 - x1 * y2;
}

Line::Line(double a, double b, double c) {
	A = a;
	B = b;
	C = c;
}

double getdistance(Line line, Circle circle) {//圆心到直线距离
	double tmp1 = line.A * circle.x0 + line.B * circle.y0 + line.C;
	double tmp2 = pow(line.A, 2) + pow(line.B, 2);
	return fabs(tmp1 / sqrt(tmp2));
}

Point Line::calintpoint1(Line line1) {//line and line
	double tmp1 = B * line1.C - line1.B * C;
	double tmp2 = A * line1.B - line1.A * B;
	double tmp3 = line1.A * C - A * line1.C;
	double x = tmp1 / tmp2;
	double y = tmp3 / tmp2;//直线交点坐标公式
	Point point(x, y);
	return point;
}

void calintpoint2(Line line, Circle circle, double dis) {//line and circle
	Line line2(line.B, -line.A, line.A * circle.y0 - line.B * circle.x0);//过圆心的垂线
	Point point = line.calintpoint1(line2);//垂足
	pair<double, double> e;//定义直线的单位向量
	double gougu = sqrt(circle.r0 * circle.r0 - dis * dis);
	e.first = (double)line.B / sqrt(line.A * line.A + line.B * line.B);
	e.second = -(double)line.A / sqrt(line.A * line.A + line.B * line.B);//求直线的单位向量
	Point point1(point.x + e.first * gougu, point.y + e.second * gougu);
	pointset.insert(point1);

	if (dis == circle.r0)//若相切则只有一个交点
		return;

	Point point2(point.x - e.first * gougu, point.y - e.second * gougu);
	pointset.insert(point2);
}

void intersectforline(Line line1) {
	//line and line
	vector<Line>::iterator iter1;
	for (iter1 = linevec.begin(); iter1 != linevec.end(); ++iter1)
	{
		if (line1.A * (*iter1).B - (*iter1).A * line1.B == 0) { //parallel
			;
		}
		else {
			Point point = line1.calintpoint1(*iter1);
			pointset.insert(point);
		}
	}
	//line and circle
	vector<Circle>::iterator iter2;
	for (iter2 = circlevec.begin(); iter2 != circlevec.end(); ++iter2)
	{
		double dis = getdistance(line1, *iter2);
		if (dis > (*iter2).r0) {//直线与圆相离
			continue;
		}
		else {
			calintpoint2(line1, (*iter2), dis);
		}
	}
	linevec.push_back(line1);
}

void intersectforcircle(Circle circle1) {
	//line and circle
	vector<Line>::iterator iter1;
	for (iter1 = linevec.begin(); iter1 != linevec.end(); ++iter1)
	{
		double dis = getdistance(*iter1, circle1);
		if (dis > circle1.r0) {//直线与圆相离
			continue;
		}
		else {
			calintpoint2(*iter1, circle1, dis);
		}
	}
	//circle and circle
	vector<Circle>::iterator iter2;
	for (iter2 = circlevec.begin(); iter2 != circlevec.end(); ++iter2)
	{
		double d = sqrt((circle1.x0 - (*iter2).x0) * (circle1.x0 - (*iter2).x0) + (circle1.y0 - (*iter2).y0) * (circle1.y0 - (*iter2).y0));
		if (d == 0 || d < fabs(circle1.r0 - (*iter2).r0) || d >(circle1.r0 + (*iter2).r0)) {
			continue;
		}//判断两圆是否有交点

		//求出过两圆交点的直线
		Line line1(2 * ((*iter2).x0 - circle1.x0), 2 * ((*iter2).y0 - circle1.y0), circle1.x0 * circle1.x0 + circle1.y0 * circle1.y0 - 
			(*iter2).x0 * (*iter2).x0 - (*iter2).y0 * (*iter2).y0 + (*iter2).r0 * (*iter2).r0 - circle1.r0 * circle1.r0);
		double dis = getdistance(line1, circle1);
		calintpoint2(line1, circle1, dis);//求出两圆交点
	}
	circlevec.push_back(circle1);
}


int main(int argc, char ** argv)
{
	ifstream infile;
	ofstream outfile;
	int num = 0;
	while (num < argc) {
		if ((string)argv[num] == "-i") {
			infile.open(argv[num + 1]);	//accept input
		}
		else if ((string)argv[num] == "-o") {
			outfile.open(argv[num + 1]);
		}
		num++;
	}
	int n = 0;
	infile >> n;
	double x1, y1, x2, y2;
	double x0, y0, r0;
	string op;
	int i = 0;
	for (i = 0; i < n; i++) {
		infile >> op;
		if (op == "L") {
			infile >> x1 >> y1 >> x2 >> y2;
			Line line1(x1, y1, x2, y2);
			intersectforline(line1);
		}
		if (op == "C") {
			infile >> x0 >> y0 >> r0;
			Circle circle1(x0, y0, r0);
			intersectforcircle(circle1);
		}
	}
	int res = pointset.size();
	//cout << res << endl;
	outfile << res << endl;
	infile.close();
	outfile.close();
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

