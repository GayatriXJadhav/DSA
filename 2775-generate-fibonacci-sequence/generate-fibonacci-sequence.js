/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let t0=0,t1=1;
    let res;

    yield 0;
    yield 1;
    
    for(let i=2;i<=1e9;i++){
        res=t0+t1;
        t0=t1;
        t1=res;
      yield res;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */