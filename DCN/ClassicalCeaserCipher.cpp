#include<bits/stdc++.h>
using namespace std;

string encrypt(string message,int key){
    string encryptedMessage;
    for(int i=0;i<message.size();i++){
        int msg = message[i];
        if(msg>=97&&msg<=122){
            msg = msg+key;
            if(msg>122){
                msg=97+((msg-122)%26)-1;
            }
        }
        if(msg>=65&&msg<=90){
            msg = msg+key;
            if(msg>90){
                msg=65+((msg-90)%26)-1;
            }
        }
        char temp = msg;
        encryptedMessage+=temp;

    }
    return encryptedMessage;
}
string decrypt(string message,int key){
    string decryptedMessage;
    for(int i=0;i<message.size();i++){
        int msg = message[i];
        if(msg>=97&&msg<=122){
            msg = msg-key;
            if(msg<97){
                msg=((msg-97)%26)+122+1;
            }
        }
        if(msg>=65&&msg<=90){
            msg = msg-key;
            if(msg<65){
                msg=90+((msg-65)%26)+1;
            }
        }
        char temp = msg;
        decryptedMessage+=temp;
    }
    return decryptedMessage;
}

int main(){
    cout<<"Enter Message:"<<endl;
    string message;
    cin>>message;
    int key;
    cout<<"Enter Key:"<<endl;
    cin>>key;
    string encryptedMessage = encrypt(message,key);
    string decryptedMessage = decrypt(encryptedMessage,key);
    cout<<"EncryptedMessage is :"<<encryptedMessage<<endl;
    cout<<"DecryptedMessage is :"<<decryptedMessage<<endl;

}




//I/O
Enter Message:
HelloPshbbwebdT
Enter Key:
45
EncryptedMessage is :AxeehIlauupxuwM
DecryptedMessage is :HelloPshbbwebdT
