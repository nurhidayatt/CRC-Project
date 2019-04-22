#include <iostream>
using namespace std;

int main() {
    string msg,crc,encoded="",send;
    cout<<"Pesan M = ";
    getline(cin,msg);
    cout<<"Polinominal P = ";
    getline(cin,crc);
    
    int m = msg.length(),n = crc.length();
    encoded+=msg;
    for(int i=1;i<=n-1;i++)
        encoded+="0";
    for(int i=0;i<=encoded.length()-n;i++){
        for(int j=0;j<n;j++){
            encoded[i+j]=encoded[i+j]==crc[j]? '0':'1';
            for(;i<encoded.length() && encoded[i]!='1';i++);
        }
    }
    cout<<msg+encoded.substr(encoded.length()-n+1);
    send=msg+encoded.substr(encoded.length()-n+1);
    for(int i=0;i<=send.length()-n;i++){
        for(int j=0;j<n;j++){
            send[i+j]=send[i+j]==crc[j]? '0':'1';
            for(;i<send.length() && send[i]!='1';i++);
        }
    }
    cout<<"\n"<<send.substr(send.length()-n+1);
    if(send.substr(send.length()-n+1)=="00"){
        cout<<"\nNo error";
    }else{
        cout<<"\nError";
    }
    return 0;
}
