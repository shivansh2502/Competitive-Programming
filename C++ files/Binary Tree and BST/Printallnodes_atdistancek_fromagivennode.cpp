#include<bits/stdc++.h>
using namespace std;
vector<int> v;

class node{
    public:
        int data;
        node *left, *right;

        node(int d){
            data=d;
            left=right=NULL;
        }
};

node* buildtreefrominandpre(int* pre, int* in, int s, int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    node* root=new node(pre[i]);
    int index=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }

    i++;

    root->left = buildtreefrominandpre(pre, in, s, index-1);
    root->right = buildtreefrominandpre(pre, in, index+1, e);
    return root;
}

void printkdistanceNodeDown(node *root, int k) {
    if (root == NULL || k < 0)  return; 

    if (k==0){ 
        v.push_back(root->data);
        return; 
    } 

    printkdistanceNodeDown(root->left, k-1); 
    printkdistanceNodeDown(root->right, k-1); 
} 

int printkdistanceNode(node* root, int target , int k) {

    if (root == NULL) return -1; 

    if (root->data == target){ 
        printkdistanceNodeDown(root, k); 
        return 0; 
    } 

    int dl = printkdistanceNode(root->left, target, k); 
  
    if (dl != -1){ 
        if (dl + 1 == k){ 
            v.push_back(root->data);
        }

        else
            printkdistanceNodeDown(root->right, k-dl-2); 

        return 1 + dl; 
    } 

    int dr = printkdistanceNode(root->right, target, k); 
    if (dr != -1){ 
        if (dr + 1 == k){ 
            v.push_back(root->data);
        }
        else
            printkdistanceNodeDown(root->left, k-dr-2); 
        return 1 + dr; 
    } 
    return -1; 
}


int main(){
    int n;
    cin>>n;
    int pre[n];
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    int in[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    node* root=buildtreefrominandpre(pre, in, 0, n-1);

    int t;
    cin>>t;
    while(t--){
        int target,k;
        cin>>target>>k;
        //node* tar=findnode(root, target);
        printkdistanceNode(root, target, k); 
        if(v.size()==0)
            cout<<0<<endl;
        else{
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        v.clear();
    }
    return 0;
}