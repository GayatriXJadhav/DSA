/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
   let size=this.length;
   for(let i=size-1;i>=0;i--){
     return this[i];
   }
    return -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */