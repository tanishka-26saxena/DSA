//LPS -> Longest Prefix Suffix
//it is used in KMP algorithm

//Intuition :
//LPS array for a string stores the length of the longest proper prefix which is also a suffix for every prefix of the string.
//eg : for "ababc" -> LPS array is [0,0,1,2,0]

//Algorithm : 
//1. We maintain two pointers pre and suf, where pre points to the prefix and suf points to the suffix.
//2. We start with pre = 0 and suf = 1.
//3. We compare the characters at pre and suf.
//4. If they match, we increment both pre and suf and set lps[suf] = pre.
//5. If they don't match, we check if pre is not 0, then we set pre = lps[pre-1].
//6. If pre is 0, we set lps[suf] = 0 and increment suf.
//7. We repeat this process until suf reaches the end of the string.

//Dry Run :
//s = "ababc"
//LPS = [0,0,0,0,0]
//pre = 0 , suf = 1 -> s[pre] = 'a' , s[suf] = 'b' -> mismatch -> pre = 0 -> LPS[1] = 0 , suf = 2
//pre = 0 , suf = 2 -> s[pre] = 'a' , s[suf] = 'a' -> match -> pre = 1 , LPS[2] = 1 , suf = 3
//pre = 1 , suf = 3 -> s[pre] = 'b' , s[suf] = 'b' -> match -> pre = 2 , LPS[3] = 2 , suf = 4
//pre = 2 , suf = 4 -> s[pre] = 'a' , s[suf] = 'c' -> mismatch -> pre != 0 -> pre = LPS[pre-1] = LPS[1] = 0
//pre = 0 , suf = 4 -> s[pre] = 'a' , s[suf] = 'c' -> mismatch -> pre = 0 -> LPS[4] = 0 , suf = 5
//LPS = [0,0,1,2,0]


class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        vector<int> lps(n , 0);
            int pre = 0 , suf = 1;
            
            while(suf < n){
                if(s[pre] == s[suf]){
                    lps[suf] = pre + 1;
                    suf++;
                    pre++;
                }
                else{
                    if(pre == 0){
                        lps[suf] = 0;
                        suf++;
                    }
                    else{
                        pre = lps[pre-1];
                    }
                    
                }
                
            }
        
        return lps[n-1];
    }
};