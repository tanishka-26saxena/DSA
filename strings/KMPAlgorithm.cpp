//KMP Algorithm
//Time Complexity : O(n + m) , n = size of haystack , m = size of needle
//Space Complexity : O(m) , m = size of needle

//Intuition : 
//1. We will first calculate the LPS array of needle string.
//2. Then we will traverse the haystack and needle string simultaneously and if we find a mismatch we will use the LPS array to avoid unnecessary comparisons.

//Example :
//haystack = "ababcababcabc"
//needle = "abc"
//LPS = [0,0,1]
//We will start comparing from the first character of both strings.
//We will keep moving forward until we find a mismatch.
// When we find a mismatch we will use the LPS array to avoid unnecessary comparisons.
//In this case when we reach the 3rd character of needle and 5th character of haystack we will find a mismatch.
//We will use the LPS array to move the pointer of needle to the 1st character and keep the pointer of haystack at the 5th character.
//We will keep doing this until we find the needle in the haystack or we reach the end of haystack.

//Dry Run : 
//haystack = "ababcababcabc"
//needle = "abc"
//LPS = [0,0,1]
//i = 0 , j = 0 haystack[i] = 'a' , needle[j] = 'a' -> match -> i = 1 , j = 1
//i = 1 , j = 1 haystack[i] = 'b' , needle[j] = 'b' -> match -> i = 2 , j = 2
//i = 2 , j = 2 haystack[i] = 'a' , needle[j] = 'c' -> mismatch -> j = LPS[j-1] = LPS[1] = 0
//i = 2 , j = 0 haystack[i] = 'a' , needle[j] = 'a' -> match -> i = 3 , j = 1
//i = 3 , j = 1 haystack[i] = 'b' , needle[j] = 'b' -> match -> i = 4 , j = 2
//i = 4 , j = 2 haystack[i] = 'c' , needle[j] = 'c' -> match -> i = 5 , j = 3
//j == m -> return i - j = 5 - 3 = 2    


class Solution {
public:
    vector<int> getLPS(string& needle){
        int n = needle.size();
        vector<int> LPS(n , 0);
        int i = 0 , j = 1;

        while(j < n){
            if(needle[i] == needle[j]){
                i++;
                LPS[j] = i;
                j++;
            }
            else{
                if(i == 0){
                    LPS[j] = 0;
                    j++;
                }
                else{
                    i = LPS[i-1];
                }
            }
        }

        return LPS;
    }
    int strStr(string haystack, string needle) {

        //solving it using KMP algorithm
        //it is nothing but extended form of LPS

        vector<int> LPS = getLPS(needle);
        int n = haystack.size();
        int m = needle.size();

        int i = 0 , j = 0;

        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            if(j == m){
                return i - j;
            }
            else if(i < n && j < m && haystack[i] != needle[j]){
                if(j == 0) i++;
                else j = LPS[j-1];
            }

        }

        return -1;

        
    }
};