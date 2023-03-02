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
    if(m==1 || m==2){
        m+=12;
        year--;
    }
    int week=(day+2*m+3*(m+1)/5+year+year/4-year/100+year/400+1)%7;
    cout<<WeekMap[week]<<endl;
    return 0;
}
