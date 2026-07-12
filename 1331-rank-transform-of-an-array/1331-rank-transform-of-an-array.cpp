class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       unordered_map<int,int>mpp;
       if ( arr.empty()) return {};
       int n =  arr.size();
       vector<int>temp=arr;

        

int rank =1;


sort(temp.begin(),temp.end());
mpp[temp[0]]=rank;
//map krdiya 
            for ( int i =1 ; i <n ;i++){
                
                if(temp[i] == temp[i-1]){
                  mpp[temp[i]] = rank;
                } else{
                    rank++;
                   mpp[temp[i]]= rank;
                }
            } 

            //map krdo 
            vector<int>ans(n,0);
              for ( int i =0; i < arr.size() ;i++){
                ans[i]= mpp[arr[i]];


    }
    return ans ;
    }
};