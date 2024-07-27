class Solution{
  public:
    int countMin(string str){
      string st=str;
        reverse(st.begin(),st.end());
        int n=str.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            
            for(int j=n-1;j>=0;j--){
                
                int ans=0;
                if(str[i]==st[j])
                   ans=1+dp[i+1][j+1];
                 else{
                    ans=max(ans,dp[i+1][j]);
                    ans=max(ans,dp[i][j+1]);
                    }
                dp[i][j]=ans;
            }
        }
        
        return str.length()-dp[0][0];
    }
};