class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>res;
        res.push_back(label);
        int level=1;
        int max_val=1;
        while(max_val<label){
            level++;
            max_val=(max_val *2) +1;

        }
        while(level>1){
            int parent_level=level-1;
            int normal_parent=label/2;
            
            int parent_min=0;
            int parent_max=0;
            if(parent_level>0){

             parent_min=(1 << (parent_level - 1));
             parent_max=(1 << parent_level)-1;
            }
            int real_parent=parent_min + parent_max-normal_parent;
            res.push_back(real_parent);
            label=real_parent;
            level--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};