// https://leetcode.com/problems/reducing-dishes/description/

class Solution {
public:
    int dp[501][501] ; 
    int f(vector<int>& nums, int i, int time){
        //base case
        if(i==nums.size()) return 0 ;

        if(dp[i][time]!=-1) return dp[i][time]; 

        //recursive case
        return dp[i][time] =  max((time+1)*nums[i] + f(nums, i+1, time+1) , f(nums, i+1,time) );
        // (time+1)*nums[i] + f(nums, i+1, time+1) -> cooked ith dish
        // f(nums, i+1,time) -> not cooking ith dish 
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp, -1, sizeof(dp)) ;
        sort(satisfaction.begin(), satisfaction.end()); 
        // in any case if we have to consider negative we like to put it at last so sort
        return f(satisfaction, 0, 0);     
    }
};


/* APP2 */
/**
 * @brief -> sort of greedy approach
 * sort the array
 * accumulate as many positive as possible 
 * then we would go backward 
 */
class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (satisfaction[i] >= 0)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
            return 0;
        int maxPos = 0, sumPos = 0;
        // maxPositive -> maxAnswer attainable
        // sumPos -> sum of satisfaction levels attainable after index
        for (int j = index; j < n; j++)
        {
            maxPos += (j - index + 1) * satisfaction[j];
            sumPos += satisfaction[j];
        }
        // now go backwards
        index--;
        while (sumPos > 0 && index >= 0)
        {
            // as we start considering back negative elements
            // each time we consider a negative 
            // we add sumPos to it 
            int temp = maxPos + sumPos + satisfaction[index];
            sumPos += satisfaction[index];
            if (temp > maxPos)
            {
                maxPos = temp;
            }
            else
            {
                break;
            }
            index--;
        }

        return maxPos;
    }
};
