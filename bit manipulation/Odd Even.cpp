// https://www.codingninjas.com/studio/problems/odd-even_7993579?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

string oddEven(int N){
    // Write your code here.
    return (N & 1)==1?"odd":"even";
}