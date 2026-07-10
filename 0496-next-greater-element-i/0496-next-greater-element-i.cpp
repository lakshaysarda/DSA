class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mpp;
        
        int nge =-1;

        for ( int i = nums2.size()-1 ; i>=0 ;i--){

            while ( !st.empty() && st.top() <= nums2[i]) {
             st.pop();
            }
            

            if ( st.empty()){
                nge = -1;
            }else{
            nge = st.top();
            }
            st.push(nums2[i]);
            

            mpp[nums2[i]]= nge ;
            

        } 
        vector<int>ans;

        for ( int i = 0 ; i <nums1.size() ;i++ ){
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
};