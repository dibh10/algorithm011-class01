class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        unordered_map<int, int> map;
        vector<int> res;

        for (auto data : nums)
        {
            map[data]++;
        }

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)//for(auto it : map)
        {
            if (q.size() < k)
            {
                q.push(make_pair(it->second, it->first));
            }
            else
            {
                if (q.top().first < it->second)
                {
                    q.pop();
                    q.push(make_pair(it->second, it->first));
                }
            }
        }

        while (!q.empty())
        {
            res.push_back(q.top().second);
            q.pop();
        }

        return res;
    }
};

