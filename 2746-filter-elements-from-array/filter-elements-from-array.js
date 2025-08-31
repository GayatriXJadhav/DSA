/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filterarr=[];
    for(let i=0;i<arr.length;i++){
     if(fn(arr[i],i)){
        filterarr.push(arr[i]);
     }
    }
    return filterarr;
}