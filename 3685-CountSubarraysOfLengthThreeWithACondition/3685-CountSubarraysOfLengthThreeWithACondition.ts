// Last updated: 7/24/2025, 8:22:11 AM
function countSubarrays(nums: number[]): number {
    let res=0;
    let first = nums[0],second=nums[1];
    for(let i=2;i<nums.length;i++){
        if(first+nums[i]===second/2)
            res++;
        first=nums[i-1];
        second=nums[i];
    }
    return res;
};