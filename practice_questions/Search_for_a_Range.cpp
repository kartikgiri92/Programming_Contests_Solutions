// Link - https://www.interviewbit.com/problems/search-for-a-range/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector <int> ans;
    int n = A.size();
    int mid, i, j, temp;
    int low, high;

    low = 0; high = n - 1;
    while(low <= high){
        mid = low + (high - low)/2;

        if(A[mid] == B){
            if((mid == 0)||(A[mid - 1] != B))
                break;
            high = mid - 1;
        }
        else if(A[mid] < B){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    if(A[mid] != B){
        ans.push_back(-1);
        ans.push_back(-1);
        return(ans);
    }
    else{
        ans.push_back(mid);
    }

    low = mid; high = n - 1;
    while(low <= high){
        mid = low + (high - low)/2;

        if(A[mid] == B){
            if((mid == n - 1)||(A[mid + 1] != B))
                break;
            low = mid + 1;
        }
        else if(A[mid] < B){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    ans.push_back(mid);
    return(ans);
}
