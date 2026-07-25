class Solution {
  public:
  
  
  struct Meeting {
    int start;
    int end;
    int index;
};

 static bool comp(Meeting a,Meeting b){
      if (a.end == b.end)
            return a.index < b.index;
      return a.end < b.end;
  } 
   vector<int> maxMeetings(vector<int> &s, vector<int> &f) {

   
  
   
  
   
       
      
  vector<Meeting> meetings;
  int n = s.size();

    for (int i = 0; i < n; i++) {
    meetings.push_back({s[i], f[i], i + 1}); // 1-based index
    } 
    sort ( meetings.begin(),meetings.end(),comp);
    
         
         int freetime = meetings[0].end;
         int count =1;
         vector<int> ans;
ans.push_back(meetings[0].index);
    
    for ( int i =1; i < n ;i++){
        if ( meetings[i].start > freetime ){
            count ++;
            freetime = meetings[i].end;
           ans.push_back(meetings[i].index);
        } 
        
        
        
    }
    sort(ans.begin(), ans.end());
return ans;
    return ans;
    }
};