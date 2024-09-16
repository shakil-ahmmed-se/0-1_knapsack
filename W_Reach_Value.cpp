#include<bits/stdc++.h>
using namespace std;
// bool ans =false;
bool reachValue(int cur,int n){
    if(cur == n){
        return true;
    }
    if(cur > n){
        return false;
    }
    int op1 = reachValue(cur*10,n);
    int op2 = reachValue(cur*20,n);
    return op1 || op2;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        bool ans = reachValue(1,n);
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}