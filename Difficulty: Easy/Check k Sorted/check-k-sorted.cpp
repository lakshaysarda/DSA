
class Solution {
  public:
    bool isKSortedArray(vector<int>& arr, int k) {
        vector <int> yes = arr;
        map<int,int>pre;

        for ( int i =0 ; i < arr.size() ;i++){
            pre[arr[i]]=i;
        }

        sort(arr.begin(),arr.end());
        map<int,int>post;


        for ( int i =0 ; i < arr.size() ;i++){
            post[arr[i]]=i;

        } 
        for ( int i =0;i<arr.size();i++){
            if (abs(post[arr[i]] - pre[arr[i]]) > k)
            return false;
        }
        return true;
    }
};
