#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode* dfs(graphNode *node, unordered_map<graphNode*, graphNode*> &um ){
	graphNode* clone = new graphNode(node->data, vector<graphNode*>());
	um[node] = clone;
	for(auto it: node->neighbours){
		if(um.find(it)==um.end()){
			clone->neighbours.push_back(dfs(it, um));
		}
		else{
			clone->neighbours.push_back(um[it]);
		}
	}
	return clone;
}
graphNode *cloneGraph(graphNode *node)
{
    if(!node)
		return node;
    if (node->neighbours.size() == 0) {
		graphNode* clone = new graphNode(node->data);
		return clone;
    }
    unordered_map<graphNode*, graphNode*> um;
	return dfs(node, um);
}
