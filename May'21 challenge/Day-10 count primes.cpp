class Solution {
public:
    int countPrimes(int n) {
         if(n==0 || n==1 || n==2) return 0; 
       bool arr[n+1]; 
       memset(arr, 1, sizeof arr); 
       int ans=0; 
       arr[0]=0; 
       arr[1]=0; 
       for(int i=2; i<sqrt(n); i++) 
          if(arr[i]) 
            for(int j=i*i; j<n; j+=i) 
                arr[j]=0; 
       
       for(int i=0; i<n; i++) 
            if(arr[i]) 
                ans++; 
       
       return ans; 
    }
};
