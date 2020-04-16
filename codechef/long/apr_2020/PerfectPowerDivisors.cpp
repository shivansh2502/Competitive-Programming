#include<bits/stdc++.h>

using namespace std;

#define int long long

#define w(x)    int x; cin>>x; while(x--)

int mo = 1000000007;

int inv(int a) {

    int r = 1, t = a, k = mo - 2;
    while (k) {
        if (k & 1) r = (long long) r * t % mo;
        t = (long long) t * t % mo;
        k >>= 1;
    }
    return r;

}
 
#define N 1000005 

#define MAX 1000000000000000005






unordered_set<int> sq; 

set<int> sc; 






void formsieve(){
    for (int i = 2; i < N; i++){ 
        sq.insert(i * i); 
  
        if (sq.find(i) != sq.end()) 
                continue; 
        int temp = i; 
  




        while (i * i <= MAX / temp){ 


            temp *= (i * i); 


            sc.insert(temp); 

        } 
    } 
}


int32_t main() {



    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    formsieve();
    int at= inv(6);
    
    w(t){
        int n1;
        cin>>n1;
        int sumtot= (n1%mo);


        if(n1==1){
            cout<<1<<"\n";
            continue;
        }


        
        for(auto i:sc){


        	if(i==1){
        		continue;
        	}


        	if(i>n1){
        		break;
        	}


        	else{
	        	int xt= n1/i;
	        	int val= (xt%mo*i%mo)%mo;
	        	sumtot= ((sumtot%mo)+ (val%mo))%mo;
        	}
        }



        int randome=100000000000000000;
        for(int i=2 ; (i*i*i)<=n1 ; i++){


            int j=i*i;
            int xt= n1/j;


            randome= min(randome,xt);

            int val= (xt%mo*j%mo)%mo;


        
            sumtot= ((sumtot%mo)+ (val%mo))%mo;
        }




        if(randome==100000000000000000) randome=2;
        





        for(int i=1; i<(randome) ; i++){

            int xt= n1/i;
            int kt=sqrtl(xt);

            int yt= n1/(i+1);
            int lt=sqrtl(yt);

            
            unsigned int sqsumtot1= ((kt-lt)%mo * (((2%mo*((kt%mo * kt%mo)%mo + (lt%mo * lt%mo)%mo  + (lt%mo * kt%mo)%mo))%mo) + (3%mo*((kt+lt)%mo))%mo + 1)%mo * at%mo)%mo; 
            
            int ans1= ((sqsumtot1)%mo * i%mo)%mo;
            
            sumtot= ((sumtot%mo)+ (ans1%mo))%mo;


        }
        

        cout<<sumtot%mo<<"\n";
    }

    return 0;

}

