/*
 * Title: hw5_3.cpp
 * Abstract: 
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/12/2018
 */
#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
Time();
Time(int hours, int minutes, char timeOfDays);
string display();
void setHour(int h);
void setMinute(int m);
void setTime(char pmOram);
void set(int h, int m, char pmOram);
int getMinute();
int getHour();
string validator(int times);
string timeValidation(int hour, char timeSpan, string output);
friend ostream& operator <<(ostream& outputStream, const Time& timeDay);
friend bool operator ==(Time& time1, Time& time2);
friend bool operator <(Time& time1, Time& time2);


private:
    int hour;
    int minute;
    char timeOfDay;
    string output;
    bool check = true;
};



Time::Time()
: hour(12), minute(0), timeOfDay('A')
{}

Time::Time(int hours, int minutes, char timeOfDays)
: hour(hours), minute(minutes), timeOfDay(timeOfDays)
{}

ostream& operator <<(ostream& outputStream, const Time& timeDay)
{
    Time * n = new Time;
    *n = timeDay;
    
    (*n).check = false;
    outputStream << (*n).display();
    (*n).check = true;
    
    delete n;
    n = nullptr;
    return outputStream;
}

bool operator <(Time& time1, Time& time2)
{
    
    if(time1.timeOfDay == time2.timeOfDay)
    {
        if(time1.hour == time2.hour)
        {
            if(time1.minute < time2.minute)
            {
                return true;
            }
            return false;
        }
        else
        {
            if(time1.hour < time2.hour){
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    
    else if(time1.timeOfDay == 'P' && time2.timeOfDay == 'A')
    {
        return false;
    }
}

bool operator ==( Time& time1, Time& time2)
{

    if (time1.hour == time2.hour && time1.minute == time2.minute && time1.timeOfDay == time2.timeOfDay)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Time::getHour()
{
    return hour;
}

int Time::getMinute()
{
    return minute;
}

void Time::setHour(int h)
{
    hour = h;
}
 
void Time::setMinute(int m)
{
    minute = m;
} 

void Time::setTime(char pmOram)
{
    
    timeOfDay = pmOram;
    
}

void Time::set(int h, int m, char pmOram)
{
    if(h > 12 || m > 59 || h < 1 || m < 0)
    {
        cerr << "*** ERROR: Incorrect value. ***" << endl;
    } 
    else if(pmOram == 'A' || pmOram == 'P')
    {
            setTime(pmOram);
            setHour(h);
            setMinute(m);
    }
    else
    {
        cerr << "*** ERROR: Incorrect value. ***" << endl;
    }
}


string Time::display()
{
    string validatetMinutes = validator(minute);
    output = to_string(hour) + ":" + validatetMinutes;
    output += timeValidation(hour, timeOfDay, output) + validatetMinutes + " military time)";
   
   
   if(check)
   {
       cout << output << endl;
   }
   
   return output;
    
}

string Time::timeValidation(int hour, char timeSpan, string output)
{
    if(hour == 12 && timeSpan == 'A')
    {
        output = " A.M.  (00";
        return output;
    }
    else if(timeSpan == 'A')
    {
        output = " A.M.   (" + to_string(hour);
    } 
    else if (hour > 9 && timeSpan == 'P')
    {
        output = " P.M.   (" + to_string(hour); 
    }
    else
    {
        output = " P.M.   (" + to_string(hour+12);
    }
    
    return output;
}

string Time::validator(int times)
{
    if(times < 10)
    {
        return "0" + to_string(times);
    }
    
    return to_string(times);
}



int main()
{
  /*Time labTime;
   Time mealTime;

   labTime.set(10, 0, 'A');
   cout << "===== lab time =====" << endl;
   labTime.display();
   cout << endl;

   cout << "\nIncorrect time 1" << endl;
   labTime.set(11, 65, 'P');
   
   cout << "\nIncorrect time 2" << endl;
   mealTime.set(7, 45, 'X'); 
   
   mealTime.set(5, 30, 'P');
   cout << "\n===== meal time =====" << endl;
   mealTime.display();
   cout << endl;
   
   return 0;*/
    Time labTime (10, 0, 'A');
   Time mealTime;
   
   cout << "labTime: " << labTime << endl;
   cout << "mealTime: " << mealTime << endl;
   
   mealTime.set(8, 45, 'A');
   cout << "\nNew mealTime for breakfirst: " << mealTime << endl;
   
   cout << "\n===== Compare two times =====" << endl;
   if (labTime == mealTime)
   {
       cout << "Bad schedule!\n";
   }
   else
   {
       cout << "Good schedule!\n";
   }
   
   cout << "\n===== Compare two times again=====" << endl;
   if (labTime < mealTime)
   {
       cout << "Let's do the lab first and then eat.\n";
   }
   else
   {
       cout << "Let's eat first and then do the lab.\n";
   }
   
   return 0;


}
