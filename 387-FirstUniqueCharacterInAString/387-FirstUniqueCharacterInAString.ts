// Last updated: 7/24/2025, 8:31:20 AM
function firstUniqChar(s: string): number {
    const uniques: Map<string,number> = new Map();
    for(let i=0;i<s.length;i++)
        if(uniques.has(s[i]))
            uniques.set(s[i],-1);
        else
            uniques.set(s[i],i);
    
    let res: number = Number.MAX_SAFE_INTEGER;
    for(const val of uniques.values())
        if(val != -1)
            res = Math.min(val,res);
    
    if(res === Number.MAX_SAFE_INTEGER)
        return -1;
    return res;
};