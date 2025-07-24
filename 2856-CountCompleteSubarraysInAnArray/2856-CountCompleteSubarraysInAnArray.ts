// Last updated: 7/24/2025, 8:23:07 AM
function countCompleteSubarrays(nums: number[]): number {
    let mp = new Map<number,number>();
    for(const num of nums)
        if(mp.has(num))
            mp.set(num,mp.get(num)+1);
        else
            mp.set(num,1);
    let res=0;
    for(let i=0;i<nums.length;i++){
        let mp1 = new Map<number,number>();
        for(let j=i;j<nums.length;j++){
            if(mp1.has(nums[j]))
                mp1.set(nums[j],mp1.get(nums[j])+1);
            else
                mp1.set(nums[j],1);
            if(mp.size===mp1.size)
                res++;
        }
    }
    return res;
};