class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> stor;
	int n = nums.size();
	bool isBreak = true;
	int reminder = 0;
	for (int i = 0; i<n && isBreak; i++)
	{
		reminder = target - nums[i];
		for (int index = i; index<n && isBreak; index++)
		{
			if (nums[index] == reminder && index!=i)
			{
				stor.push_back(i);
				stor.push_back(index);
               // cout<<nums[0]<<endl;
                isBreak = false;
			}
		}
	}
	return stor;
        
        
}
};