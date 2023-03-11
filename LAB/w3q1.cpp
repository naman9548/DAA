#include<iostream>
using namespace std;
void selection_sort(int a[],int size){
    int key,t,c=0,s=0;
    for(int i=1;i<size;i++){
        int j=i-1;
        key=a[i];
        while(j>=0&&a[j]>key){
            
            a[j+1]=a[j];
            j--;
            c++;
            s++;
        }
        a[j+1]=key;
        s++;
    }
    cout<<"Comparisions:"<<c<<endl<<"Shifts:"<<s<<endl;
}
int main(){
    int arr[100],size,t;
    cout<<"Enter number of test cases:";
    cin>>t;
    while(t--){
        cout<<"Enter array size:";
        cin>>size;
        cout<<"Enter array elements:";
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
        selection_sort(arr,size);
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
