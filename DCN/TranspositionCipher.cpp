#include<bits/stdc++.h>
using namespace std;


string encrypt(string key,string message){

    //mappedKey for priority wise column selection
    vector<pair<int,int>>temp;
    vector<int>mappedKey;
    for(int i=0;i<key.size();i++){
        temp.push_back({key[i]-'A',i});
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
        mappedKey.push_back(temp[i].second);
    }

    string encryptedMessage;
    int col = mappedKey.size();
    int row = message.size()/col;
    if(message.size()%col>0){
        row++;
    }

    char cipher[row][col];
    int k = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;){
            if(k>=message.size()){
                cipher[i][j]='_';
                j++;
            }
            if(isalpha(message[k])||message[k]==' '){
                cipher[i][j]=message[k];
                j++;
            }
            k++;
        }
    }
    for(int j=0;j<mappedKey.size();j++){
        for(int i=0;i<row;i++){
            if(isalpha(cipher[i][mappedKey[j]])||cipher[i][mappedKey[j]]==' '||cipher[i][mappedKey[j]]=='_'){
                encryptedMessage+=cipher[i][mappedKey[j]];
            }
        }
    }
    return encryptedMessage;
}

string decrypt(string key,string cipher){

    //mappedKey for priority wise column selection
    vector<pair<int,int>>temp;
    vector<int>mappedKey;
    for(int i=0;i<key.size();i++){
        temp.push_back({key[i]-'A',i});
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
        mappedKey.push_back(temp[i].second);
    }
    string decryptedMessage;

    int col = mappedKey.size();

    int row = cipher.size()/col;
    char cipherMat[row][col];



    int k = 0;
    for(int i=0;i<mappedKey.size();i++){
        for(int j=0;j<row;j++){
          cipherMat[j][mappedKey[i]]=cipher[k];
          k++;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(cipherMat[i][j]=='_'){
                break;
            }
            decryptedMessage += cipherMat[i][j];
        }
    }



    return decryptedMessage;
}

int main(){
    string key,message;
    cout<<"Enter Key:"<<endl;
    cin>>key;
    cout<<"Enter Message:"<<endl;
    cin>>message;


    string encryptedMessage = encrypt(key,message);
    cout<<"EncryptedMessage is: "<<encryptedMessage<<endl;


    string decryptedMessage = decrypt(key,encryptedMessage);
    cout<<"DecryptedMessage is: "<<decryptedMessage<<endl;


}


//I/O
Enter Key:
JKJBSAD
Enter Message:
sdnjsajdjvnvavaknvnarnvanlvn
EncryptedMessage is: aaavjnvnjvrnsdannvnadjkvsvnl
DecryptedMessage is: sdnjsajdjvnvavaknvnarnvanlvn
