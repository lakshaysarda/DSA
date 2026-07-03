class Solution {
  public:
    vector<string> powerSet(string &s) {
        int n = s.size();
        vector<string>ans;
        ans.push_back("");
        
       
       for ( int i =1 ; i < pow(2,n); i++){
           string sub ="";
           
           for( int j = 0 ; j< n ;j++){
               
               if(i & (1<<j)){
                   sub += s[j];
               }
           }
           ans.push_back(sub);
           
       }
       sort(ans.begin(),ans.end());
        return ans;
    }
};