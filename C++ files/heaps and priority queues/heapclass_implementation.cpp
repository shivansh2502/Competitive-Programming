#include<bits/stdc++.h>
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b){
        if(minHeap){
            return a<b;
        }
        else{
            return a>b;
        }
    }

    void Heapify(int i){
        int left=2*i;
        int right=2*i+1;
        int minIndex=i;
        
        if(left<v.size() && compare(v[left],v[i])){
            minIndex=left;
        }
        if(right<v.size() && compare(v[right],v[minIndex])){
            minIndex=right;
        }
        if(minIndex!=i){
            swap(v[i],v[minIndex]);
            Heapify(minIndex);
        }
    }

    public:
        Heap(bool type=true){
            minHeap=type;
            v.push_back(-1);
        }

        void push(int data){
            v.push_back(data);

            int index=v.size()-1;
            int parent=index/2;

            while(index>1 && compare(v[index],v[parent])){
                swap(v[index],v[parent]);
                index=parent;
                parent=parent/2;
            }
        }

        void top(){
            cout<<v[1]<<endl;
        }

        bool empty(){
            return v.size()==1;
        }

        void pop(){
            int last=v.size()-1;
            swap(v[1],v[last]);
            v.pop_back();
            Heapify(1);
        }

};

int main(){
    Heap h(false);
    h.push(5);
    h.push(15);
    h.push(23);
    h.push(2);
    h.push(7);
    h.top();
    while(!h.empty()){
        h.top();
        h.pop();
    }
    return 0;
}