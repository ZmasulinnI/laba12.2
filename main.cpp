#include <iostream>

using namespace std;


class Array{
private:
    int *arr;
    int size;
    const int max = 100;
public:
    Array(int size_v)
    {
        this->size = size_v;
        arr = new int[size];
        arr = {0};
    }
    Array(int size_v, int deflt)
    {
        this->size = size_v;
        arr = new int[size];
        for (int i = 0; i < size;i++) arr[i] = deflt;
    }
    
};

class Time{
private:
    int hours;
    int minutes;
public:
    Time(int _h, int _m)
    {
        this->hours = _h;
        this->minutes = _m;
        timeTranslation();
    }
    void timeTranslation()
    {
        while(this->minutes >= 60)
        {
            this->hours+= 1;
            this->minutes -=60;
        }
        while(this->minutes < 0)
        {
            this->hours-= 1;
            this->minutes +=60;
        }
        while(this->hours >= 24)
        {
            this->hours-= 24;
        }
        while(this->hours < 0)
        {
            this->hours+= 24;
        }

    }
    void getTime(){
        printf("%d.%d", this->hours, this->minutes);
    }
};


class Bill{
private:
    string lastName;
    string numberPhone;
    int callPrice;
    int discount;
    Time startTime;
    Time endTime;
public:
    Bill(string _ln, string _np, int _cp, int _dc, Time _st, Time _et)
    {
        this->lastName = _ln;
        this->numberPhone = _np;
        this->callPrice = _cp;
        this->discount = _dc;
        this->startTime = _st;
        this->endTime = _et;
    }
};


int main(){

    return 0;
}