#include <map>
#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map <char,int> omap;
        int max_length=0,length=0,change_loc=0,starting_loc=0;
        if(s.length()==0) return 0;
        if(s.length() == 1 )return 1;
        for(int i = 0;i<s.length();){
            cout<<"i "<<i<<"  "<<s[i]<<endl;;
            if( omap.find(s[i]) != omap.end() ){
                if(omap[s[i]] != i ){
                    
                    change_loc = omap[s[i]];
                    omap[s[i]]  = i;
                    if(change_loc >= starting_loc){
                          i = change_loc; 
                          starting_loc = i+1;
                          length=0;
                          
                    }
                    else{
                        length++;
                    }
                    if(length>max_length) max_length = length;
                    
                    
                }
                else{
                    length++;
                }
            }
            else{
                omap[s[i]] = i;
                length++;
            }
            if(length>max_length) max_length = length;
            
            cout<<" map "<<omap[s[i]]<<"length"<<length<<endl;
            i++;
        }
        return max_length;
    }
};
int main(){
    Solution hi;
    hi.lengthOfLongestSubstring("tmmzuxt");
    return 0;
}