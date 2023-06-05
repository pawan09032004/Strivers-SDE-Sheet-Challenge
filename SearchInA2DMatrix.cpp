bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int rs = matrix.size();
		     int cs = matrix[0].size();
         int r = 0;
         int c = cs - 1;
			
        while (r < rs && c > -1) {

            int cur = matrix[r][c];

            if (cur == target){
                 return true;
            }
            if (target > cur){ 
                r++;
            }
            else{ 
            c--;
            }
        }
        
        return false;
}
