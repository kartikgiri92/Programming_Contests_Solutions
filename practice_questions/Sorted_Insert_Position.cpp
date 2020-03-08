// Link - https://www.interviewbit.com/problems/sorted-insert-position/

int Solution::searchInsert(vector<int> &A, int B) {
    int low, high, mid;
    int n = A.size();

    low = 0; high = n - 1;

    while(low <= high){
        mid = low + (high - low)/2;

        if(A[mid] == B)
            return(mid);

        if(A[mid] < B)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return(low);
}
