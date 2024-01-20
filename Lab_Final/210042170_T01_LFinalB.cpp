//  You are given an array of integers ‘stones’ where ‘storen[i]’ is the weight
//  of the i-th stone.
//  We are playing a game with the stones. On each turn, we choose the heaviest
//  two stones and smash them together. Suppose the heaviest two stones have
//  weights x and y, with x<=y. The result of the smash is:- If x==y, both stones are destroyed.- If x!=y, the stone of weight x is destroyed, and the stone of weight y
//  has a new weight (y-x).
//  At the end of the game, there is at most one stone left. Return the weight of
//  the last remaining stone. If there are no stones left, return 0.
//  2 7 4 1 8 1-1
//  10 10 10 10 10-1
//  10 10 5 10 10 10-1
//  50 30 10 40 20-1
//  50 30 10 40 60 20-1
//  1
//  10
//  5
//  10
//  10
//  10 50 30 10 40 60 20-1 0
//  1 7 5 4 2 2 1 4 8 1-1 1
//  1 7 5 4 2 2 1 4 8-1
//  Combine 7,8. State: (2 4 1 1 1)
//  Combine 2,4. State: (2 1 1 1)
//  Combine 2,1. State: (1 1 1)
//  Combine 1,1. State: (1)
//  That's the value of the last stone.
//  0
//  3 3-1
//  1-1
//  Task 2:
//  0
//  1


#include<iostream>

using namespace std;

int getMax(int x[], int size){

    int max=0;

    for(int i=0; i< size ; i++){

        if
    }


}


int getSecondMax(){



}



int getLastStone(){



    //recursively get the first and second max

    //get the diff

    //loop it untill the last element


}






int main(){


    int input[]={};

    int size=


    

}

