class TaskManager {
private:
	std::unordered_map<int, pair<int, int>> taskIdtouserIdp;
	std::priority_queue<pair<int, int>> taskpId;
public:
	TaskManager(vector<vector<int>>& tasks) {
		//taskId->priority userid

		for (int i = 0; i < tasks.size(); i++)
		{
			taskIdtouserIdp[tasks[i][1]] = { tasks[i][2] ,tasks[i][0] };
			taskpId.push({ tasks[i][2] ,tasks[i][1] });
		}

	}

	void add(int userId, int taskId, int priority) {
		taskIdtouserIdp[taskId] = { priority ,userId };
		taskpId.push({ priority ,taskId });
	}

	//taskIdpriority
	void edit(int taskId, int newPriority) {
		int userId= taskIdtouserIdp[taskId].second;
		taskIdtouserIdp[taskId]={ newPriority ,userId };
		taskpId.push({ newPriority ,taskId });
	}

	void rmv(int taskId) {
		taskIdtouserIdp.erase(taskId);
	}

	int execTop() {
		while (!taskpId.empty())
		{
			auto temp = taskpId.top();
			taskpId.pop();
			int priority = temp.first;
			int taskId = temp.second;
			if (taskIdtouserIdp.find(taskId) == taskIdtouserIdp.end()) {
				continue;
			}
            if (taskIdtouserIdp[taskId].first != priority) {
	continue;
}
			int userId = taskIdtouserIdp[taskId].second;
			taskIdtouserIdp.erase(taskId);
			return userId;
		}
        return -1;
	}
};