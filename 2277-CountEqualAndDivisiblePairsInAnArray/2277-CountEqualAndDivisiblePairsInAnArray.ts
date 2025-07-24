// Last updated: 7/24/2025, 8:24:44 AM
function countPairs(nums: number[], k: number): number {
    const mp: Map<number, number[]> = new Map();
    let res = 0;
    for(const [i,num] of nums.entries()){
        if(mp.has(num)){
            for(const j of mp.get(num)!){
                if((i*j)%k==0)
                    res++;
            }
        }
        else{
            mp.set(num,[]);
        }
        mp.get(num)!.push(i);
    } 
    return res; 
};