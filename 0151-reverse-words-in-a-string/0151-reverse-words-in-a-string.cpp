class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.size();
        string ans ="";
        int i =0;

   while (i<n){
        while ( s[i]==' ' )
            i++;
             if ( i>=n ) break;

    string word ="";
        while (i<n && s[i]!=' ' ){
            word += s[i];
            i++;
    

        }
        reverse(word.begin(),word.end());

        if ( !ans.empty() ) {
            ans +=  " ";
            ans += word;

        } else {
            ans += word ;
        }
   }
   return ans ; }
};