Code : Edit Distance

Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character

Note
Strings don't contain spaces

Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.

Output Format :
The first and only line of output contains the edit distance value between the given strings.

Constraints :
1<= m,n <= 10
Time Limit: 1 second

Sample Input 1 :
abc
dc
Sample Output 1 :
2



int editDistance(string s1, string s2) {
	// base case
    if(s1.size()==0 &&s2.size()==0)  // s1="" && s2="" in this case s1==s2 hence no ops hence return 0;
    {
        return 0;
    }
    
// here s1 is taken as a referencei.e; we will try to make s2 equals to s1.
    int x,y,z;    // x-> insert y-> replace, z-> delete 
    
    if(s1.empty())   // s1="" s2= bye -> insert, replace -> not work only delete will work
    {
           z= editDistance(s1, s2.substr(1)) +1;    
        
        return z;
    }
        
     if(s2.empty()) // s1=xbd   s2="" -> replace delete-> not work, insert -> will work
     {
         x= editDistance(s1.substr(1), s2) + 1;
         return x;
     }   
    
    if(s1[0]==s2[0]) {
        x= editDistance(s1.substr(1), s2.substr(1));
        
        return x;
    } else {
        
        // insert
        x= editDistance(s1.substr(1), s2) + 1;
        
        // replace
        y= editDistance(s1.substr(1), s2.substr(1)) + 1;
        
        // delete
        z= editDistance(s1, s2.substr(1)) + 1;
        
        return min(x, min(y,z));
    }
}


//**************************** Memoization**************************************//

#include<vector>

//************************************* memoization********************************************//
int editDistance(string s1, string s2, vector<vector<int>> &dp) {
	// base case
    if(s1.size()==0 &&s2.size()==0)  // s1="" && s2="" in this case s1==s2 hence no ops hence return 0;
    {
        return 0;
    }

    int m=s1.size();
    int n=s2.size();

    if(dp[m][n]!=-1) {
        return dp[m][n];
    }


// here s1 is taken as a referencei.e; we will try to make s2 equals to s1.
    int x,y,z;    // x-> insert y-> replace, z-> delete

    if(s1.empty())   // s1="" s2= bye -> insert, replace -> not work only delete will work
    {
           z= editDistance(s1, s2.substr(1), dp) +1;
           dp[0][n]=z;
        return z;
    }

     if(s2.empty()) // s1=xbd   s2="" -> replace delete-> not work, insert -> will work
     {
         x= editDistance(s1.substr(1), s2, dp) + 1;
         dp[m][0]= x;
         return x;
     }

    if(s1[0]==s2[0]) {
        x= editDistance(s1.substr(1), s2.substr(1), dp);
        dp[m][n]=x;
        return x;
    } else {

        // insert
        x= editDistance(s1.substr(1), s2, dp) + 1;

        // replace
        y= editDistance(s1.substr(1), s2.substr(1), dp) + 1;

        // delete
        z= editDistance(s1, s2.substr(1), dp) + 1;

        return dp[m][n]= min(x, min(y,z));
    }
}

//**************************************** tabualtion*********************************************//
int editDistance_tab(string s1, string s2, vector<vector<int>> &dpArr) {


    int m=s1.size();
    int n=s2.size();


    dpArr[0][0]=0; // base case

    // corner case 1 :- s1="" s2= bye -> insert, replace -> not work only delete will work & we have to delete
                                                // till s2.size();
    for(int j=0; j<n; j++) {
        dpArr[0][j]= j;
    }

    // corner case 2:-  s1=xbd   s2="" -> replace delete-> not work, insert -> will work & we have to insert
                                                // till s1.size();
    for(int i=0;i<m;i++) {
        dpArr[i][0]= i;
    }

    // remaining cells
   for(int i=1;i<=m;i++) {
       for(int j=1;j<=n;j++) {

           if(s1[m-i]== s2[n-j])  // to ckeck s1[0]==s2[0]
           {
               dpArr[i][j]= dpArr[i-1][j-1];
           } else {
               int x= dpArr[i-1][j]+1;
               int y= dpArr[i-1][j-1]+ 1;
               int z=  dpArr[i][j-1]+1;

               dpArr[i][j]= min(x,min(y,z));

           }
       }
   }

    return dpArr[m][n];
}

int editDistance(string s1, string s2)
{
	vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));  // declaring.

	vector<vector<int>> dpArr(s1.size()+1, vector<int>(s2.size()+1, -1));  // declaring.


    return editDistance_tab(s1, s2, dpArr);
}


