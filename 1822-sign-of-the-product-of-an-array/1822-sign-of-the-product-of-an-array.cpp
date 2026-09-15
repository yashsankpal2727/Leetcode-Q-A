class Solution {
public:
    int arraySign(vector<int>& nums) {
      long double x =1;
      for(int i =0 ; i < nums.size();i++)
      {
          x *= nums[i];
      }  

     
    if (x > 0){

        return 1;
    }
    else if (x < 0){
        
        return -1;
    }
    else{
        
        return 0;
    } 

    }
};