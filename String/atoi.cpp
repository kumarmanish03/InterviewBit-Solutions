// By Manish Kumar (IEC2019068), IIIT Allahabad
// Medium But tricky due to corner cases
// Observe all corner cases carefully
// Observe how to ckeck overflow of an integer(line 37)
// https://www.interviewbit.com/problems/atoi/

int Solution::atoi(const string A) {
    int *ans = new int[(sizeof(int))];
    *ans = 0;
    int t = 0;
    bool neg = false;
    
    while(A[t] == ' '){
            t++;
    }
    
    if(A[t] == '+'){
        t++;
        if(A[t] >= '0' && A[t] <= '9') *ans = *ans + A[t] - '0';
        else return 0;
        t++;
    }
    else if(A[t] == '-'){
        neg = true;
        t++;
    }
    else if(A[t] < '0' || A[t] > '9'){
        return 0;
    }

    for(int i = t; i < A.size(); i++){
        if(A[i] < '0' || A[i] > '9'){
            if(neg) return -1 * *ans;
            else return *ans;
        }
        else {
						// To check overflow of an integer
            if((*ans > INT_MAX / 10) || (*ans == INT_MAX / 10 && A[i] != '0')){
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
            *ans = *ans * 10 + A[i] - '0';
        }
    }
    
    if(neg) return -1 * *ans;
    else return *ans;
    
}
