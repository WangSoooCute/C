#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> myQueue;
    for(int i = 0; i < 5; ++i)
        myQueue.push(i);

    while(true){
        if(myQueue.empty()){
            printf("myQueue is empty!\n");
            break;
        }
        printf("front of myQueue is %d\n", myQueue.front());
        
        myQueue.pop();
    }
}
