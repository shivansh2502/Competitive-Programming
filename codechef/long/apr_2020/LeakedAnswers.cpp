#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;

 

bool compart(pair<int, int> a1, pair<int, int> b1){
    return a1.second<b1.second;
}







int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;




    while(t--){



        int n1, m1, k1;
        cin>>n1>>m1>>k1;

        map<int, pair<int, set<int>>> mapsi;
        
        map<int, int> cnt;

        int arr[n1][k1];

        vector<int> vic;








        for(int itt=0;itt<k1;itt++){

            cnt[itt]=0;

        }

        for(int itt=0; itt<n1; itt++){

            mapsi.clear();

            for(int jtt=0; jtt<k1; jtt++){



                cin>>arr[itt][jtt];
                mapsi[arr[itt][jtt]].first++;
                mapsi[arr[itt][jtt]].second.insert(jtt);

            }

            int mi=0;
            int mv=0;
            set<int> mk;

            for(auto jtt: mapsi){
                if(mk.empty()){







                    mv=jtt.first;
                    mk=jtt.second.second;
                    mi=jtt.second.first;

                }
                else{

                    int op=0;
                    int oq=0;
                    int wp=-1;
                    int wq=-1;

                    vector<pair<int, int>> vecti;

                    for(auto i:cnt){
                        vecti.push_back(make_pair(i.first, i.second));
                    }

                    bool concl=false;

                    sort(vecti.begin(), vecti.end(), compart);





                    for(auto ptt:vecti){
                    
                        if(wp >-1 && wp<ptt.second){
                            if(op>oq){

                                concl=true;
                                break;

                            }
                        }

                        if(wq>-1 && wq<ptt.second){
                            if(oq>op){

                                concl=true;
                                mv=jtt.first;
                                mk=jtt.second.second;
                                mi=jtt.second.first;
                                break;

                            }
                        }








                        if(!mk.count(ptt.first) && jtt.second.second.count(ptt.first)){

                            wq= ptt.second;
                            oq++;

                        }

                        else if(mk.count(ptt.first) && !jtt.second.second.count(ptt.first)){

                            wp=ptt.second;
                            op++;

                        }
                    }
                    if(!concl){

                        if(wq!=-1 && wp==-1){

                            mv=jtt.first;
                            mk=jtt.second.second;
                            mi=jtt.second.first;

                        }


                        else if(wq==-1 && wp!=-1 && wq<wp){

                            mv=jtt.first;
                            mk=jtt.second.second;
                            mi=jtt.second.first;

                        }

                        else if(wq==-1 && wp!=-1 && wq<wp){

                            if(oq>op){

                                mv=jtt.first;
                                mk=jtt.second.second;
                                mi=jtt.second.first;

                            }

                        }

                    }
                }
            }





            for(auto ptt:mk){

                cnt[ptt]++;
    
            }
            vic.push_back(mv);
        }








        for(auto itt:vic){

            cout<<itt<<" ";

        }

        cout<<endl;
    }


    return 0;

    
}


