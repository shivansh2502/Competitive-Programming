#include<bits/stdc++.h>
using namespace std;
#define hashmap map<char,node*>
class node{
    public:
    char data;
    hashmap h;
    bool isterminal;
    
    node(char d){
        data=d;
        isterminal=false;
    }

};
class trie{
    public:
    node* root;
    
    trie(){
        root= new node('\0');
    }
    void addword( string word){
        node* temp=root;
        for(int i=0;word[i]!='\0';i++){
            char ch= word[i];
            if(temp->h.count(ch)==0){
                node* child= new node(ch);
                temp->h[ch]=child;
                temp=child;
            }
            else{
                temp=temp->h[ch];
            }
        }
        temp->isterminal=true;
    }
bool findtemp(string s){
    node * temp=root;
    for(int i=0;s[i]!='\0';i++){
        char ch=s[i];
        if(temp->h.count(ch)==1){
            temp=temp->h[ch];
        }
        else{
            return false;
        }
    }
    
    vector<string>v;
    print(s,v,temp);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return true;
}

void print(string s,vector<string>&v,node* temp){
    if(temp->isterminal){
        v.push_back(s);
    }
    for(auto i=temp->h.begin();i!=temp->h.end();i++){
        s+=i->second->data;
        print(s,v,i->second);
        s.pop_back();
    }
}
};

int main() {
    int n;
    cin>>n;
    trie t;
    string s;
    while(n--){
        cin>>s;
        t.addword(s);
    }
    int q;
    cin>>q;
    while(q--){
        cin>>s;
        bool temp=t.findtemp(s);
        if(!temp){
            cout<<"No suggestions"<<endl;
            t.addword(s);
        }

    }
	return 0;
}