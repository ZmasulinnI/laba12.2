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
        Price();
    }
    double sum_getter()
    {
        return sumPrice;
    }
    string last_name_getter()
    {
        return lastName;
    }

    void Price()
    {
        int callTime;
        double priceWithoutDisc;
        if(startTime.hoursGetter() > endTime.hoursGetter())
        {
            callTime = ((endTime.hoursGetter()+24)*60+endTime.minutesGetter())-(startTime.hoursGetter()*60+startTime.minutesGetter());
        }
        else
        {
            callTime = (endTime.hoursGetter()*60+endTime.minutesGetter())-(startTime.hoursGetter()*60+startTime.minutesGetter());
        }
        priceWithoutDisc = callTime * this->minutePrice;
        this->sumPrice = priceWithoutDisc - ((priceWithoutDisc/100)*this->discount);
    }
    void output()
    {
        printf("%s-%s %d %d ", lastName.c_str(), numberPhone.c_str(), minutePrice, discount);
        startTime.getTime();
        endTime.getTime();
        cout << this->sumPrice << "\n";
    }
};

class ListPayer{
private:
    int vecLength;
    string name;
    vector <Bill> List;
    double totalPrice;
public:
    ListPayer(){}
    void init()
    {
        cin >> vecLength;
        cin >> this->name;
        List.resize(vecLength);
        sum_calculate();
    }
    void vec_output()
    {
        for(int i = 0; i < vecLength; ++i)
        {
            List[i].output();
        }
    }

    void sum_calculate()
    {
        for(int i = 0; i < vecLength;i++)
        {
            this->totalPrice += this->List[i].sum_getter();
        }
    }

    void operator +(ListPayer& value)
    {
        ListPayer output_sum;
        output_sum.List = this->List;
        bool flag = false;
        for(int i = 0;i<value.vecLength;i++)
        {
            flag = false;
            for(int j = 0;j < this->vecLength;j++)
            {
                if(value.List[i].last_name_getter() == output_sum.List[j].last_name_getter())
                {
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                output_sum.List.push_back(value.List[i]);
            }
        }
        output_sum.name = "ListPayer1 + ListPayer2";
        output_sum.vecLength = output_sum.List.size();
        output_sum.sum_calculate();
        output_sum.output();
    }
    void operator -(ListPayer& value)
    {
        ListPayer *output_sub = new ListPayer;
        bool flag = false;
        for(int i  = 0; i < this->vecLength; i++)
        {
            flag = false;
            for(int j = 0; j < value.vecLength; j++)
            {
                if(this->List[i].last_name_getter() == value.List[j].last_name_getter())
                {
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                output_sub->List.push_back(this->List[i]);
            }
        }
        output_sub->name = "ListPayer1 - ListPayer2";
        output_sub->vecLength = output_sub->List.size();
        output_sub->sum_calculate();
        output_sub->output();
    }
    void operator *(ListPayer& value)
    {
        ListPayer output_mult;
        cout << "\n" << output_mult.totalPrice << "\n";
        cout << "\n" << output_mult.vecLength << "\n";
        bool flag = false;
        for(int i  = 0; i < this->vecLength; i++)
        {
            flag = false;
            for(int j = 0; j < value.vecLength; j++)
            {
                if(this->List[i].last_name_getter() == value.List[j].last_name_getter())
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
            {
                output_mult.List.push_back(this->List[i]);
            }
        }
        output_mult.name = "ListPayer1 * ListPayer2";
        output_mult.vecLength = output_mult.List.size();
        output_mult.sum_calculate();
        output_mult.output();
        cout << output_mult.totalPrice;
    }

    void output()
    {
        cout << this->name << " summa=" << this->totalPrice << "\n";
        vec_output();
    }

};






int main()
{
    ListPayer ListPayer1;
    ListPayer ListPayer2;


    ListPayer1.init();
    ListPayer2.init();

//    ListPayer1.output();
//    ListPayer2.output();

//    ListPayer1 + ListPayer2;

    ListPayer1 + ListPayer2;
    ListPayer1 - ListPayer2;
    ListPayer1 * ListPayer2;


    return 0;
}