#include <iostream>
#include <string>
std::string str;
int last[100005],dp[100005];
int main(){
    std::cin >> str;
    dp[1] = 1;
    int ans = 1;
    last[str[0]] = 1;
    for (int i = 2; i <= str.size(); i++){
        char cur = str[i - 1];
        dp[i] = dp[i - 1] + (i - last[cur]);
        last[cur] = i;
        ans += dp[i];
    }
    std::cout << ans;
    return 0;
}