#include<bits/stdc++.h>
using namespace std;

void buildSegmentTree(int *a, int *tree, int s, int e, int treeindex){
    if(s==e){
        tree[treeindex]= a[s];
        return;
    }
    int mid= (s+e)/2;
    buildSegmentTree(a, tree, s, mid, 2*treeindex);
    buildSegmentTree(a, tree, mid+1, e, 2*treeindex+1);
    tree[treeindex]= tree[2*treeindex] + tree[2*treeindex +1];
}

int query(int *tree,int index, int s, int e, int qs, int qe){
    //no overlap
    if(s>qe || e<qs){
        return 0;
    }
    //complete overlap
    else if(qs<=s && qe>=e){
        return tree[index];
    }
    //partial overalap
    int mid=(s+e)/2;
    int q1= query(tree, 2*index, s, mid, qs, qe);
    int q2= query(tree, 2*index +1, mid+1, e, qs, qe);
    return q1+q2;
}

void updation(int *tree, int index, int s, int e, int i, int value){

    if(s>i || e<i) return;

    else if(s==e){
        tree[index]= value;
        return;
    }

    int mid= (s+e)/2;
    updation(tree, 2*index, s, mid, i, value); 
    updation(tree, 2*index+1, mid+1, e, i, value); 
    tree[index]= tree[2*index]+ tree[2*index+1];
    return;
}

void rangeupdation(int *tree, int index, int s, int e, int rs, int re, int inc){
    
    //no overlap
    if(re<s ||  rs>e){
        return;
    }

    // complete overlap
    if(s==e){
        tree[index] +=inc;
        return;
    }

    // partial overlap
    int mid= (s+e)/2;
    rangeupdation(tree, 2*index, s, mid, rs, re, inc);
    rangeupdation(tree, 2*index+1, mid+1, e, rs, re, inc);
    tree[index]=tree[2*index]+ tree[2*index +1];
    return;
}

int main(){
    int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n= sizeof(a)/sizeof(int);
    int tree[2*n];

    buildSegmentTree(a, tree, 0, n-1, 1);
    //print segment tree
    for(int i=1;i<2*n;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    // query 
    cout<<query(tree, 1, 0, n-1, 2, 6)<<endl;

    //updation
    updation(tree, 1, 0, n-1, 3, -4);
    cout<<query(tree, 1, 0, n-1, 2, 6)<<endl;

    //range updating
    rangeupdation(tree, 1, 0, n-1, 2, 4, 10);
    cout<<query(tree, 1, 0, n-1, 2, 2)<<endl;

    return 0;
}