class Solution {
public:
 
bool checkPalindrome(string s)
{
int st=0;
int e= s.size()-1;
while (st < e){
if ( s[st] != s[e]){
return 0;

       }
       else {
           st++;
           e--;
       }
   }
   return 1;


}

bool ifValid ( char ch ) {

if ( (ch >= 'a' && ch <= 'z') ||  ( ch >= 'A' && ch <= 'Z') || ( ch >= '0' && ch <= '9')) {
return 1;

} else {
return 0;
}
}

char tolowescase( char ch  ){
if ( (ch >= 'a' && ch <= 'z' ) || (ch >= '0' && ch <= '9')){


return ch ;


} else {
char x =  ch -'A' +'a';
return x;

}
}
bool isPalindrome ( string s ){

string temp = "";
for ( int j=0; j < s.size() ; j++) {


if( ifValid ( s[j] )){
    temp.push_back(s[j]) ;
}


}
// convert to lowercase

for ( int i=0; i < temp.size() ; i ++){

temp[i] = tolowescase( temp[i]  ) ;
}

return checkPalindrome(temp);
}

   
};