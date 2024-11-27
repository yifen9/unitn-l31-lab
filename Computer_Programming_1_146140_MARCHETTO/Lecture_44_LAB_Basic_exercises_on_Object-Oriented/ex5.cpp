using namespace std;
#include <iostream>

class Circle{
    private:
        const float PI = 3.1415926;
        float r, x, y;
    public:
        Circle();
        Circle(Circle&);
        float circle_get_radius();
        float circle_get_x();
        float circle_get_y();
        void circle_set(const float, const float, const float);
        float circle_area();
        float circle_circumference();
        void circle_print();
};

float random_float();

int main(){
    Circle* C = new Circle[3];

    for(int i=0; i<3; i++){C[i].circle_set(3,18,2);}

    srand(time(NULL));

    int i1 = rand()%3;
    int i2 = i1;
    while(i1 == i2){i2 = rand()%3;}

    C[i1].circle_set(random_float(),random_float(),random_float());
    C[i2].circle_set(random_float(),random_float(),random_float());

    for(int i=0; i<3; i++){
        cout << "Circle " << i << ':' << endl;
        C[i].circle_print();
    }

    return 0;
}

Circle::Circle(){
    r = 0;
    x = 0;
    y = 0;
}

Circle::Circle(Circle &A){
    r = A.circle_get_radius();
    x = A.circle_get_x();
    y = A.circle_get_y();
}

float Circle::circle_get_radius(){
    return r;
}

float Circle::circle_get_x(){
    return x;
}

float Circle::circle_get_y(){
    return y;
}

void Circle::circle_set(const float r, const float x, const float y){
    this->r = r;
    this->x = x;
    this->y = y;
}

float Circle::circle_area(){
    return (PI*r*r);
}

float Circle::circle_circumference(){
    return (2*PI*r);
}

void Circle::circle_print(){
    cout << "- radius: " << r << endl;
    cout << "- center: " << endl;
    cout << "  - x: " << x << endl;
    cout << "  - y: " << y << endl;
}

float random_float(){return (float(rand() % 0b11111111'11111111)
                           / float(rand() % 0b11111111));}