#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums;
        }
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int> &nums, int left, int mid, int right)
    {
        vector<int> leftArray(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> rightArray(nums.begin() + mid + 1, nums.begin() + right + 1);

        int i = 0, j = 0, k = left;
        while (i < leftArray.size() && j < rightArray.size())
        {
            if (leftArray[i] <= rightArray[j])
            {
                nums[k] = leftArray[i];
                i++;
            }
            else
            {
                nums[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < leftArray.size())
        {
            nums[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < rightArray.size())
        {
            nums[k] = rightArray[j];
            j++;
            k++;
        }
    }
};