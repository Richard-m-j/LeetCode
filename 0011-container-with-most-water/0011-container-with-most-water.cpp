class Solution
{
public:
    int volume(int h1, int h2, int w)
    {
        if (h1 > h2)
            return h2 * w;
        return h1 * w;
    }

    int maxArea(vector<int> &height)
    {
        ios_base::sync_with_stdio(false);

        int n = height.size();
        int maxVol = 0;
        int left = 0, right = n - 1;
        int shorter,current;
        while (left < right)
        {
            shorter = min(height[left],height[right]);
            current = volume(height[left], height[right], right - left);
            if (current > maxVol)
                maxVol = current;
            
            if (height[left] < height[right])
                while (left < right && height[left] <= shorter)
                    left++;
            else
                while (left < right && height[right] <= shorter)
                    right--;
        }
        return maxVol;
    }
};
