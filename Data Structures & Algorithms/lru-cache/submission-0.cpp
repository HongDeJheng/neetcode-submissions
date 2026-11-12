class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (auto it = keyToCachePos.find(key); it != keyToCachePos.end()) {
            auto &cachePos = it->second;
            touch(cachePos);
            return cachePos->second;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (auto it = keyToCachePos.find(key); it != keyToCachePos.end()) {
            auto &cachePos = it->second;
            touch(cachePos);
            cachePos->second = value;
            return;
        }

        if (cache.size() >= capacity) {
            auto removeKey = cache.back().first;
            keyToCachePos.erase(removeKey);
            cache.pop_back();
        }

        cache.push_front({key, value});
        keyToCachePos[key] = cache.begin();
    }

private:
    using Cache = list<pair<int, int>>;
    using CachePos = Cache::iterator;
    Cache cache;
    unordered_map<int, CachePos> keyToCachePos;
    int capacity;

    void touch(CachePos &it) {
        cache.splice(cache.begin(), cache, it);
        it = cache.begin();
    }
};
