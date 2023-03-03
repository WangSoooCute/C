#include<iostream>
#include<string>
#include<cstring>
using namespace std;

typedef struct{
	unsigned w;//权值
	unsigned p;//指向双亲 
	unsigned l;//指向左孩子 
	unsigned r;//指向右孩子
	string word;
}Node;
Node HT[100000];
string HC[100000];//赫夫曼编码

void select(int end,int& l,int& r){//l,r的引用，便于修改其值 
	int min;
	
	for(int i=1;i<=end;i++)
		if(HT[i].p==0){
			min=i;
			break;
		}
	for(int i=1;i<=end;i++)
		if(HT[i].p==0 && HT[i].w<HT[min].w)
			min=i;
	l=min;
	
	for(int i=1;i<=end;i++)
		if(HT[i].p==0 && i!=l){
			min=i;
			break;
		}
	for(int i=1;i<=end;i++)
		if(HT[i].p==0 && i!=l && HT[i].w<HT[min].w)
			min=i;
	r=min;
}

void createHT(int n){
	cout<<endl<<"建立的赫夫曼树为:"<<endl;
	int l,r;
	for(int i=n+1;i<=2*n-1;i++){
        //选择
		select(i-1,l,r);
		
		HT[l].p=i;
		HT[r].p=i;
		HT[i].l=l;
		HT[i].r=r;
        HT[i].w=HT[l].w+HT[r].w;
		
		cout<<"双亲结点权重:"<<HT[i].w<<" 左孩子结点权重:"<<HT[l].w<<" 右孩子结点权重:"<<HT[r].w<<endl; 
	}
}

//创建Huffman Code
void createHC(int n){
	cout<<endl<<"创建赫夫曼编码:"<<endl;
	for(int i=1;i<=n;i++){
		string tmp="";
		
		for(int j=i;HT[j].p!=0;j=HT[j].p){
			int p=HT[j].p;
            //0表示左孩子，1表示右孩子
			if(HT[p].l==j)
				tmp.insert(0,"0");//在字符串的最前面插入"0"
			else if(HT[p].r==j)
				tmp.insert(0,"1");
		}
		HC[i].assign(tmp,0,n-1);
		
		cout<<"第"<<i<<"个结点的权值代表的字符串为:"<<HT[i].word<<endl;
		cout<<"第"<<i<<"个结点的权值为:"<<HT[i].w<<" 编码为："<<HC[i]<<endl; 
	}
}

int main(){
    //叶子节点的数目
    int n;
	cout<<"请输入叶子节点的数目n:"<<endl;
	cin>>n;

	//初始化HT数组 
	cout<<endl<<"请依次按顺序输入每个叶子节点的权值:"<<endl;
	for(int i=1;i<=n;i++){//树的结点下标从1开始，而非0开始
		cout<<"请输入第"<<i<<"个叶子节点代表的字符串:"<<endl;
		cin>>HT[i].word;
        cout<<"请输入第"<<i<<"个叶子节点的权值:"<<endl;
		cin>>HT[i].w;
        HT[i].p=0;
		HT[i].l=0;
		HT[i].r=0;
	}
	for(int i=n+1;i<=2*n-1;i++){//Huffman树结点有2*n-1个
		HT[i].w=0;
		HT[i].p=0;
		HT[i].l=0;
		HT[i].r=0;
		HT[i].word='0';
	}
	
	createHT(n);
	createHC(n);
	return 0;
}

