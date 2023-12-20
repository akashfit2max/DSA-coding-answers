// https://www.codingninjas.com/studio/problems/bit-manipulation_8142533?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

int setIthBit(int n, int i){
    int bitMask = 1<<i-1;
    return n | bitMask;
}

 

int clearIthBit(int n, int i){
    int bitMask = ~(1<<i-1);
    return n & bitMask;
}

 

int getIthBit(int n, int i){
    int bitMask = 1<<i-1;
    if((n & bitMask) == 0){
        return 0;
    }else return 1;
}

vector<int> bitManipulation(int num, int i){
    // Write your code here.
    vector<int> ans;
    ans.push_back(getIthBit(num, i));
    ans.push_back(setIthBit(num, i));
    ans.push_back(clearIthBit(num, i));

    return ans;
}