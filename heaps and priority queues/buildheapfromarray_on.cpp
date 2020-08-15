#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int i){

    int left= 2*i;
    int right= 2*i+1;
    int maxIndex= i;

    if(left<v.size() && v[i]>v[left]){
        maxIndex=left;
    }
    if(right<v.size() && v[maxIndex]>v[right]){
        maxIndex=right;
    }
    if(maxIndex!=i){
        swap(v[i], v[maxIndex]);
        heapify(v, maxIndex);
    }

}


void convert_to_heap(vector<int> &v){

    int n= (v.size()-1)/2;
    for(int i=n;i>=0;i--){
        heapify(v, i);
    }
}

int main(){
    vector<int> v{10, 24, 12, 7, 3, 18, 20};

    convert_to_heap(v);

    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}