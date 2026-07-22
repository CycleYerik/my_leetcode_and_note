#include <iostream>

using namespace std;

int month_day_p[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int month_day_n[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int year_days = 365, year_days_leap = 366;

bool isleap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int is_date_valid(int p_year, int p_month, int p_day, int n_year, int n_month, int n_day)
{
    if(p_month <= 0 || p_month > 12 || n_month <= 0 || n_month > 12 || p_day <= 0 || p_day > 31 || n_day <= 0 || n_day > 31)
    {
        return -1;
    }

    if(isleap(p_year))
    {
        month_day_p[2] = 29;
    }
    if(isleap(n_year))
    {
        month_day_n[2] = 29;
    }

    if(month_day_n[n_month] < n_day || month_day_p[p_month] < p_day)
    {
        return -1;
    }

    //以上是有效判断

    //判断当前日期是否在发布日期的后面
    if(n_year < p_year || (n_year == p_year && n_month < p_month) || (n_year == p_year && n_month == p_month && n_day < p_day))
    {
        return -1;
    }


    int day_result = 0;

    if(n_year > p_year) //不同年
    {
        for(int i = p_year + 1 ; i < n_year ; i++)
        {
            day_result += isleap(i) ? year_days_leap : year_days; 
        }
        day_result += month_day_p[p_month] - p_day;
        for(int i = p_month+1 ; i <= 12 ; i++)
        {
            day_result += month_day_p[i];
        }

        for(int i = 1 ; i < n_month ; i++)
        {
            day_result += month_day_n[i];
        }

        day_result += n_day;
    }
    else 
    {
        for(int i = p_month +1 ; i < n_month ; i++)
        {
            day_result += month_day_n[i];
        }
        if(n_month > p_month)
        {
            day_result += month_day_n[p_month] - p_day;
            day_result += n_day;
        }
        else 
        {
            day_result += (n_day - p_day);
        }
        
    }

    if(day_result >= 30 )
    {
        return 1;
    }
    else 
    {
        return 0;
    }
      
}



int main(void)
{

    int p_year, p_month,  p_day,  n_year,  n_month,  n_day;

    cin >> p_year >> p_month >> p_day;
    cin >> n_year >> n_month >> n_day;

    cout << is_date_valid(p_year,p_month,p_day,n_year,n_month,n_day);

    return 0;
}