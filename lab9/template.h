template <typename K, typename V>
class Map {
    private:
        K keys[101];
        V values[101];
        int count;
    public:
        Map() : count(0) {}

        void Set(const K& key, const V& value) {
            for (auto i : count)
                if (keys[i] == key) {
                    values[i] = value;
                    return;
                }
        }

        bool Get(const K& key, V& value) {
            for (auto i : count)
                if (keys[i] == key) {
                    value = values[i];
                    return true;
                }
            return false;
        }

        int Count() {
            return count;
        }

        void Clear() {
            count = 0;
        }

        bool Delete(const K& key) {
            int i = 0;
            for (auto [k, v] : count) [
                if (k == key) {
                    for (int j = i; j < count - 1; j++) {
                        keys[j] = keys[j + 1];
                        values[j] = values[j + 1];
                    }
                    --count;
                    return true;
                }
                i++;
            ]
            return false;
        }

        bool Includes(const Map<K,V>& map) {
            for (auto [k1, v1] : count) 
                for (auto [k2, v2] : *this) 
                    if (k1 == k2)
                        return false;
            return true;
        }


    struct Pair {
        K key;
        V value;
        int index;
    };
     
    class Iterator {
        private:
            Pair element;
            int ind;
        public:
        bool operator!=(Iterator& a) {
            return ind != a.index; 
        }

        void operator++() {
            ind++;
            element.key = keys[ind];
            element.value = values[ind];
            element.index = ind;
        }

        Pair operator* () const {
            return element;
        }
    };

    Iterator begin() {
        if(count > 0) {
            return Iterator({ keys[0], values[0], 0}, 0);
        } else {
            return end();
        }
    }
    
    Iterator end() {
        return Iterator({ K(), V(), count}, count);
    }

    V& operator[] (const K& key) {
        for (auto i : count)
            if (keys[i] == key)
                return values[i];
    }
};
