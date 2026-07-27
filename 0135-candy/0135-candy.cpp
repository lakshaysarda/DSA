class Solution {
public:
    int candy(vector<int>& ratings) {
        // solve wrt left neighbours 
        int sum =0;
        int n =ratings.size();
        vector<int>left(n,1);
        

        for ( int i =1; i < ratings.size() ;i++){
            

            

            if (ratings[i]>ratings[i-1]){
                left[i] = left[i-1] + 1;
            } 
        }

        
            
            // solve wrt to right neighbours 

             vector<int>right(n,1);
        

        for ( int i =ratings.size()-2; i >=0 ;i--){
            

           

             if (ratings[i]>ratings[i+1]){
                 right[i] = right[i+1] + 1;
            } 



        } 
        

        for ( int i =0 ; i < n ;i++){
            sum+=max(left[i],right[i]);
        }

        return sum ;
        }
    
};