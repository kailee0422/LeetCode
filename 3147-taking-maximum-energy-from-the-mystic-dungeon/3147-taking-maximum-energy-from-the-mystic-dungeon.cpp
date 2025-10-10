class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int size = energy.size();
        for (int index = size - k - 1;index>=0; index--)
        {
            energy[index] = energy[index] + energy[index + k];
        }
        return *max_element(energy.begin(), energy.end());
    }
};