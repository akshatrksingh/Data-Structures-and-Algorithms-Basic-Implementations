class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{
	    vector<int> v = nums;
	    sort(v.begin(), v.end());
	    int s = 0;
	    map<int, int> pos;
	    for(int i = 0; i < nums.size(); i++)
	    {
	        pos[nums[i]] = i;
	    }
	    for(int i = 0; i < nums.size(); i++)
	    {
	        if(nums[i] == v[i]) continue;
	        s++;
	        int j = nums[i];
	        swap(nums[i], nums[pos[v[i]]]);
            pos[j] = pos[v[i]];
            pos[v[i]] = i;
	    }
	    return s;
	}
};
