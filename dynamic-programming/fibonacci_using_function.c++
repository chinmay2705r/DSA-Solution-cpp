// Problem: Fibonacci Series
// Difficulty: Easy

#include<iostream>
using namespace std;

int fibonacci(int n){

    int a=0;
    int b =1;

    cout<<  a << " " << b <<endl;

    for(int  i =0;i<=n;i++){
        int nextnumber = a+b;
        cout<<nextnumber<<endl;

        a=b;
        b= nextnumber;
    }
    return a,b;

}

int main(){

    int a = 0;
    int b = 1;

    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
     
    int ans = fibonacci(n);
    cout<<"The fibonacci series from 1 to n  is "<< ans <<endl;
    
}
