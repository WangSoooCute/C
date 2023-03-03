#include <cstdio>
#include <string>
using namespace std;

int main(){
    string str = "howareyou";
    //int pos = str.find("are");
    int pos = str.find("was");

    if(pos != string:: npos)
        printf("Found, pos = %d\n", pos);
    else
        printf("Not found\n");
    return 0;
}
