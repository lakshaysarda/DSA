class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int d=n;
        while(n>0){
            int a = n%10;
          sum += a;
          prod*=a;
          n/=10;
        } 

        return (d%(sum+prod) ==0);
        
    }
};