class Solution {
public:
    void reverseString(vector<char>& s) {
          reverse(s.begin(),s.end());
          
        

         for (char val: s){
            cout<<val;
         }
    }
};