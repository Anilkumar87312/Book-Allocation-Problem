#include <iostream>
#include <algorithm>
using namespace std;
bool isposible (int arr[],int n,int m, int mid){
    int studentcout=1;
    int pagesum=0;
    for (int i=0;i<n;i++){
        if(pagesum+arr[i]<=mid){
            pagesum+=arr[i];
        }
        else {
            studentcout++;
            if (studentcout>m||arr[i]>mid){
                return false;
            }
            pagesum = arr[i];

        }
    }
    return true;
}
int main(){
    int m;
    cout<<"enter number of student: ";
    cin>>m;
    int n;
    cout<<"enter number of book: ";
    cin>>n;
    if (m > n) {
    cout << "Allocation not possible";
    return 0;
}

    int* arr= new int[n];
    cout<< "enter number of pages in book: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
    }
    int start = *max_element(arr, arr + n);
    int end = sum;
    int ans=-1;
    while (start<=end){
        int mid = start +(end -start)/2;
        if (isposible(arr,n,m,mid)){
            ans = mid ;
            end = mid-1;
        }
        else {
            start= mid +1;
        }
    }
    cout<<"answer: "<<ans;

   delete[] arr;
    arr = nullptr;

return 0;
}
