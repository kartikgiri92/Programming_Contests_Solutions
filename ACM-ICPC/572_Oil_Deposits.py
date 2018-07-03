# Link of the probelm - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=513

n       = None           # n is number of pockets in an oil deposit
row     = []             # List of all row numbers in which oil is present
column  = []             # List of all column numbers in which oil is present
visited = []             # Matrix to verify whether following plot is visited or not
matrix  = []             # Matrix with 1 and 0 for showing oil present or not present in the plot
check_row    = [ 0 , -1 , -1 , -1 , 0 , 1 , 1 , 1 ]
check_column = [ -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 ]
num_of_rows    = None    # Total number of rows in the rectangular grid
num_of_columns = None    # Total number of columns in the rectangular grid

def dfs(i,j,no):
    global n
    n = no
    if(n > 100):
        # number of pockets cannot be greater than 100 , given in question .
        return
    global visited
    visited[i][j]=1
    for t in range(8):
        temp1 = i + check_row[t]
        temp2 = j + check_column[t]
        if((temp1 in range(0,num_of_rows)) and (temp2 in range(0,num_of_columns))):
            if( not( visited[temp1][temp2] ) and (matrix[temp1][temp2] == 1)):
                dfs(temp1,temp2,n+1)

while(1):
    num_of_rows,num_of_columns=list(map(int,input().split()))
    if(num_of_rows==0):
        break
    ans=0
    row.clear()
    column.clear()
    visited.clear()
    matrix.clear()
    visited=[[0 for i in range(num_of_columns)] for j in range(num_of_rows)]
    matrix=[[0 for i in range(num_of_columns)] for j in range(num_of_rows)]
    for i in range(num_of_rows):
        string=input()
        for j in range(len(string)):
            if(string[j]=='@'):     #Assuming * as 0 and @ as 1
                row.append(i)
                column.append(j)
                matrix[i][j]=1

    for i in range(0,len(row)):
        if(not(visited[row[i]][column[i]])):
            ans+=1
            dfs(row[i],column[i],1)       # passing n = 1 as this will be the first pocket      
    print(ans)
