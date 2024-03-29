class Solution {
public:
  int getMaxLen(vector<int>& nums) {
        int mx=0;  //will store result
        int sz=nums.size();
        for(int i=0;i<sz;i++)
        {     
              int n_s=-1,n_e=-1,n=0,p=0,j;
         
              //n_s ->to store starting of negatiive number
              //n_e ->to store end of negative number
              //n   ->count of negative number
              //p   ->count of positive number
         
         //We will iterate until we found zero 
              for(j=i;j<sz;j++)
              {    
                  if(nums[j]<0) n++;
                  if(nums[j]>0)p++;
                  if(nums[j]<0&&n_s==-1) { n_s=j;} //store starting index of negative number
                  if(nums[j]<0) n_e=j;             //store end index of negative number
                  if(nums[j]==0) break;          //subarray ends now because after that all the product will be 0  
              }
             // cout<<i<<" "<<n_s<<" "<<n_e<<" "<<j<<" : "<<n<<" "<<p<<"\n";
         
             /* Here only two possibilities */
            
             /* 1.if we have even number of negative 
                multiply of even negative numbers are positive, so add both n and p and take max of res 
             */
             if(n%2==0) mx=max(mx,n+p);
          
             /*
               2.if we have negative numbers and count of these are odd ,
               Lets say subarray -> {1,2,-1,2,3,1,-1,2,3,4,-1,2,3} , I am taking 3 negative numbers
               We know that odd-1 = even
               We have stored starting of negative number index in n_s
               and end of negative number index in n_e
               
               For this example n_s=2 , n_e = 10
               So here two cases, if we left a negative number of n_s index then 
               total count of negative numbers will be odd-1=even negative numbers 
               i.e subarray will be {2,3,1,-1,2,3,4,-1,2,3}
               
               Or if we left a negative number of n_e index than
               total count of negative numbers will be odd-1=even negative numbers 
               i.e subarray will be {1,2,-1,2,3,1,-1,2,3,4}
               
               So max length will be any one from these two only
               So we will take max length of these two
             */
             if(n%2==1)
             {
                  mx=max(j-n_s-1,mx);
                  mx=max(n_e-i,mx);
             }
             //cout<<mx<<" ";
           i=j; //now starting from new subarray
        }
         
        
        return mx;
    }
};