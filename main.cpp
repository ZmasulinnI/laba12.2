#include <iostream>
#include <vector>
#include <cmath>

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
    Time(int _h = 0, int _m = 0)
    {
        this->hours = _h;
        this->minutes = _m;
        timeTranslation();
    }
    void input()
    {
        string input;
        string buff;
        int dot_pos;
        cin >> input;
        dot_pos = input.find(".");
        buff = input.substr(0, dot_pos);
        this->hours = stoi(buff);
        buff = input.substr(dot_pos + 1);
        this->minutes = stoi(buff);
        timeTranslation();
    }
    int hoursGetter()
    {
        return hours;
    }
    int minutesGetter()
    {
        return minutes;
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
        cout << hours << "." << minutes << " ";
    }
};


class Bill{
private:
    string lastName;
    string numberPhone;
    int minutePrice;
    int discount;
    Time startTime;
    Time endTime;
    double sumPrice;

public:
    Bill(string _ln, string _np, int _mp, int _dc, Time &_st, Time &_et)
    {
        this->lastName = _ln;
        this->numberPhone = _np;
        this->minutePrice = _mp;
        this->discount = _dc;
        startTime = _st;
        endTime = _et;
    }
    Bill()
    {
        cin >> this->lastName;
        cin >> this->numberPhone;
        cin >> this->minutePrice;
        cin >> this->discount;
        startTime.input();
        endTime.input();

    }
    void Price()
    {
        int callTime;
        int priceWithoutDisc;
        if(startTime.hoursGetter() > endTime.hoursGetter())
        {
            callTime = ((((endTime.hoursGetter()+24)*60)+endTime.minutesGetter())-(startTime.hoursGetter()*24)+startTime.minutesGetter());
        }
        else
        {
            callTime = (((endTime.hoursGetter()*60)+endTime.minutesGetter())-(startTime.hoursGetter()*24)+startTime.minutesGetter());
        }
        priceWithoutDisc = callTime * this->minutePrice;
        this->sumPrice = round((priceWithoutDisc - (priceWithoutDisc/100)*this->discount)*100)/100;
    }
    void output()
    {
        printf("%s-%s %d %d ", lastName.c_str(), numberPhone.c_str(), minutePrice, discount);
        startTime.getTime();
        endTime.getTime();
//        cout << this->sumPrice << "\n";
    }
};

void vec_output(vector <Bill> &arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i].output();
    }
}




int main()
{
//    string lastName, numberPhone;
//    int minutePrice, discount;
//    int _hs, _ms, _he, _me;
//    cin >> lastName >> numberPhone >> minutePrice >> discount >> _hs >> _ms >> _he >> _me;
//    Time start(_hs, _ms);
//    Time end(_he, _me);
    int size1 = 1, size2 = 1;
    string name1, name2;

    cin >> size1;
//    cin >> name1;
    vector <Bill> array1(size1);

//    cin >> size2;
//    cin >> name2;
//    vector <Bill> array2(size2);

    vec_output(array1, array1.size());


    return 0;
}