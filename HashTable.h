template<typename K, typename V> class HashMap{
    private:
        static const size_t hashGroups = 10;
        size_t size = 0;
        std::list<std::pair<K, V>> table[hashGroups];

    public:
        bool IsEmpty(){
            return size == 0;
        }

        int HashFunction(int key) const{
            return std::hash<K>{}(key) % hashGroups;
        }

        void InsertItem(K key, V value){
            int hashValue = HashFunction(key);
            auto& cell = table[hashValue];
            auto bItr = cell.begin();
            bool keyExists = false;
            for(; bItr != cell.end(); bItr++){
                if(bItr->first == key){
                    keyExists = true;
                    bItr->second = value;
                    break;
                }
            }
            if(!keyExists){
                cell.emplace_back(key, value);
                ++size;
            }
            return;
        }

        void printTable() const{
            for(size_t i = 0; i < hashGroups; i++){
                if (table[i].empty()) continue;
                auto bItr = table[i].begin();
                    
                for(const auto& pair : table[i]){
                    std::cout << pair.first << " " << pair.second << std::endl;
                }
            }
            std::cout << std::endl;
        }       
};