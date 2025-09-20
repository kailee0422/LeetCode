class Router {
private:
    int memorylimit ;
    queue<tuple<int, int, int>> FIFO;
    map<tuple<int, int, int>, bool> umap;

public:
    Router(int memoryLimit) {
        memorylimit= memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        if (umap.find({source, destination, timestamp })== umap.end())
        {
            // not found
            while (FIFO.size() >= memorylimit) {
                auto temp = FIFO.front();
                FIFO.pop();
                umap.erase(temp);
            }
            umap[{source, destination, timestamp }] = true;
            FIFO.push({ source ,destination ,timestamp });
            return true;
        }
        return false;
    }

    vector<int> forwardPacket() {
        if (FIFO.empty()) {
            return {};
        }

        auto temp = FIFO.front();
        FIFO.pop();
        umap.erase(temp);
        return { get<0>(temp), get<1>(temp), get<2>(temp) };
    }

    int getCount(int destination, int startTime, int endTime) {
        int count = 0;
        for (const auto& n : umap) {
            if (get<1>(n.first) == destination && (get<2>(n.first) >= startTime && get<2>(n.first) <= endTime))
            {
                count++;
            }
        }
        return count;
    }
};
