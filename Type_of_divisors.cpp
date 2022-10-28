#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string solution(ll n)
{
	ll even = 0, odd = 0;
	for (ll i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i % 2 == 0)
			{
				even++;
			}
			if ((n / i) % 2 == 0)
			{
				if (n / i == i)
				{
					even--;
				}
				even++;
			}
			if ((n / i) % 2 != 0)
			{
				if (n / i == i)
				{
					odd--;
				}
				odd++;
			}
			if (i % 2 != 0)
			{
				odd++;
			}
		}
	}

// if there are more no. of even divisors
	if (even > odd)
	{
		return "even";
	}
  // if there are more no. of even divisors
	else if (even < odd)
	{
		return "odd";
	}
  // if there are equal no. of divisors
	else
		return "equal";
}

int main()
{
	ll n;
	cin >> n;
	string answer = solution(n);
	cout << answer << endl;
}
