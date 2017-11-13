class Solution {
public:
    unordered_map<string,string> m;
    int res=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(m.find(longUrl) != m.end())return m[longUrl];
        res++;
        m[longUrl]="tinyurl.com/"+to_string(res);
        return m[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        unordered_map<string,string>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second==shortUrl)
                return it->first;
        }
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));