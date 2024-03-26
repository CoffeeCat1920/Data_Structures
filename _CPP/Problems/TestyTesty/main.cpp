#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

  vector<int> sortArray( vector<int> nums ) {

    int size = nums.size();

    for ( int i = 0; i < size; i++ ) {
      
      for ( int j = i; j < size; j++ ) {
        
        if ( nums[i] > nums[j] ) {
          
          int temp = nums[i];
          nums[i] = nums[j];
          nums[j] = temp;

        }

      }

    }
    
    return nums;

  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    float result = 0;

    nums1.insert( nums1.end(), nums2.begin(), nums2.end() );   

    nums1 = sortArray( nums1 );

    if ( nums1.size() % 2 != 0 ) {
      
      result = nums1[ int( nums1.size()/2 ) ]; 

    }
    else {

      result =  ( float ( nums1[ nums1.size()/2 ] ) + float ( nums1[ ( nums1.size()/2 ) - 1 ] ) )  / 2 ;
      
    }

    return result;

  }

};

int main (int argc, char *argv[]) {
  

  Solution solution;

  vector<int> nums1 = { 1, 2 };
  vector<int> nums2 = { 3, 4 };

  std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;

  return 0;
}
