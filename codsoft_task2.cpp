#include <iostream>
using namespace std;
int main() {
    float a,b,ans;
    char op;
    cout<<"Enter your question:";
    cin>>a>>op>>b;
    switch(op){
        case '+':
        ans=a+b;
        cout<<"Answer is:"<<ans;
        break;
         case '-':
        ans=a-b;
        cout<<"Answer is:"<<ans;
        break;
         case '*':
        ans=a*b;
        cout<<"Answer is:"<<ans;
        break;
         case '/':
        ans=a/b;
        cout<<"Answer is:"<<ans;
        break;
        default:
        cout<<"Wrong input";
    }
    return 0;
}
