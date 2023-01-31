#ifndef CALCULATE_H
#define CALCULATE_H

#include <iostream>

using namespace std;

struct dot
{
    int x, y;
};

class getdot
{
public:
    int axisrange1, axisrange2;
    int dotnum;
    getdot(int a, int b, int c)
    {
        axisrange1 = a;
        axisrange2 = b;
        dotnum = c;
    }
    double randot();
};

class cal
{
public:
    int min[2];
    int max[2];
    double getrange(struct dot a, struct dot b);
    cal()
    {
        min[0] = max[0] = 0;
        min[1] = max[1] = 1;
    }
};

#endif // CALCULATE_H
