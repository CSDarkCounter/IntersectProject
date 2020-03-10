# 北航软工个人项目作业：求几何对象交点

| 项目 | 内容 |
|  ----| ---- |
|这个作业属于哪个课程|[2020春季计算机学院软件工程(罗杰 任健)](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2020_LJ) |
|这个作业的要求在哪里|[个人项目作业](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2020_LJ/homework/10429)|
|我在这个课程的目标是|学习软件工程相关知识，提高自己团队项目的开发能力|
|教学班级|005|
|项目地址|[IntersectProject](https://github.com/CSDarkCounter/IntersectProject.git)|

## 使用方法：
命令行输入intersect.exe -i input.txt -o output.txt
其中，input.txt为输入文件，output.txt为输出文件

**输入格式：**
第 1 行：一个自然数 N >= 1，表示输入的几何对象的数目。
第 2 行至第 N + 1 行：每行描述一个几何对象。具体格式如下：
直线：L <x1> <y1> <x2> <y2>，表示通过点 (x1, y1) 和 (x2, y2) 的直线。输入保证给定两点不重合。
圆：C <x> <y> <r>，表示以点 (x, y) 为中心，半径为 r 的圆。输入保证半径 r > 0。
所有几何对象参数均为整数，范围为 (-100000, 100000)。

输出格式
共 1 行，输出平面中满足需求的点的数目。
