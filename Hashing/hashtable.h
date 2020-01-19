#include<cstring>
using namespace std;

template<typename T>

class node{
    public:
        string key;
        T value;
        node<T>* next;

        node(string k, T v){
            key=k;
            value=v;
        }
        ~node(){
            if(next!=NULL){
                delete next;
            }
        }

};

template<typename T>

class Hashtable{
    int cs;
    int ms;
    node<T>** buckets;

    void rehash(){
        node<T>** oldbuckets=buckets;
        int oldms=ms;
        ms=ms*2;
        cs=0;
        buckets=new node<T>* [ms];
         
        for(int i=0;i<ms;i++){
            buckets[i]=NULL;
        }
         
        for(int i=0;i<oldms;i++){
            node<T>* temp=oldbuckets[i];
            if(temp!=NULL){
                while(temp!=NULL){
                    insert(temp->key, temp->value);
                    temp=temp->next;
                }
                delete oldbuckets[i];
            }
        }
        delete [] oldbuckets;
    }

    int hashFn(string key){
        int ans=0;
        int mul=1;
        int l=key.length();
        for(int i=0;i<l;i++){
            ans+=key[l-i-1]*mul;
            mul*=37;
            mul%=ms;
            ans%=ms;
        }
        return ans;
    }


    public:
        Hashtable(int ds=7){
            cs=0;
            ms=ds;
            buckets=new node<T>*[ms];

            for(int i=0;i<ms;i++){
                buckets[i]=NULL;
            }
        }

        void insert(string key, T value){
            int i=hashFn(key);
            node<T>* n= new node<T> (key,value);
            n->next=buckets[i];
            buckets[i]=n;
            cs++;
            float loadfactor=(float) cs/ms;
            if(loadfactor>0.7){
                cout<<"Load factor is "<<loadfactor<<endl;
                rehash();
            }
        }

        void print(){
            for(int i=0;i<ms;i++){
                cout<<"Bucket "<<i<<" ";
                node<T>* temp=buckets[i];
                while(temp!=NULL){
                    cout<<temp->key<<" ";
                    temp=temp->next;
                }
                cout<<endl;
            }
        }

        T* search(string k){
            int i=hashFn(k);
            node<T>* temp=buckets[i];
            while(temp!=NULL){
                if(temp->key==k){
                    return &(temp->value);
                }
            }
            return NULL;
        }

        void erase(string k){
            int i=hashFn(k);
            node<T>* temp=buckets[i];
            if(temp->key==k){
                buckets[i]=temp->next;
                delete temp;
                return;
            }
            node<T>* prev;
            while(temp!=NULL && temp->key!=k){
               
                prev=temp;
                temp=temp->next;
            }
            if(temp==NULL){
                return;
            }
            else{
                prev->next=temp->next;
                delete temp;
                return;
            }
        }

        T& operator[](string k){
            T* temp=search(k);
            if(temp==NULL){
                T garbage;
                insert(k, garbage);
                T* value= search(k);
                return *value;
            }
            return *temp;
        } 

};


