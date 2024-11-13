using namespace std;
#include <iostream>
#include <cmath>

struct vertex{
    float pos[2];

    vertex *next = NULL;
};

vertex *polygon_ini();

float polygon_p(vertex*);

float point_distance(vertex*,vertex*);

int main(int argc, char *argv[]){
    vertex *P = polygon_ini();

    cout << "Perimeter: " << polygon_p(P) << endl;

    return 0;
}

vertex *polygon_ini(){
    vertex *P = new vertex();

    cout << "Please input the values of a polygon:" << endl;
    vertex *p = P;
    for(int i=0; i<5; i++){
        cout << " - Vertex " << i << ": " << endl;
        cout << "   - X: ";
        cin >> p->pos[0];
        cout << "   - Y: ";
        cin >> p->pos[1];
        p->next = new vertex();
        p = p->next;
    }
    delete p;

    return P;
}

float polygon_p(vertex *P){
    int res = 0;

    vertex *p = P;
    for(int i=0; i<4; i++){
        res += point_distance(p,p->next);
        p = p->next;
    }
    res += point_distance(p,P);

    return res;
}

float point_distance(vertex *p1, vertex *p2){
    return sqrt(
         (p1->pos[0]-p2->pos[0])*(p1->pos[0]-p2->pos[0])
        +(p1->pos[1]-p2->pos[1])*(p1->pos[1]-p2->pos[1])
    );
}