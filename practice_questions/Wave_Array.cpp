// Link - https://www.interviewbit.com/problems/wave-array/

vector<int> Solution::wave(vector<int> &A){
    int n = A.size();
    int temp;

    sort(A.begin(), A.end());
    for(int i = 0; i < n; i += 2){
        if(i + 1 == n)
            break;
        temp = A[i + 1];
        A[i + 1] = A[i];
        A[i] = temp;
    }

    return(A);

}
