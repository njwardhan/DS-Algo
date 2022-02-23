// Problem Link: https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10

// Recursive approach not clear ..

int countDistinctWayToClimbStair(long long nStairs)
{
    if(nStairs == 0)
        return 1;
    
    if(nStairs < 0)
        return 0;
    
    int answer = countDistinctWayToClimbStair(nStairs-1) + countDistinctWayToClimbStair(nStairs-2);
    
    return answer;
}