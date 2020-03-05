// Link - https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
vector<int> Solution::getRow(int A){
    vector <int> v;

    int i = A + 1, c = 1;

    for(int j = 1; j <= i; j++){
        v.push_back(c);
        c = c*(i - j)/j;
    }

    return(v);
}
