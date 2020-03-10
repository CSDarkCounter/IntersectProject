#include "pch.h"
#include "CppUnitTest.h"
#include "../IntersectProject/IntersectProject.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a = 1.0;
			double b = -1.0;
			double c = 0.0;
			Line line1(a, b, c);
			Line line2(a, a, c);
			pair<double, double> point;
			point.first = c;
			point.second = c;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}

		TEST_METHOD(TestMethod2)
		{
			Line line1(1, 4, -1, 7);
			Line line2(2, 4, -1, 7);
			pair<double, double> point;
			point.first = -1;
			point.second = 7;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}

		TEST_METHOD(TestMethod3)
		{
			Line line1(-2, 2, 3, 7);
			Line line2(5, 8, 10, 9);
			pair<double, double> point;
			point.first = (double)(15) / 4;
			point.second = (double)(31) / 4;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}

		TEST_METHOD(TestMethod4)
		{
			Line line1(0, 0, 0, 2);
			Line line2(-2, 1, 3, 1);
			pair<double, double> point;
			point.first = 0;
			point.second = 1;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}

		TEST_METHOD(TestMethod5)
		{
			Line line1(-350, 100, -250, 200);
			Line line2(-200, 100, -140, 200);
			pair<double, double> point;
			point.first = 25;
			point.second = 475;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}

		TEST_METHOD(TestMethod6)
		{
			Line line1(-99999, 99999, -100, 100);
			Line line2(22, 22, 99999, 99999);
			pair<double, double> point;
			point.first = 0;
			point.second = 0;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}

		TEST_METHOD(TestMethod7)
		{
			Line line1(3, 4, -5, 8);
			Line line2(7, 2, -3, 9);
			pair<double, double> point;
			point.first = 7;
			point.second = 2;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}

		TEST_METHOD(TestMethod8)
		{
			Line line1(0, 0, 1, 1);
			Line line2(0, 1, 1, 3);
			pair<double, double> point;
			point.first = -1;
			point.second = -1;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}

		TEST_METHOD(TestMethod9)
		{
			Line line1(0, 0, -1, -1);
			Line line2(0, 2, 1, 5);
			pair<double, double> point;
			point.first = -1;
			point.second = -1;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}

		TEST_METHOD(TestMethod10)
		{
			Line line1(0, 1, 1, 5);
			Line line2(0, 3, 1, 10);
			pair<double, double> point;
			point.first = -(double)(2)/3;
			point.second = -(double)(5)/3;
			Assert::AreEqual(line1.calintpoint1(line2).first, point.first);
			Assert::AreEqual(line1.calintpoint1(line2).second, point.second);
		}


	};
}
