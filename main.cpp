#include <iostream>
#include <ctime>
#include <cstdlib>
#include "calculate.h"
using namespace std;

int main()
{
    srand(static_cast<size_t>(time(0)));

    int xrange1, yrange1, xrange2, yrange2;
    int dotnum;

    cout<<"insert range of x, y coordination"<<endl;
    cout<<" min x : ";
    cin>>xrange1;
    cout<<" max x : ";
    cin>>xrange2;
    cout<<" min y : ";
    cin>>yrange1;
    cout<<" max y : ";
    cin>>yrange2;
    cout<<" number of dots : ";
    cin>>dotnum;

    dot *dt= new dot[dotnum]; //점 좌표 동적 구조체 배열 

    getdot dotx(xrange1, xrange2, dotnum);// 각 점의 x축, y축 값을 rand함수로 생성
    for(int i=0; i<dotnum; i++)
    {
        dt[i].x = dotx.randot();
    }
    getdot doty(yrange1, yrange2, dotnum);
    for(int i=0; i<dotnum; i++)
    {
        dt[i].y = doty.randot();
    }

    cal *calrange = new cal; // 점간의 거리 구하는 클래스 동적할당으로 선언

    double maxrange = 0;
    double minrange = 0;
    for(int i=0; i<dotnum-1; i++) // 점간의 최대 거리, 최소 거리 식
    {
        for(int j=i+1; j<dotnum; j++)
        {
            if(calrange->getrange(dt[i],dt[j]) >= calrange->getrange( dt[calrange->max[0]], dt[calrange->max[1]] ))
            {
                calrange->max[0] = i;
                calrange->max[1] = j;
                maxrange = calrange->getrange(dt[calrange->max[0]],dt[calrange->max[1]]);
            }
            if(calrange->getrange(dt[i],dt[j]) <= calrange->getrange(dt[calrange->min[0]], dt[calrange->min[1]]))
            {
                calrange->min[0] = i;
                calrange->min[1] = j;
                minrange = calrange->getrange(dt[calrange->min[0]],dt[calrange->min[1]]);
            }
        }
    }
    cout<<"max range : "<< maxrange << endl;
    cout<<"max dot1 : "<< dt[calrange->max[0]].x << ", " << dt[calrange->max[0]].y<<endl;
    cout<<"max dot2 : "<< dt[calrange->max[1]].x << ", " << dt[calrange->max[1]].y<<endl;
    cout<<"min range : "<< minrange << endl;
    cout<<"min dot1 : "<< dt[calrange->min[0]].x << ", " << dt[calrange->min[0]].y<<endl;
    cout<<"min dot2 : "<< dt[calrange->min[1]].x << ", " << dt[calrange->min[1]].y<<endl;

    delete calrange;
    return 0;
}
