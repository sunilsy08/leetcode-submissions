#include<bits/stdc++.h>
class Solution {
public:

    
    
    
    int romanToInt(string s) {
        unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
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