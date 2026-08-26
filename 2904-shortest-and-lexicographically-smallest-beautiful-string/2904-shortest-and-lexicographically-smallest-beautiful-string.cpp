class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int left=0;
        int ones=0;
        int bestleft=-1;
        int bestlen=INT_MAX;
        for(int right=0; right<n; right++){
            if(s[right]=='1'){
                ones++;
            }
            while(ones>k){
                if(s[left]=='1'){
                    ones--;
                    
                }
                left++;
            }
            while(ones==k && left<right && s[left]=='0'){
                left++;
            }
            if(ones==k){
                int currlen=right-left+1;
                if(currlen<bestlen){
                    bestlen=currlen;
                    bestleft=left;
                }
                if(currlen==bestlen){
                    string curr=s.substr(left,right-left+1);
                    string best=s.substr(bestleft,right-bestleft+1);
                    if(curr<best){
                        bestleft=left;
                    }
                }
            }
        }
        if(bestleft==-1){
            return "";
        }
        return s.substr(bestleft,bestlen);
    }
};