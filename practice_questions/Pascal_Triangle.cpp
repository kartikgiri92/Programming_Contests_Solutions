// Link - https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    vector < vector <int> > v;
    int i, j;

    for(i = 0; i < A; i++){
        vector <int> temp;
        for(j = 0; j <= i; j++){
            if((j == 0) || (j == i)){
                temp.push_back(1);
                continue;
            }
            temp.push_back(v[i - 1][j] + v[i - 1][j - 1]);
        }
        v.push_back(temp);
    }

    return(v);
}
