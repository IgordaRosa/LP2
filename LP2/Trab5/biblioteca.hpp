#ifndef shapes_hpp
#define shapes_hpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
#define PI 3.14159

using namespace std;

float ConverterL3d(string ponto, size_t p);
float ConverterL2d(string ponto, size_t p);

class Point2d{
public:
    float m_x,m_y;
    Point2d() : m_x(0),m_y(0){};
    Point2d(float x, float y) : m_x(x),m_y(y){};
};

class Point3d{
public:
    float m_x,m_y,m_z;
    Point3d() : m_x(0),m_y(0),m_z(0){};
    Point3d(float x, float y, float z) : m_x(x),m_y(y),m_z(z){};
};

class Circle{

private:
float m_ratio;


public:
Circle() : m_ratio(0) {};
Circle(float ratio) : m_ratio(ratio){};
float CalcArea() const { return PI*m_ratio*m_ratio;};

};

class Square{
private:
float m_edge;


public:
Square() : m_edge(0) {};
Square(float edge) : m_edge(edge){};
float CalcArea() const { return m_edge*m_edge;};

};

class Triangle{
private:
float m_edge1;
float m_edge2;
float m_edge3;


public:
Triangle() : m_edge1(0),m_edge2(0),m_edge3(0) {};
Triangle(float e1,float e2,float e3) : m_edge1(e1),m_edge2(e2),m_edge3(e3){};
Triangle(Point2d p1,Point2d p2,Point2d p3);
float CalcArea();

};

class Sphere{

private:
float m_ratio;


public:
Sphere() : m_ratio(0) {};
Sphere(float ratio) : m_ratio(ratio){};
float CalcArea() const { return 4*PI*m_ratio*m_ratio;};

};

class Tetrahedron{

private:
float m_edge1;
float m_edge2;
float m_edge3;
float m_edge4;
float m_a1;
float m_a2;

public:
Tetrahedron() : m_edge1(0),m_edge2(0),m_edge3(0),m_edge4(0){};
Tetrahedron(Point3d p1,Point3d p2,Point3d p3, Point3d p4);
float CalcArea();

};

class Cube{

private:
float m_edge;


public:
Cube() : m_edge(0) {};
Cube(float edge) : m_edge(edge){};
float CalcArea() const { return m_edge*m_edge*6;};
};

#endif
