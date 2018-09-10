class Solution {
public:
  /**
   * @param array: an integer array
   * @return: the length of the minimum cycle section
   */
  int minimumCycleSection(vector<int> &array) {
    vector<int> next(array.size() + 1);
    int i = 0;
    int j = -1;

    next[0] = -1;

    while (i < array.size()) {
      if (j == -1 || array[i] == array[j]) {
        i += 1;
        j += 1;
        next[i] = j;
      } else {
        j = next[j];
      }
    }
    return i - next[i];
  }
};
