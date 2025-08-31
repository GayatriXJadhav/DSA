/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let size=nums.length;
    let res=init;
    for(let i=0;i<size;i++){
        res=fn(res,nums[i]);
    }
    return res;
   
};