class Solution {
public:
    int numDecodings(string s) {
        if( s.empty() || s[0] == '0') return 0 ; 
        int prev2 = 1 , prev1 = 1 ;
        for(int i = 0 ; i < s.size() ; i++){
            int current = 0 ; 

            if(s[i] != '0' ){
                current += prev1;
            }
            if( i>0  && s[i-1] != '0' && (s[i-1] - '0') *10 + (s[i] - '0') <=26){
                current +=  prev2;
            }
            prev2 = prev1 ;
            prev1 = current ;
        }
        return prev1;
    }
};
