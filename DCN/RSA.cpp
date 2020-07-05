#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>keyPairs;
void generateKeyPairs(int z){

    int e = 2;
    while(e<z){
        if(__gcd(e,z)==1){
            int d = 1;
            while(d<1000){
                int temp = fmod(d*e,z);
                if(temp==1){
                    keyPairs.push_back({e,d});
                    break;
                }else{
                    d++;
                }
            }
        }
        e++;
    }
}

string getEncryptedMessage(string message,int encryptKey, int n){
    vector<int>msg;
    for(int i=0;i<message.size();i++){
        int temp = message[i]-'a';
        msg.push_back(temp+1);
    }

    string encryptedMessage;
    for(int i=0;i<msg.size();i++){
        int eM = pow(msg[i],encryptKey);
        eM = fmod(eM,n);
        char temp = eM;

        encryptedMessage+=temp;

    }
    return encryptedMessage;

}
string getDecryptedMessage(string message,int decryptKey, int n){
    vector<int>msg;
    for(int i=0;i<message.size();i++){
        int temp = message[i];
        msg.push_back(temp);
    }

    string decryptedMessage;
    for(int i=0;i<msg.size();i++){

        double m=1;
        for (int j = 0; j < decryptKey; j++) {
            m*=msg[i];
            m=fmod(m,n);
        }
        m=fmod(m,n);
        char dM = (m+96);
        decryptedMessage+=dM;

    }
    return decryptedMessage;

}

bool isPrime(int p){
    if(p==1){
        return 0;
    }
    if(p==3||p==2){
        return 1;
    }
    if(p%2==0||p%3==0){
        return 0;
    }
    for(int i=5;i*i<=p;i+=6){
        if(i%2==0||(i+2)%2==0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int p,q;
    cout<<"Enter Two Prime Numbers:"<<endl;
    cin>>p>>q;
    string message;
    cout<<"Enter Message:"<<endl;
    cin>>message;

    if(!isPrime(p)||!isPrime(q)){
        cout<<"Wrong Input : Input is not prime";
        return 0;
    }

    int n = p*q;
    int z = (p-1)*(q-1);

    generateKeyPairs(z);
    cout<<"e and d are: "<<endl;
    for(int i=0;i<keyPairs.size();i++){
        cout<<keyPairs[i].first<<" "<<keyPairs[i].second<<endl;
    }

    int encryptKey = keyPairs[0].first;
    int decryptKey = keyPairs[0].second;
    string encryptedMessage = getEncryptedMessage(message,encryptKey,n);
    cout<<"EncryptedMessage: "<<encryptedMessage<<endl;
    string decryptedMessage = getDecryptedMessage(encryptedMessage,decryptKey,n);
    cout<<"DecryptedMessage: "<<decryptedMessage;


}





// input
Enter Two Prime Numbers:
5 7
Enter Message:
f
//output
e and d are:
5 5
7 7
11 11
13 13
17 17
19 19
23 23
EncryptedMessage: ♠
DecryptedMessage: f
