vector<int> stringMatch(string text, string pattern) {
	vector<int> ans;
	int n = text.size();
	int m = pattern.size();

	for(int i = 0; i < n; i++){
		bool isContains = true;
		int j = i;
		int k = 0;
		while(k < m){
			if(text[j] != pattern[k]){
				isContains = false;
				break;
			}
			k++;
			j++;
		}
		if(isContains) ans.push_back(i+1);
	}

	return ans;
}
