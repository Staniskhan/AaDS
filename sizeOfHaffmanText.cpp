#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
typedef long long ll;

ll getMin(std::vector<ll>& repeats, std::deque<ll>& nodes)
{
	if (repeats.empty())
	{
		ll a = nodes.back();
		nodes.pop_back();
		return a;
	}
	else if (nodes.empty())
	{
		ll a = repeats.back();
		repeats.pop_back();
		return a;
	}
	else
	{
		if (repeats.back() <= nodes.back())
		{
			ll a = repeats.back();
			repeats.pop_back();
			return a;
		}
		else
		{
			ll a = nodes.back();
			nodes.pop_back();
			return a;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::ifstream in;
	in.open("huffman.in");

	ll n;
	in >> n;

	std::vector<ll> repeats(n);
	std::deque<ll> nodes;

	for (ll i = 0; i < n; i++)
	{
		in >> repeats[n - i - 1];
	}
	in.close();


	unsigned long long sum = 0;

	while (!repeats.empty() || nodes.size() != 1)
	{
		ll a = getMin(repeats, nodes);
		ll b = getMin(repeats, nodes);

		nodes.push_front(a + b);
		sum += a + b;
	}

	


	std::ofstream out;
	out.open("huffman.out");
	out << sum;
	out.close();

}