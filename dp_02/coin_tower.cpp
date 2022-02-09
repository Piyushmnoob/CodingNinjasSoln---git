Coin Tower

Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?

Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.

Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).

Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec

Sample Input 1 :
4 2 3
Sample Output 1 :
Whis

Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus


int dp[2000000];
string findWinner(int n,int x,int y) {
    dp[1]=1;
    dp[x]=1; dp[y]=1;
    // if I'm winning at i-1, i-x, i-y th pos then there is no chance that at ith pos I will going to win
    
    
    for(int i=2;i<=n;i++) {
        if(!dp[i]) // if I am not winning at ith pos 
        {
      /* 1) */ dp[i]=dp[i-1]^1; // then it means I am winning at i-1 th pos
            
            if(i-x>=1)  // also winning at i-x pos
            {
                dp[i]=max(dp[i],dp[i-x]^1);
            }
           
            if(i-y>=1)    // also winning at i-y th pos.
            {
                dp[i]=max(dp[i],dp[i-y]^1); 
            }
        }
    }
    string sol; 
    if(dp[n]) 
        sol="Beerus";
    else
        sol="Whis";
    return sol;
}

