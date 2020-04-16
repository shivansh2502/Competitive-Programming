#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define f(i,n)			for(int i=0;i<n;i++)
#define fs(i,s,n)		for(int i=s;i<n;i++)
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
const int MOD = 119 << 23 | 1;
#define inf             1e18
#define double          long double
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void sm25official()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int gcd(int a, int b){
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}

void foo(double input, int &numerator, int &denominator){
    double integral = std::floor(input);
    double frac = input - integral;

    unsigned int precision = 1000000000000000000;
    // int v=frac*precision;
    int gcd_ = gcd(round(frac * precision), precision);

    denominator = precision / gcd_;
    numerator = round(frac * precision) / gcd_;
}

int inv(int a) {
    int r = 1, t = a, k = MOD - 2;
    while (k) {
        if (k & 1) r = (long long) r * t % MOD;
        t = (long long) t * t % MOD;
        k >>= 1;
    }
    return r;
}

double dp0[400][400];
double dp1[400][400];
double dpa[400][400];
double dpA[400][400];
double probabilty(string s, int x, int y, char ans){

    if(x==y && s[x]=='#'){
        return 0.25;
    }
    if(ans=='0' && dp0[x][y]!=0){return dp0[x][y];}
    if(ans=='1' && dp1[x][y]!=0){return dp1[x][y];}
    if(ans=='a' && dpa[x][y]!=0){return dpa[x][y];}
    if(ans=='A' && dpA[x][y]!=0){return dpA[x][y];}
    int open=0;
    char symbol;
    int mid=0;
    for(int i=x+1;i<y;i++){
        if(s[i]=='('){
            open++;
        }
        else if(s[i]==')'){
            open--;
        }
        else if(s[i]=='&' || s[i]=='|' || s[i]=='^'){
            if(open==0){
                symbol=s[i];
                mid=i;
                break;
            }
        }
    }
    int i=mid;
    if(symbol=='&'){
        
        if(ans=='0'){
            double exp1= probabilty(s, x+1, i-1, '0');
            double exp2= probabilty(s, i+1, y-1, '0');
            double exp5= probabilty(s, x+1, i-1, 'a');
            double exp6= probabilty(s, i+1, y-1, 'a');
            double exp7= probabilty(s, x+1, i-1, 'A');
            double exp8= probabilty(s, i+1, y-1, 'A');
            dp0[x][y]=((exp1+exp2-exp1*exp2)+(exp5*exp8)+(exp6*exp7));
            int num, den;
            foo(dp0[x][y], num, den);
            return (num*inv(den))%MOD;
        }
        else if(ans=='1'){
            double exp1= probabilty(s, x+1, i-1, '1');
            double exp2= probabilty(s, i+1, y-1, '1');
            dp1[x][y]=exp1*exp2;
            return exp1*exp2;
        }
        else if(ans=='a'){
            double exp1= probabilty(s, x+1, i-1, '1');
            double exp2= probabilty(s, i+1, y-1, 'a');
            double exp3= probabilty(s, x+1, i-1, 'a');
            double exp4= probabilty(s, i+1, y-1, '1');
            dpa[x][y]=((exp1*exp2)+(exp3*exp4)+(exp3*exp2));
            return ((exp1*exp2)+(exp3*exp4)+(exp3*exp2));
        }
        else if(ans=='A'){
            double exp1= probabilty(s, x+1, i-1, '1');
            double exp2= probabilty(s, i+1, y-1, 'A');
            double exp3= probabilty(s, x+1, i-1, 'A');
            double exp4= probabilty(s, i+1, y-1, '1');
            dpA[x][y]=((exp1*exp2)+(exp3*exp4)+(exp3*exp2));
            return ((exp1*exp2)+(exp3*exp4)+(exp3*exp2));
        }
    }
    else if(symbol=='|'){
        if(ans=='0'){
            double exp1= probabilty(s, x+1, i-1, '0');
            double exp2= probabilty(s, i+1, y-1, '0');
            dp0[x][y]=exp1*exp2;
            return exp1*exp2;
        }
        else if(ans=='1'){
            double exp1= probabilty(s, x+1, i-1, '1');
            double exp2= probabilty(s, i+1, y-1, '1');
            double exp3= probabilty(s, x+1, i-1, 'a');
            double exp4= probabilty(s, i+1, y-1, 'a');
            double exp5= probabilty(s, x+1, i-1, 'A');
            double exp6= probabilty(s, i+1, y-1, 'A');
            dp1[x][y]=((exp1+exp2-(exp1*exp2))+(exp3*exp6)+(exp4*exp5));
            return ((exp1+exp2-(exp1*exp2))+(exp3*exp6)+(exp4*exp5));
        }
        else if(ans=='a'){
            double exp1= probabilty(s, x+1, i-1, '0');
            double exp2= probabilty(s, i+1, y-1, 'a');
            double exp3= probabilty(s, x+1, i-1, 'a');
            double exp4= probabilty(s, i+1, y-1, '0');
            dpa[x][y]=((exp1*exp2)+(exp3*exp4)+(exp3*exp2));
            return ((exp1*exp2)+(exp3*exp4)+(exp3*exp2));
        }
        else if(ans=='A'){
            double exp1= probabilty(s, x+1, i-1, '0');
            double exp2= probabilty(s, i+1, y-1, 'A');
            double exp3= probabilty(s, x+1, i-1, 'A');
            double exp4= probabilty(s, i+1, y-1, '0');
            dpA[x][y]=((exp1*exp2)+(exp3*exp4)+(exp3*exp2));
            return ((exp1*exp2)+(exp3*exp4)+(exp3*exp2));   
        }
    }
    else if(symbol=='^'){
        if(ans=='0'){
            double exp1= probabilty(s, x+1, i-1, '0');
            double exp2= probabilty(s, i+1, y-1, '0');
            double exp3= probabilty(s, x+1, i-1, 'a');
            double exp4= probabilty(s, i+1, y-1, 'a');
            double exp5= probabilty(s, x+1, i-1, 'A');
            double exp6= probabilty(s, i+1, y-1, 'A');
            double exp7= probabilty(s, x+1, i-1, '1');
            double exp8= probabilty(s, i+1, y-1, '1');
            dp0[x][y]=((exp1*exp2)+(exp3*exp4)+(exp5*exp6)+(exp7*exp8));
            return ((exp1*exp2)+(exp3*exp4)+(exp5*exp6)+(exp7*exp8));
        }
        else if(ans=='1'){
            double exp1= probabilty(s, x+1, i-1, '0');
            double exp2= probabilty(s, i+1, y-1, '1');
            double exp3= probabilty(s, x+1, i-1, '1');
            double exp4= probabilty(s, i+1, y-1, '0');
            double exp5= probabilty(s, x+1, i-1, 'a');
            double exp6= probabilty(s, i+1, y-1, 'A');
            double exp7= probabilty(s, x+1, i-1, 'A');
            double exp8= probabilty(s, i+1, y-1, 'a');
            dp1[x][y]=((exp1*exp2)+(exp3*exp4)+(exp5*exp6)+(exp7*exp8));
            return ((exp1*exp2)+(exp3*exp4)+(exp5*exp6)+(exp7*exp8));
        }
        else if(ans=='a'){
            double exp1= probabilty(s, x+1, i-1, '0');
            double exp2= probabilty(s, i+1, y-1, 'a');
            double exp3= probabilty(s, x+1, i-1, 'a');
            double exp4= probabilty(s, i+1, y-1, '0');
            double exp5= probabilty(s, x+1, i-1, '1');
            double exp6= probabilty(s, i+1, y-1, 'A');
            double exp7= probabilty(s, x+1, i-1, 'A');
            double exp8= probabilty(s, i+1, y-1, '1');
            dpa[x][y]=((exp1*exp2)+(exp3*exp4)+(exp5*exp6)+(exp7*exp8));
            return ((exp1*exp2)+(exp3*exp4)+(exp5*exp6)+(exp7*exp8));
        }
        else if(ans=='A'){
            double exp1= probabilty(s, x+1, i-1, '0');
            double exp2= probabilty(s, i+1, y-1, 'A');
            double exp3= probabilty(s, x+1, i-1, 'A');
            double exp4= probabilty(s, i+1, y-1, '0');
            double exp5= probabilty(s, x+1, i-1, '1');
            double exp6= probabilty(s, i+1, y-1, 'a');
            double exp7= probabilty(s, x+1, i-1, 'a');
            double exp8= probabilty(s, i+1, y-1, '1');
            dpA[x][y]=((exp1*exp2)+(exp3*exp4)+(exp5*exp6)+(exp7*exp8));
            return ((exp1*exp2)+(exp3*exp4)+(exp5*exp6)+(exp7*exp8));
        }
    }

}



