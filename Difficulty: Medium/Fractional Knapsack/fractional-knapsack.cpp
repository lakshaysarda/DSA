class Solution {
  public:
  static bool comp(pair<int,int> &a, pair<int,int> &b) {

    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;

    return r1 > r2;
}
      
      
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int,int>>v;
        
        for ( int i =0 ; i<wt.size() ;i++){
          v.push_back({val[i],wt[i]});  
        } 
        
        sort ( v.begin(),v.end(),comp);
        double ans =0;
        
        for ( int i =0 ; i < v.size() ;i++){
            
            if (v[i].second <= capacity ){
                ans+=v[i].first;
                capacity-=v[i].second;
            }
                
                else if (v[i].second > capacity ){
                    ans += ((double)v[i].first / v[i].second) * capacity;
                    break;
                }
                
            }
         
        return ans ;
        
        
    }
};
