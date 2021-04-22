class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int low, int high, int target) {
    int mid, idx, len;

    len = nums.size();

    idx = -1;
    vector<int> result = {-1, -1};

    while (low <= high) {

      mid = (low + high) / 2;

      if (nums[mid] == target) {
        idx = mid;
        break;
      } else if (nums[mid] > target) {
        return searchRange(nums, low, (mid - 1), target);
      } else if (nums[mid] < target) {
        return searchRange(nums, (mid + 1), high, target);
      }
    }

    if (idx != -1) {

      for (int i = idx; i <= (len - 1); i++) {
        if (i != (len - 1)) {

          if (nums[i] != nums[i + 1]) {
            result[1] = i;
            break;
          }
        }
        if (nums[i] == nums[(len - 1)]) {
          result[1] = (len - 1);
          break;
        }
      }

      for (int i = idx; i >= 0; i--) {

        if (i != 0) {
          if (nums[i] != nums[i - 1]) {
            result[0] = i;
            break;
          }
        }
        if (nums[i] == nums[0]) {
          result[0] = 0;
          break;
        }
      }
      return result;
    }
    return result;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    int len;
    vector<int> result = {-1, -1};
    len = nums.size();
    if (len == 0)
      return result;
    else if (len == 1) {
      if (target == nums[0])
        return {0, 0};
      else
        return result;
    } else
      return searchRange(nums, 0, (len - 1), target);
  }
};