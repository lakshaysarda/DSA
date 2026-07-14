class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // sliding window 
        int left =0;
        int maxi = 0;
        int n = cardPoints.size();
        int right = n-1;
        int sum =0;

       //sabse pehle left ko pura chala and ek kam krte and right m add krde 
        while ( left < k ){
         sum += cardPoints[left];
         maxi = max(maxi,sum);
         left++;}

         if (left >= k ){
            int i =0;
        while (right >= n-k){
            sum = sum - cardPoints[left-1-i];
            sum += cardPoints[right];
            maxi = max(sum , maxi);
            right--;
            i++;
        }
         }
        

    return maxi;
    }
};