// Link - https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &A){
    int i, j, temp, k;
    int n = A.size();

    for(i = n - 2; i >=0; i--){
        if(A[i] < A[i + 1]){
            break;
        }
    }

    if(i == -1){
        sort(A.begin(), A.end());
        return(A);
    }

    k = -1;
    for(j = n - 1; j > i; j--){
        if(k == -1){
            if(A[i] < A[j])
                k = j;
        }
        else if((A[i] < A[j]) && (A[j] < A[k])){
            k = j;
        }
    }

    temp = A[k];
    A[k] = A[i];
    A[i] = temp;

    i++;
    n--;
    while(i < n){
        temp = A[i];
        A[i] = A[n];
        A[n] = temp;
        i++;
        n--;
    }

    return(A);
}
