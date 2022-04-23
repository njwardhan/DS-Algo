// Daily Challenge: 23rd April 2022
// Both encode() and decode() function run in constant time and space
// Solution uses an "okayish" hash function that does the job for us in this question

class Solution {
public:
    map<string, string> m;
    string HashFunction(string str)
    {   
        string s = "abcdefghijklmnopqrstuvwxyz";
        string t = "0123456789";
        
        vector<int> temp;
        srand(time(0));
        for(int i = 1; i <= 6; i++)
            temp.push_back(rand() % 7);
        
        string hash = "";
        
        hash += s[temp[0]];
        hash += s[temp[1]];
        hash += s[temp[2]];
        hash += t[temp[3]];
        hash += t[temp[4]];
        hash += t[temp[5]];
        
        m[hash] = str;
        return hash;
    }
    
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string x = "https://tinyurl.com";
        string k = HashFunction(longUrl);
        return x + k;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int n = shortUrl.size();
        string x = shortUrl.substr(n-6, n-1);
        return m[x];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));