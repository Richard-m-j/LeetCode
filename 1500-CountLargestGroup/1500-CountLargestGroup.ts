// Last updated: 7/24/2025, 8:26:58 AM
function countLargestGroup(n: number): number {
    const mp = new Map<number,number>;
    for(let i=1;i<=n;i++){
        let num = i,digitSum=0;
        while(num){
            digitSum += num%10;
            num = Math.floor(num/10);
        }
        if(mp.has(digitSum))
            mp.set(digitSum,mp.get(digitSum)+1);
        else
           mp.set(digitSum,1);
        // console.log(i,digitSum,mp.get(digitSum));
    }
    let res=0,groupSize=0;
    for(let size of mp.values()){
        // console.log(size);
        if(size==groupSize)
            res++;
        else if(size>groupSize){
            res=1;
            groupSize=size;
        }
    }
    return res;
};