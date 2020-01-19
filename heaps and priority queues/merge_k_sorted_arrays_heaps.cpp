#include<bits/stdc++.h>
using namespace std;

class Merge{
    public:
        int data;
        char array;

        Merge(int data, char array){
            this->data=data;
            this->array=array;
        }

};

class merge_compare{
    public:
        bool operator()(Merge a, Merge b){
            return  a.data >= b.data ;
        }
};

int main(){
    int a[]={0,4,10,12};
    int b[]={1,3,5,7};
    int c[]={2,4,12,15,20};

    priority_queue<Merge, vector<Merge>, merge_compare> pq;
    
    vector<int> ans;
    int sizea=0;
    int sizeb=0;
    int sizec=0;
    pq.push(Merge(a[0],'a'));
    pq.push(Merge(b[0],'b'));
    pq.push(Merge(c[0],'c'));
    
    while(pq.top().data != INT_MAX){
        ans.push_back(pq.top().data);
        if(pq.top().array=='a'){
            sizea++;
            if(sizea<sizeof(a)/sizeof(int)){
                pq.push(Merge(a[sizea],'a'));
            }
            else{
                pq.push(Merge(INT_MAX,'a'));
            }
        }
        else if(pq.top().array=='b'){
            sizeb++;
            if(sizeb<sizeof(b)/sizeof(int)){
                pq.push(Merge(b[sizeb],'b'));
            }
            else{
                pq.push(Merge(INT_MAX,'b'));
            }
        }
        else if(pq.top().array=='c'){
            sizec++;
            if(sizec<sizeof(c)/sizeof(int)){
                pq.push(Merge(c[sizec],'c'));
            }
            else{
                pq.push(Merge(INT_MAX,'c'));
            }
        }
        pq.pop();
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}