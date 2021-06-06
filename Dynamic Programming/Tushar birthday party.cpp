// Manish Kumar, IIIT Allahabad
// Medium

// Unbounded KnapSack(dishes can be ate unlimitedly)

https://www.interviewbit.com/problems/tushars-birthday-party/

// Strategy:
// **Observations: **
// As the friends cannot share dishes, we can calculate the cost for each of them independently and add all such costs.
// Now, the problem instance for every friend is reduced to standard KnapSack problem.

// **Dynamic programming recurrence: **

// dp[i][j] –> min. cost to satisfy a person with capacity i using first j dishes.

// dp[i][j] = min( dp[i][j-1] , dp[ i-fillCap[j] ][j] + cost[j] ) // if ( i-fillCap[j] ) >= 0
// dp[i][j] = dp[i][j-1] // otherwise

// As one dish can be taken multiple times, we have used dp[ i-fillCap[j] ][ j ] and not dp[ i-fillCap[j] ][ j-1 ]. This is different from standard KnapSack where one element can be used only once.

// Note: Base cases should be handled properly.

int dp[1001][1001];

// dp[i][j] = minimum cost using first 'i' dishes for 'j' capacity

long long memorization(const vector<int> &dishes, const vector<int> &cost, int dish , int capacity){
    if(capacity == 0){
        return 0;
    }
    if(dish == 0){
        return INT_MAX;  // If 
    }
    
    if(dp[dish][capacity] != -1)
        return dp[dish][capacity];
    
    if(dishes[dish-1] <= capacity){
        dp[dish][capacity] = min(cost[dish-1]+memorization(dishes, cost, dish, capacity-dishes[dish-1]), memorization(dishes, cost, dish-1, capacity));
    }
    else
        dp[dish][capacity] = memorization(dishes, cost, dish-1, capacity);
        
    return dp[dish][capacity];
}

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    memset(dp, -1, sizeof(dp));
    int minCost = 0;
    int n = B.size();
    //memorization(B,C,n, 1000);
    for(auto i:A){
        minCost += (int)memorization(B,C,n, i);;
    }
    memset(dp, -1, sizeof(dp));
    return minCost;
}
