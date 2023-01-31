#include<iostream>
#include<cmath>
#include"calculate.h"

using namespace std;

double getdot::randot() // 점 랜덤 생성
{
    return  (rand()%(axisrange2+(-1*axisrange1))) + axisrange1;
}

double cal::getrange(struct dot a, struct dot b) // 점간의 거리 구하는 함수
{
    return (sqrt((pow(abs(b.x - a.x), 2) + pow(abs(b.y - a.y), 2))));
}

