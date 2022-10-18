class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int i=0,countSetBits_num2=0,countSetBits_num1=0;
        for(int i=0;i<32;i++){
            if((num2 & (1<<i))!=0)
                countSetBits_num2++;
            if((num1 & (1<<i))!=0)
                countSetBits_num1++;
        }
        int diff=countSetBits_num2 - countSetBits_num1;
        if(diff==0)
            return num1;
        else if(diff<0){
            diff=abs(diff);
            while(diff!=0 && i<32){
                if((num1 & (1<<i))!=0){
                    num1 ^= (1<<i);
                    diff--;
                }
                i++;
            }
            return num1;
        }
        else{
            int i=0;
            while(diff!=0 && i<32){
                if((num1 & (1<<i))==0){
                    num1 ^= (1<<i);
                    diff--;
                }
                i++;
            }
            return num1;
        }
        return 0;
    }
};
