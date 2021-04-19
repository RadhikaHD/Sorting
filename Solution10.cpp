class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1, len2;
    len1 = nums1.size();
    len2 = nums2.size();

    vector<int> result;
    int resultLength;

    int i = 0;
    int j = 0;

    while ((i < len1) and (j < len2)) {

      if (nums1[i] < nums2[j]) {

        result.push_back(nums1[i]);
        i++;
      } else {

        result.push_back(nums2[j]);
        j++;
      }
    }

    if (i == len1) {
      for (int a = j; a < len2; a++) {
        result.push_back(nums2[a]);
      }
    }

    if (j == len2) {
      for (int a = i; a < len1; a++) {
        result.push_back(nums1[a]);
      }
    }

    resultLength = result.size();

    int medianIndex;
    float median;
    if (resultLength % 2 == 0) {
      medianIndex = resultLength / 2;
      median = (result[medianIndex] + result[medianIndex - 1]) / 2.0;
    } else {
      medianIndex = resultLength / 2;
      median = result[medianIndex];
    }

    return median;
  }
};