//Z function algorithm
//it is used in pattern searching algorithm
//it is also used in finding distinct substring in a string
//it is also used in finding longest substring which is also prefix
//it is also used in finding number of times a pattern occurs in a string

//Intuition :
//Z function for a string is an array of same length as the string where Z[i]
//is the length of the longest substring starting from s[i] which is also a prefix of s.
//eg : for "ababc" -> Z array is [0,0,2,0,0]

//Algorithm :
//1. We maintain two pointers l and r which represent the rightmost segment of the string which is also a prefix.
//2. We iterate through the string from index 1 to n-1.
//3. For each index k, we check if k > r. If true, we set l = r = k and then we try to extend the segment [l, r] as much as possible by comparing characters from s[r] and s[r-l].
//4. If k <= r, we calculate the index k1 = k - l.
//   a. If Z[k1] < r - k + 1, we set Z[k] = Z[k1].
//   b. Else, we set l = k and then we try to extend the segment [l, r] as much as possible by comparing characters from s[r] and s[r-l].
//5. We repeat this process until we reach the end of the string.   

//Dry Run :
//s = "ababc"
//Z = [0,0,0,0,0]
//l = 0 , r = 0 , k = 1 -> k > r -> l = r = k = 1 -> s[r] = 'b' , s[r-l] = 'a' -> mismatch -> Z[1] = 0 , r = 0
//l = 0 , r = 0 , k = 2 -> k > r -> l = r = k = 2 -> s[r] = 'a' , s[r-l] = 'a' -> match -> r = 3 -> s[r] = 'b' , s[r-l] = 'b' -> match -> r = 4 -> s[r] = 'c' , s[r-l] = 'a' -> mismatch -> Z[2] = r - l = 4 - 2 = 2 , r = 3
//l = 0 , r = 3 , k = 3 -> k <= r -> k1 = k - l = 3 - 0 = 3 -> Z[3] < r - k + 1 -> Z[3] = Z[3] = 0
//l = 0 , r = 3 , k = 4 -> k <= r -> k1 = k - l = 4 - 0 = 4 -> Z[4] < r - k + 1 -> Z[4] = Z[4] = 0
//Z = [0,0,2,0,0]


class Solution {
public:
    vector<int> calculateZFunc(string s) {

        //doing it using Z function algorithm
        vector<int> ZFunc(s.size(), 0);
        int l = 0;
        int r = 0;

        for (int k = 1; k < s.size(); k++) {
            if (k > r) {
                l = r = k;
                while (r < s.size() && s[r] == s[r - l]) {
                    r++;
                }
                ZFunc[k] = r - l;
                r--;
            }
            else{
                int k1 = k - l;
                if(ZFunc[k1] < r - k + 1){
                    ZFunc[k] = ZFunc[k1];
                }
                else{
                    l = k;
                    while(r < s.size() && s[r] == s[r - l]){
                        r++;
                    }
                    ZFunc[k] = r-l;
                    r--;
                }
            }
        }
        return ZFunc;
    }
    int strStr(string haystack, string needle) {

        // using z-function algorithm to calculate this

        string s = needle + "$" + haystack;
        vector<int> ZFunc = calculateZFunc(s);

        for (int i = 0; i < ZFunc.size(); i++) {
            if (ZFunc[i] == needle.size()) {
                return i - needle.size() - 1;
            }
        }
        return -1;
    }
};