int32_t main(){
    sm25official();
    w(t){
        memset(dp0, 0, sizeof(dp0));
        memset(dp1, 0, sizeof(dp1));
        memset(dpa, 0, sizeof(dpa));
        memset(dpA, 0, sizeof(dpA));
        string s;
        cin>>s;
        double ans0= probabilty(s, 0, s.length()-1, '0');
        double ans1= probabilty(s, 0, s.length()-1, '1');
        double ansa= probabilty(s, 0, s.length()-1, 'a');
        double ansA= probabilty(s, 0, s.length()-1, 'A');

        cout<<ans0<<endl;
        

        // int num0,den0,num1,den1,numa,dena,numA,denA;
        // foo(ans0, num0, den0);
        // foo(ans1, num1, den1);
        // foo(ansa, numa, dena);
        // foo(ansA, numA, denA);
        // cout<<num0<<"/"<<den0<<endl;
        // cout<<num1<<"/"<<den1<<endl;
        // cout<<numa<<"/"<<dena<<endl;
        // cout<<numA<<"/"<<denA<<endl;

        // int final0=modDivide(num0, den0, m);
        // int final1=modDivide(num1, den1, m);
        // int finala=modDivide(numa, dena, m);
        // int finalA=modDivide(numA, denA, m);
        // cout<<final0<<" "<<final1<<" "<<finala<<" "<<finalA<<endl;
    }

    return 0;
}


