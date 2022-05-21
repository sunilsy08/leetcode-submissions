class Solution {
public:
unordered_map<char, int> m = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
    
    int romanToInt(string s) {
        if(s.length() == 0) return 0;
        
        int num = 0;
        
        int i = 0;
        while(i <s.length()-1) {
            
            if(m[s[i]] < m[s[i+1]]){
                num -= m[s[i]];
            }
            else 
                num += m[s[i]];
            
            i++;
                
        }
        num += m[s[s.length()-1]];
        
        return num;
    }
};