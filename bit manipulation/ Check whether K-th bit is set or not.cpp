// https://www.codingninjas.com/studio/problems/check-whether-k-th-bit-is-set-or-not_5026446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
bool isKthBitSet(int n, int k)
{
    // Write your code here.
    return (n & (1 << k-1)) > 0 ? true : false;
}