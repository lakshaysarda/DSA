



class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

      sort ( prices.rbegin(),prices.rend());
      sort ( discounts.rbegin(),discounts.rend());
      double ans =0;
      int l=0;
      int r=0;

   while(l<prices.size() && r<discounts.size()){
            double a = double ((100-discounts[r]) * prices[l])/100;
            ans+=a;
            l++;
            r++;
      
    } 
      while(l<prices.size()){
        ans += prices[l];
        l++;
    }

    return ans ;
    }
};