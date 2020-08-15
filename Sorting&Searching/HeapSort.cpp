#include<bits/stdc++.h>
using namespace std;


void heapify(vector<int> &v, int i, int size){
    int left= 2*i;
    int right= 2*i+1;
    int maxindex=i;

    if(left< size  && v[i]<v[left]){
        maxindex=left;
    }
    if(right<size && v[maxindex]<v[right]){
        maxindex= right;
    }
    if(maxindex!=i){
        swap(v[maxindex], v[i]);
        heapify(v, maxindex, size);
    }
}

void convert_to_heap(vector<int> &v){
    int n= (v.size()-1)/2;

    for(int i=n;i>0;i--){
        heapify(v, i, v.size());
    }
}

void HeapSort(vector<int> &v){
    convert_to_heap(v);
    int n=v.size();

    while(n>1){
        swap(v[1], v[n-1]);
        n--;
        heapify(v, 1, n);
    }

}

int main(){
    vector<int> v{-1, 12, 23, 1, 7, 18, 20};

    HeapSort(v);

    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}