class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int arr[100];
        int index = 0;
        while(x!=0){
            int d = x%10;
            arr[index++] = d;
            x = x/10;
        }
        for(int i=0, j=index-1; i<index/2; i++, j--){
            if(arr[i]!=arr[j]){
                return false;
            }
        }
        return true;
    }
}; 