class RandomizedSet {
private:
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
                return false;
        }
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        vector<int> :: iterator it;
        for(it=nums.begin();it!=nums.end();)
        {
            if(*it==val)
            {
                it=nums.erase(it);
                return true;
            }
            else
                ++it;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
       int random=rand()%nums.size();
        return nums[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
