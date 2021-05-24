#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        vector<double> result;
        double median = 0,i=0,j=0;
        int size =0;
        while(size <=  ((total+1)/2)){
            int num;
            if( i < nums1.size() && j < nums2.size() ){
             //   cout<<"i "<<i<<"  j "<<j<<endl;
                if(nums1[i]<nums2[j]){
                  //  cout<<"first array"<<nums1[i]<<endl;
                    result.push_back(nums1[i]);
                    i++;
                    
                }
                else{
                  //  cout<<"second array "<< nums2[j]<<endl;
                    result.push_back(nums2[j]);
                    j++;
                }
                
            }
            else if(i == nums1.size() && j != nums2.size()){
                result.push_back(nums2[j]);
            //    cout<<"second array e"<< nums2[j]<<endl;
                j++;
            }
            else if(j == nums2.size() && i != nums1.size()){
              //  cout<<"first array e"<<nums1[i]<<endl;
                result.push_back(nums1[i]);
                i++;
            }
            size++;
            //cout<<"size"<<size<<endl;
        }
         if(total%2 == 0) {
            //  cout<<(result[(total-1)/2])<<endl;
            //  cout<<(result[(total+1)/2])<<endl;
              median = ((result[(total-1)/2]) + (result[(total+1)/2]))/2;
             // cout<<"median odd"<<median<<endl;
           
         }
          else{
               median = result[total/2];
         //   cout<<"median even"<<median<<endl;
          
          }
        
        return median; 
    }
};
int main(){
    vector<int> hi ,hr;
    hi = {1,3};
    hr ={2};
    Solution obj;
    int result1 = obj.findMedianSortedArrays(hi,hr);
    cout<<"result "<<result1<<endl;
    //obj.print();
    return 0;
}