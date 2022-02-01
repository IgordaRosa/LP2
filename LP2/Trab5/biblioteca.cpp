#include "biblioteca.hpp"
#include <cmath>

Triangle::Triangle(Point2d p1, Point2d p2, Point2d p3)
{
    float e3 = sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y));
    float e2 = sqrt((p1.m_x - p3.m_x)*(p1.m_x - p3.m_x) + (p1.m_y - p3.m_y)*(p1.m_y - p3.m_y));
    float e1 = sqrt((p2.m_x - p3.m_x)*(p2.m_x - p3.m_x) + (p2.m_y - p3.m_y)*(p2.m_y - p3.m_y));

    m_edge1 = e1;
    m_edge2 = e2;
    m_edge3 = e3;
}

float Triangle::CalcArea(){
    float s = (m_edge1+m_edge2+m_edge3)/2;
    float a = sqrt(s*(s-m_edge1)*(s-m_edge2)*(s-m_edge3));
    return a;
}

Tetrahedron::Tetrahedron(Point3d p1,Point3d p2,Point3d p3,Point3d p4)
{
    float l1 = sqrt((p3.m_x - p4.m_x)*(p3.m_x - p4.m_x) + (p3.m_y - p4.m_y)*(p3.m_y - p4.m_y) + (p3.m_z - p4.m_z)*(p3.m_z - p4.m_z));
    float l2 = sqrt((p2.m_x - p4.m_x)*(p2.m_x - p4.m_x) + (p2.m_y - p4.m_y)*(p2.m_y - p4.m_y) + (p2.m_z - p4.m_z)*(p2.m_z - p4.m_z));
    float e4 = sqrt((p1.m_x - p4.m_x)*(p1.m_x - p4.m_x) + (p1.m_y - p4.m_y)*(p1.m_y - p4.m_y) + (p1.m_z - p4.m_z)*(p1.m_z - p4.m_z));
    float e3 = sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y) + (p1.m_z - p2.m_z)*(p1.m_z - p2.m_z));
    float e2 = sqrt((p1.m_x - p3.m_x)*(p1.m_x - p3.m_x) + (p1.m_y - p3.m_y)*(p1.m_y - p3.m_y) + (p1.m_z - p3.m_z)*(p1.m_z - p3.m_z));
    float e1 = sqrt((p2.m_x - p3.m_x)*(p2.m_x - p3.m_x) + (p2.m_y - p3.m_y)*(p2.m_y - p3.m_y) + (p2.m_z - p3.m_z)*(p2.m_z - p3.m_z));

    m_edge1 = e1;
    m_edge2 = e2;
    m_edge3 = e3;
    m_edge4 = e4;
    m_a1 = l1;
    m_a2 = l2;
}

float Tetrahedron::CalcArea(){

    // area da base
    float s1 = (m_edge1+m_edge2+m_edge3)/2;
    float ab1 = sqrt(s1*(s1-m_edge1)*(s1-m_edge2)*(s1-m_edge3));

    float s2 = (m_edge4+m_edge2+m_a1)/2;
    float ab2 = sqrt(s2*(s2-m_edge4)*(s2-m_edge2)*(s2-m_a1));

    float s3 = (m_edge1+m_a1+m_a2)/2;
    float ab3 = sqrt(s3*(s3-m_edge1)*(s3-m_a1)*(s3-m_a2));

    float s4 = (m_edge3+m_a2+m_edge4)/2;
    float ab4 = sqrt(s4*(s4-m_edge3)*(s4-m_a2)*(s4-m_edge4));

    float a = ab1 + ab2 + ab3 + ab4;

    return a;
}


float ConverterL3d(string ponto, size_t p){
    float a1 =stof(ponto);

    size_t j=(ponto.find(","));

    for(size_t i=0; i<=j; i++){
        ponto.erase(ponto.begin()+0);
    }

    float a2 = stof(ponto);

    j=(ponto.find(","));
    
    for(size_t i=0; i<=j; i++){
        ponto.erase(ponto.begin()+0);
    }

    float a3 = stof(ponto);
    if(p==0){
        return a1;
    }
    if(p==1){
        return a2;
    }
    if(p==2){
        return a3;
    }
    return 0;
}

float ConverterL2d(string ponto, size_t p){ 
    size_t j=0;
    float a1 =stof(ponto);

    j=(ponto.find(","));

    for(size_t i=0; i<=j; i++){
        ponto.erase(ponto.begin()+0);
    }

    float a2 = stof(ponto);

    if(p==0){
        return a1;
    }
    if(p==1){
        return a2;
    }
    return 0;
}