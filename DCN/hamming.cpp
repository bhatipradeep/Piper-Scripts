#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,xorr,x;
    int n = 7;
    int k = 4;
    int m= n-k,r=n-k,c=r-1;
    int arr[7]={0};

    cout<<"Databits: ";
    vector<int>input;
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
    int j=0;
    for(int i=n-1;i>=0;i--){
        if((i+1)!=int(pow(2,c))){
            arr[i]=input[j++];
        }
        else c--;
    }

    for(int i=0;i<r;i++){
        xorr=0;
        for(j=pow(2,i)-1;j<n;j=j+pow(2,i+1)){
            for(l=j;l<=j+int(pow(2,i))-1;l++){
                xorr^=arr[l];
            }
        }
        if(xorr!=0)arr[int(pow(2,i)-1)]=1;
    }

    cout<<"Hamming code:";
    for(int i=n-1;i>=0;i--)cout<<arr[i];
    cout<<endl;



    int arr2[3];
    cout<<"Received Code:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    for(int i =0;i<r;i++){
        xorr=0;
        for(int j=pow(2,i)-1;j<n;j=j+pow(2,i+1)){
            for(l=j;l<=j+int(pow(2,i))-1;l++){
                xorr^=arr[l];
            }
        }
        arr2[i]=xorr;
    }

    int biterror=0;
    for(int i=r-1;i>=0;i--){
        biterror+=arr2[i]*int(pow(2,i));
    }

    if (biterror==0){
        cout<<"Error Detected: No";
    }
    else{
        cout<<"Error Detected: ";
        cout<<"Error bit :"<<biterror<<"\n";


    }
    return 0;
}
