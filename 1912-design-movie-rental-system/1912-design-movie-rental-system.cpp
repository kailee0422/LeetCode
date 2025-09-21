class MovieRentingSystem {
private:
    unordered_map<int, set<pair<int, int>>>hashmap;//movie->(price,shop)
    map< pair<int, int>, int> hashmapforp;//(shop,movie)->price
    set<tuple<int,int, int>> record;//(shop,movie) rent movie(5)

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (int i = 0; i < entries.size(); i++)
        {
            hashmap[entries[i][1]].insert( { entries[i][2],entries[i][0] });
            hashmapforp[{entries[i][0], entries[i][1]}]=(entries[i][2]);
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;

        for (auto& p : hashmap[movie]) {
            if (count >= 5) {
                break;
            }
            result.push_back(p.second); // shop
            count++;
        }

        return result;
    }

    void rent(int shop, int movie) {
        int price = hashmapforp[{shop, movie}];
        hashmap[movie].erase({ price,shop });
        record.insert({ price ,shop ,movie });
    }

    void drop(int shop, int movie) {
        int price = hashmapforp[{shop, movie}];
        record.erase({ price ,shop ,movie });
        hashmap[movie].insert({ price,shop });

    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto it = record.begin(); it != record.end() && count < 5; ++it, ++count) {
            int price = get<0>(*it);
            int shop = get<1>(*it);
            int movie = get<2>(*it);
            result.push_back({ shop, movie });
        }
        return result;
    }
};
