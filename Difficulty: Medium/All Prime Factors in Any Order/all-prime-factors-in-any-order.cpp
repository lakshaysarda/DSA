class Solution {
  public:
    vector<int> primeFactors(int n) {
vector<int>ans;        
        // code here
        while(n%2==0){
            ans.push_back(2);
            n=n/2;
        } 
        
        for ( int i =3 ; i*i <=n ; i+=2){
            if (n%i==0){
                
                while(n%i==0){
                    n=n/i;
                    ans.push_back(i);
                }
            }
        } 
        if ( n>1) ans.push_back(n);
        return ans ;
    }
};
