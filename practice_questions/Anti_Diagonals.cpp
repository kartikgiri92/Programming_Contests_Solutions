// Link - https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector < vector <int> > v;
    int n = A.size();
    int i, j, k, l;

    for(j = 0; j < n; j++){
        vector <int> temp;
        for(i = 0; i <= j; i++){
            temp.push_back(A[i][j - i]);
        }
        v.push_back(temp);
    }

    for(k = 1; k < n; k++){
        j = n - 1;
        vector <int> temp;
        for(l = k ; l < n; l++){
            temp.push_back(A[l][j]);
            j--;
        }
        v.push_back(temp);
    }

    return(v);
}
