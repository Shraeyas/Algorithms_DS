#include <iostream>

using namespace std;

int main ()
{
	//freopen ("in.in", "r", stdin);

	int t, n_case = 1;
	cin >> t;

	while (t--)
	{
		int n, d, c, m;
		cin >> n >> d >> c >> m;

		string s;
		cin >> s;

		int n_dogs = 0, n_cats = 0;

		for (int i = n - 1 ; i >= 0 ; i--)
		{
			if (s[i] == 'C')
			{
				n_cats++;
			}

			else
			{
				n_dogs++;
			}
		}

		bool flag = true, flag_dog = true;

		for (int i = 0 ; i < s.length () ; i++)
		{
			if (d == 0 && n_dogs != 0)
			{
				flag = false;
				break;
			}

			if (s [i] == 'D')
			{
				d--;
				n_dogs--;
				c += m;
			}

			else
			{
				if (c == 0)
				{
					flag = false;
					break;
				}

				n_cats--;
				c--;
			}
		}

		if (n_dogs == 0)
		{
			cout << "Case #" << n_case++ << ": " << "YES" << endl;
		}

		else
		{
			cout << "Case #" << n_case++ << ": " << "NO" << endl;
		}
	}
}
