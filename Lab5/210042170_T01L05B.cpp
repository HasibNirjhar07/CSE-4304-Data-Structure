#include <bits/stdc++.h>
using namespace std;
void Swap_it(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[],int n,int i){
            int smallest=i;
            if((2*i+1)<n && arr[2*i+1]<arr[smallest]){
                smallest=2*i+1;
            }
            if((2*i+2)<n && arr[2*i+2]<arr[smallest]){
                smallest=2*i+2;
            }
            if(smallest!=i){
                Swap_it(&arr[i],&arr[smallest]);
                heapify(arr,n,smallest);
            }
}
void build_min_heap(int arr[],int n){
        for(int i=(n/2)-1;i>=0;i--){
            heapify(arr,n,i);
        }
}

void Min_heap_insert(int arr[],int n,int input){
        arr[n]=input;
        n++;
        build_min_heap(arr,n);
}

int heap_minimum(int arr[],int n){
        return arr[0];
}

int extract_heap_minimum(int arr[],int n){
            int k=arr[0];
            Swap_it(&arr[0],&arr[n-1]);
            build_min_heap(arr,n-1);
            return k;
}

void heap_decrease_key(int arr[],int i,int key){
        if(key>arr[i]){
            cout<<"Error";
        }
        arr[i]=key;
        while(i>0 && arr[(i-1)/2]>arr[i]){
            Swap_it(&arr[i],&arr[(i-1)/2]);
            i=(i-1)/2;
        }
}

void heap_increase_key(int arr[],int i,int key){
        if(key<arr[i]){
            cout<<"Error";
        }
        arr[i]=key;
        heapify(arr,i,key);
}
int main(){
        int arr[100];
        int i;
        for(i=0;;i++){
                int k;
                cin>>k;
                if(k==-1)
                  break;
                else 
                  arr[i]=k;
            }
            
        build_min_heap(arr,i);
        for(int j=0;j<i;j++){
            cout<<arr[j]<<" ";
        }
        int k=heap_minimum(arr,i);
        int r=extract_heap_minimum(arr,i);
        cout<<k<<" "<<r<<" "<<'\n';
        i--;
        for(int j=0;j<i;j++){
            cout<<arr[j]<<" ";
        }
        cout<<'\n';
        
        int rk = 40;
        Min_heap_insert(arr,i,rk);
        for(int j=0;j<i+1;j++){
            cout<<arr[j]<<" ";
        }
        cout<<'\n';
}