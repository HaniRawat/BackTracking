//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> store;
    unordered_set<string>mp;
    
    void fun(vector<int>arr,vector<int>v, set<vector<int>>&s, int n, int i){
        
           if(i==n){
               sort(v.begin(),v.end());
               s.insert(v);
               return;
           }
           
           v.push_back(arr[i]);
           fun(arr,v,s,n,i+1);
           v.pop_back();
           fun(arr,v,s,n,i+1);
    }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        set<vector<int>>s;
        
        vector<int>v;
        
        fun(arr,v,s,n,0);
        vector<vector<int>>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends