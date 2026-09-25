class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long ans=0;
        sort(intervals.begin(),intervals.end());
        vector<int>start;
        vector<int>end;
        for(int i=0;i<intervals.size();i++){
          start.push_back(intervals[i][0]);
          end.push_back(intervals[i][1]);
        }

        for(int i=0;i<end.size();i++){
            int l=i+1,r=start.size()-1;
            int cnt=0;
            while(l<=r){
                int mid=(l+r)/2;
                if(start[mid]<=end[i]){
                    l=mid+1;
                    
                }
                else{
                    r=mid-1;
                }
            }
            ans+=l-(i+1);
        }

        return ans;
    }
};