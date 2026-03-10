class Solution {
public:
    int minSubarray(vector<int>& a, int p) {
        long s = 0;
        for (int v : a) s += v;

        long r = s % p;
        if (r == 0) return 0;

        unordered_map<int,int> m;
        m[0] = -1;

        long pr = 0;
        int ans = a.size();

        for (int i = 0; i < a.size(); i++) {
            pr = (pr + a[i]) % p;
            int x = (pr - r + p) % p;

            if (m.count(x))
                ans = min(ans, i - m[x]);

            m[(int)pr] = i;
        }

        return ans == a.size() ? -1 : ans;
    }
};