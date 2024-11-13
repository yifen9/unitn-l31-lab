using namespace std;
#include <iostream>
#include <cmath>

struct point{float pos[3];};

float point_distance(point,point);

float tri_p(point,point,point);

int main(){
    point p1,p2,p3;
    p1.pos[0]=0; p1.pos[1]=0; p1.pos[2]=0;
    p2.pos[0]=1; p2.pos[1]=2; p2.pos[2]=3;
    p3.pos[0]=3; p3.pos[1]=6; p3.pos[2]=9;

    cout << "P1: 0,0,0" << endl;
    cout << "P2: 1,2,3" << endl;
    cout << "P3: 3,6,9" << endl;

    cout << endl;

    cout << "D P1-P2: " << point_distance(p1,p2) << endl;
    cout << "D P1-P3: " << point_distance(p1,p3) << endl;
    cout << "D P2-P3: " << point_distance(p2,p3) << endl;

    cout << endl;

    cout << "P tri P1,P2,P3: " << tri_p(p1,p2,p3) << endl;
}

float point_distance(point p1, point p2){
    return sqrt(
         (p1.pos[0]-p2.pos[0])*(p1.pos[0]-p2.pos[0])
        +(p1.pos[1]-p2.pos[1])*(p1.pos[1]-p2.pos[1])
        +(p1.pos[2]-p2.pos[2])*(p1.pos[2]-p2.pos[2])
    );
}

float tri_p(point p1, point p2, point p3){
    return(
         point_distance(p1,p2)
        +point_distance(p1,p3)
        +point_distance(p2,p3)
    );
}