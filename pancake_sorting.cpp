class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        
        vector<int> steps(A.size()*2);
        int n = A.size();
        int sz = n;
        int j = 0;
        while(sz > 0){
            int i = get_index_of_max(A,sz);
            
            if(i >= 0){
                
                flip(A,0,i);
                flip(A,0,sz-1);
                steps[j++]= i+1;
                steps[j++] = sz;
            }
            sz -=1;
        }
        
        steps.resize(j);
        return steps;
        
        
    }
    
    
    int get_index_of_max(vector<int>& A,int n){
        
        for(int i=0;i<n;i++){
            if(A[i]==n){
                return i;
            }
        }
        return -1;
    }
    
    
    void flip(vector<int>& a,int i,int j){
        while(i<j){
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
            i ++ ;
            j -- ;
        }
    }
};
