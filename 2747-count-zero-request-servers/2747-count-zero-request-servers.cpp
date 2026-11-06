class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int k=queries.size();

        for(int i=0;i<k;i++){
            int ind=-(i+1);
            logs.push_back({ind,queries[i]});
        }

        logs.push_back({0,0});
        sort(logs.begin(),logs.end(),[&](vector<int> &a, vector<int> &b){
            if(a[1]!=b[1]) return a[1]<b[1];
            return a[0]>b[0];
        });

        // for(auto it : logs) cout << it[0] << " " << it[1] << endl;
        unordered_map<int,int> freq;

        int l=0,r=1;
        int server=0;

        vector<int> ans(k,0);
        while(r<logs.size()){
            int server_id=logs[r][0];
            
            if(server_id>0){
                freq[server_id]++;
                if(freq[server_id]==1) server++;
            }
            
            while(l<r && logs[r][1]-logs[l][1]>x){
                if(logs[l][0]>0){
                    freq[logs[l][0]]--;
                    if(freq[logs[l][0]]==0) server--;
                }
                l++;
            }

            if(server_id<0){
                ans[-server_id-1]=n-server;
            }
            
            r++;
        }

        return ans;
    }
};