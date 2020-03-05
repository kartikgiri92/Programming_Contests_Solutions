// Link - https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &A){
    int start_index = -1, end_index = -1;
    int temp_start = -1, temp_end = -1;
    long int max_yet = INT_MIN;
    long int sum_yet = -1;

    for(int i = 0; i < A.size(); i++){
        if(A[i] < 0){
            sum_yet = -1;
            continue;
        }

        if((sum_yet == -1)){
            sum_yet = 0;
            temp_start = i;
        }

        sum_yet += A[i];
        temp_end = i;

        if(sum_yet > max_yet){
            start_index = temp_start;
            end_index = temp_end;
            max_yet = sum_yet;
        }
        else if((sum_yet == max_yet) && (temp_start != start_index)){
            if((end_index - start_index) < (temp_end - temp_start)){
                start_index = temp_start;
                end_index = temp_end;
            }
        }
        else if((sum_yet == max_yet) && (temp_start == start_index)){
            end_index = temp_end;
        }
    }

    vector <int> ans;
    if(start_index == -1)
        return(ans);
    for(int i = start_index ; i<= end_index; i++)
        ans.push_back(A[i]);

    return(ans);

}
