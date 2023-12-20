bool isPowerOfTwo(int n)
{	
    if((n&n-1)==0) return true;

    return false;
}