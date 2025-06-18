int solution(const int n)
{
    auto sum = 0;
    for (auto i=1; i<=n; ++i) if (n%i==0) sum+=i;
    return sum;
}