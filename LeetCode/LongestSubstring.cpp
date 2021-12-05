//滑动窗口及优化
class Solution{
  pubilc:
  int lengthOfLongestSubstring(string s){
    if (s.length()==0)
      return 0;
    unordered_map<char,int>hashTable;
    int maxLength=0;
    int currentLength=0;
    int startIndex=0;
    for(int i=0;i<s.length();i++){
     if( hashTable.find(s[i]==hashTable.end()){
       currentLength++;
       hashTable[s[i]]=i;
     }
          else{
          if(currentLength>maxLength)
          {
            maxLength=currentLength;
          }
         startIndex=max(hashTable[s[i]],startIndex);
          currentLength-i-startIndex;
          hashTable[s[i]]=i;
          }
         }
        if(currentLength>maxLength)
        {
          maxLength=currentLength;
        }
        return maxLength;
        }
   }
        
 
