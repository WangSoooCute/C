#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void){
    map<string,int> MonthMap={
        {"January",1},{"February",2},{"March",3},{"April",4},
        {"May",5},{"June",6},{"July",7},{"August",8},
        {"September",9},{"October",10},{"November",11},{"December",12}
    };
    map<int,string>WeekMap={
        {0,"Sunday"},{1,"Monday"},{2,"Tuesday"},{3,"Wednesday"},
        {4,"Thursday"},{5,"Friday"},{6,"Saturday"}
    };
    int day;
    string month;
    int year;
    cin>>day>>month>>year;

    int m=MonthMap[month];
    if(m==1 || m==2){//1、2月处理为上一年的13、14月
        m+=12;
        year--;
    }
    int week=(day+2*m+3*(m+1)/5+year+year/4-year/100+year/400+1)%7;
    cout<<WeekMap[week]<<endl;
    return 0;
}

//该文件在Mac端编译时，不能用g++，而要用g++ -std=c++11

/*Kim Larsen公式的原理：

公元0年1月1日是星期日，
公元0年3月1日是星期四，即星期数是4（公元0年是闰年

不考虑闰年的话，第y年的3月1日的星期数是4-1+365*(y-1)，它的余同为y+2；
每经过4年会有一个闰年，所以一共会多y/4天。每100年会少一个闰年，每400年又会多一个闰年。闰年导致的天数变化是y/4-y/100+y/400

3-7月每月有31、30、31、30、31天，8-12月也是同样的分布，甚至排在后面1月也是一个大月31天，
所以，m月d日就是从3月1日起算的第(m-3)*30+(m+1)*3/5-2+d天，
即星期数是y+2 + y/4-y/100+y/400 + (m-3)*30+(m+1)*3/5-2+d，它的余同为d+2m+3(m+1)/5+y+y/4-y/100+y/400+1
*/
