#include<bits/stdc++.h>
using namespace std;

 void permute(string str,string per){
    if(str.size()==0){
        cout<<per<<endl;
        return;
    }

    for(int i=0;i<str.size();i++){
        char curr=str[i];
        string remstr;
        string temp;

        temp=str;
        temp.erase(temp.begin()+i); 
        remstr=temp;

        // per=per+curr;
        permute(remstr,per+curr);
    }

}

int main(){
    int n;
    cout<<"Enter the size of the string: ";
    cin>>n;

    cout<<"Enter the string: ";
    string str;

    cin>>str;
    string per="";

     permute(str,per);
     return 0;   
}