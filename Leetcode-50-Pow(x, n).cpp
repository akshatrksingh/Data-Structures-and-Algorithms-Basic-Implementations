/*
class Solution 
{
    public:
        double myPow(double x, int n) 
        {
            if (n == 0)
                return 1;
            double res = myPow(x, n/2);
            if (n % 2 == 1)                // Wrong for negative n
                return  x*res*res;         // Wrong for negative n
            else
                return res*res;
        }
};
*/
class Solution 
{
    public:
        double myPow(double x, int n) 
        {
            if (n == 0)
                return 1;
            double res = myPow(x, n/2);
            if (n % 2)    
                return (n < 0)? 1/x*res*res: x*res*res;
            else
                return res*res;
        }
};
