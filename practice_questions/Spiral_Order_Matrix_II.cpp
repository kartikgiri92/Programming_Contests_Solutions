// Link - https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector < vector <int> > v;

    int n = A;
    int i, j, num = 1;
    int a = 0, b = n - 1, x = 0, y = n - 1;

    for(i = 0; i < n; i++){
        vector <int> temp;
        for(j = 0; j < n; j++){
            temp.push_back(0);
        }
        v.push_back(temp);
    }

    while(a <= b && x <= y){

        for(i = x; i <= y; i++){
            v[a][i] = num;
            num++;
        }
        a++;

        for(i = a; i <= b; i++){
            v[i][y] = num;
            num++;
        }
        y--;

        for(i = y; i >= x; i--){
            v[b][i] = num;
            num++;
        }
        b--;

        for(i = b; i >= a; i--){
            v[i][x] = num;
            num++;
        }
        x++;

    }

    return(v);
}
