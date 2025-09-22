using namespace std;
#include <iostream>

class Time{
    private:
        int h, m, s;
    public:
        Time();
        int time_get_hour();
        int time_get_minutes();
        int time_get_seconds();
        void time_advance(const int, const int, const int);
        void time_reset(const int, const int, const int);
        void time_print();
};

int main(){
    Time* T = new Time();

    T->time_reset(11,59,59);

    T->time_advance(0,0,1);

    T->time_print();
    cout << endl;

    return 0;
}

Time::Time(){
    h = 0;
    m = 0;
    s = 0;
}

int Time::time_get_hour(){
    return h;
}

int Time::time_get_minutes(){
    return m;
}

int Time::time_get_seconds(){
    return s;
}

void Time::time_advance(const int h, const int m, const int s){
    int t = (((this->h + h) * 3600)
            + ((this->m + m) * 60)
            + (this->s + s))
            % (24 * 3600);
    Time::time_reset(t/3600,(t%3600)/60,t%60);
}
void Time::time_reset(const int h, const int m, const int s){
    this->h = h;
    this->m = m;
    this->s = s;
}
void Time::time_print(){cout << h << ':' << m << ':' << s;}