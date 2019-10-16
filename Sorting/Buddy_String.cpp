/*Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if(A.size()!=B.size())
            return false;
        
        if(A.size()<2)
            return false;
            
        int a[26] {0};
        int idx1=-1,idx2=-1;
        bool hasDuplicates = false;
        for(int i=0;i<A.size();i++){
            
            if(a[A[i]-'a'])
                hasDuplicates=true;
            ++a[A[i]-'a'];
            
            if(A[i]!=B[i]){
                if(idx1==-1)
                    idx1=i;
                else if(idx2==-1){
                    idx2=i;
                     if(A[idx1]!=B[idx2]||A[idx2]!=B[idx1])
                        return false;
                }else
                    return false;
            }
            
        }
        if(idx1!=-1&&idx2!=-1)
            return true;
        else if(idx1==-1&&idx2==-1)
            return hasDuplicates;
        else
            return false;
            
    }
};