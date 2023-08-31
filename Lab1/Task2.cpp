
// #include<iostream>
// using namespace std;

// int Pair_Count(int Array[], int n, int target)
// {
//     int count = 0;

//     for(int k=0,i=1;i<n;i++)
//     {
//         if(Array[k]+Array[i]==target)
//         {
//             count++;
//         }

//         if(i==n-1)
//         {
//             k++;
//             i=k;
//         }
//     }

//     return count;
// }

// int Find_Pair(int Array[], int n, int target)
// {
//     for(int k=0,i=1;i<n;i++)
//     {
//         if(Array[k]+Array[i]==target)
//         {
//             cout<< "("<<Array[k]<<","<<Array[i]<<")"<<endl;
//             return 0;
//         }

//         if(i==n-1)
//         {
//             k++;
//             i=k;
//         }
//     }
// }

// int main()
// {
//     int size;
//     cout<<"Array size: ";
//     cin >> size;

//     int Array []={0};

//     cout<<"Array Elements: ";
//     for(int i=0; i<size; i++)
//     {
//         cin >> Array[i];
//     }

//     int target;
//     cout<< "target: ";
//     cin >> target;

//     Find_Pair(Array,size,target);

//     cout<<"\n";

//     target= Pair_Count(Array,size,target);

//     cout<<target<<" pairs"<<endl;

//     return 0;
// }


#include<iostream>
using namespace std;
int main()
{
    int val;
    cout<<"Enter the Number: ";
    cin>>val;
    cout<<"\nThe Value is "<<val;
    cout<<endl;
    return 0;
}