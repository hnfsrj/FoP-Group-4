#include <iostream>
using namespace std;
int main(){
int x,i,j,k,l;
char choice,n;
again:
cout<<"Enter the number of rows you want:"<<endl;
cin>>x;

if(x>=1){
    for(i=0;i<x;i++){
        for(j=0;j<=i;j++){
          cout<<j;}
        for(k=1;k<2*(x-i);k++){
          cout<<" ";}
        for(l=i;l>=0;l--){
          cout<<l;}
           cout<<endl;}

    do{
        for(j=0;j<=x;j++){
            cout<<j;}
        for(k=x-1;k>=0;k--){
            cout<<k;}
            cout<<endl;
         i++;}
      while(i<-1);


    for(i=x-1;i>=0;i--){
        for(j=0;j<=i;j++){
          cout<<j;}
        for(k=1;k<2*(x-i);k++){
          cout<<" ";}
        for(l=i;l>=0;l--){
          cout<<l;}
           cout<<endl;}}
else{
    cout<<"Invalid input!"<<endl;
      }

cout<<"Do you want to do it again?\n   Choose 'Y/y' for 'yes' and'N/n' for 'no':"<<endl;
cin>>choice;
    if(choice=='y' ||  choice=='Y')
        goto again;
    else if(choice=='n' ||  choice=='N')
         cout<<"Thank you:)"<<endl;
    else
        cout<<"Invalid choice!"<<endl;



return 0;
}
