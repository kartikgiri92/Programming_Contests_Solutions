// Link - https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int n) {
    vector<int> v;
    int num_d = 0, num_i = 0;

    for(char x: A){
        if(x == 'D')
            num_d++;
        else
            num_i++;
    }

    if(A[0] == 'D'){
        v.push_back(num_d + 1);
        v.push_back(num_d);
        num_i = num_d + 2;
        num_d--;
    }
    else{
        v.push_back(num_d + 1);
        v.push_back(num_d + 2);
        num_i = num_d + 3;
    }

    for(int i = 1; i < n - 1; i++){
        if(A[i] == 'D'){
            v.push_back(num_d);
            num_d--;
        }
        else{
            v.push_back(num_i);
            num_i++;
        }
    }

    return(v);
}
