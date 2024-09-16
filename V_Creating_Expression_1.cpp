#include<bits/stdc++.h>
using namespace std;
bool ans = {false};
int expression(int n,int a[],int x){
    int sum = 0;
    if(n == 0 || x == 0) return sum;
    int op1 = sum + a[n-1] +expression(n-1,a,x);
    
    int op2= sum - a[n-1] + expression(n-1,a,x);
    
    if(op1 == x || op2 == x) ans = true;
    // else ans = false;
    // return sum ;
}
int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    expression(n,a,x);
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
    return 0;
}