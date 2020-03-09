// IntersectProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<set>    
#define equals(a, b) (fabs((a) - (b)) < 1e-7)
using namespace std;


class Line {
public:
	// use Ax+By+C=0 to describe a line
	double A, B, C;
	Line(double x1, double y1, double x2, double y2);
	pair<double, double> calintpoint(Line line1);

	
};

vector<Line> linevec;
set<pair<double, double>> pointset;


Line::Line(double x1, double y1, double x2, double y2) {
	A = y2 - y1;
	B = x1 - x2;
	C = x2 * y1 - x1 * y2;
}

pair<double, double> Line::calintpoint(Line line1) {
	double tmp1 = B * line1.C - line1.B * C;
	double tmp2 = A * line1.B - line1.A * B;
	double tmp3 = line1.A * C - A * line1.C;
	double x = tmp1 / tmp2;
	double y = tmp3 / tmp2;
	pair<double, double> point;
	point.first = x;
	point.second = y;
	return point;
}

void intersect(Line line1) {
	vector<Line>::iterator iter;
	for (iter = linevec.begin(); iter != linevec.end(); ++iter)
	{
		if (line1.A * (*iter).B - (*iter).A * line1.B == 0) { //parallel
			;
		}
		else {
			pair<double, double> point = line1.calintpoint(*iter);
			pointset.insert(point);
		}
	}
	linevec.push_back(line1);
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
	string op;

	int i = 0;
	for (i = 0; i < n; i++) {
		infile >> op >> x1 >> y1 >> x2 >> y2;
		if (op == "L") {
			Line line1(x1, y1, x2, y2);
			intersect(line1);
		}
	}
	int res = pointset.size();
	cout << res << endl;
	outfile << res << endl;
	infile.close();
	outfile.close();
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

