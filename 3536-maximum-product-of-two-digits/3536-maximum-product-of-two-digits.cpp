class Solution {
public:
    int maxProduct(int n) {
        // store n as digits in an array 
        vector<int>arr;
        int num = n;
        while(num){
            arr.push_back(num%10);
            num/=10;

        } 

        sort(arr.begin(), arr.end());

        int m = arr.size();

        return arr[m - 1] * arr[m - 2];
        
    }
};