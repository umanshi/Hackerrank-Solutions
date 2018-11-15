/*
Given two strings, a and b that may or may not be of the same length, 
determine the minimum number of character deletions required to make a
and b anagrams. Any characters can be deleted from either of the strings. 
*/

int makeAnagram(string a, string b) { 
    int count_a[26] = {0};
    int count_b[26] = {0};
    
    for(int i=0; i<a.length(); i++){
        count_a[a[i]-'a']++;}
    
    for(int i=0; i<b.length(); i++){
        count_b[b[i]-'a']++;} 
    int ans = 0;
    
    for(int i=0; i<26; i++)
        ans+= abs(count_a[i] - count_b[i]);
    return ans;
}
