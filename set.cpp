#include <set>
#include <iostream>
#include <string>
using namespace std;
 
set<string> func(int n){
 	set<string> s_n;
 	
 	if(n==1){
 		s_n.insert("()");
 		return s_n;
	}
	set<string> s_n_1=func(n-1);
	for(set<string>::iterator i=s_n_1.begin();i!=s_n_1.end();i++){
		s_n.insert("()"+*i);
		s_n.insert(*i+"()");
		s_n.insert("("+*i+")");
	}
	return s_n;
 }
 
int main(){	
	set<string> s;
	int n = 0;
	s=func(3);
	for(set<string>::iterator i=s.begin();i!=s.end();i++){
		n++;
	}
    cout<<n<<endl;
	return 0;
}
