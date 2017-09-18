#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define REP(i, a, b) for (int i = a; i <= b; i++)

int DAYS_OF_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int LEAP_DAYS_OF_MONTH[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year)
{
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, d, m, y, day_of_month;
  string s;

  cin >> n;

  REP(i, 1, n)
  {
    cin >> m;
    y = m % 10000;

    m = m / 10000;
    d = m % 100;

    m = m / 100;

    REP(j, 1, 20)
    {
      day_of_month = is_leap_year(y) ? LEAP_DAYS_OF_MONTH[m - 1] : DAYS_OF_MONTH[m - 1];
      d += 14;

      if (d > day_of_month)
      {
        m += 1;
        d %= day_of_month;
      }

      if (m > 12)
      {
        y += m / 12;
        m %= 12;
      }
    }

    int t = m * 100 + d;

    if (t >= 121 && t <= 219)
    {
      s = " aquarius";
    }
    else if (t >= 220 && t <= 320)
    {
      s = " pisces";
    }
    else if (t >= 321 && t <= 420)
    {
      s = " aries";
    }
    else if (t >= 421 && t <= 521)
    {
      s = " taurus";
    }
    else if (t >= 522 && t <= 621)
    {
      s = " gemini";
    }
    else if (t >= 622 && t <= 722)
    {
      s = " cancer";
    }
    else if (t >= 723 && t <= 821)
    {
      s = " leo";
    }
    else if (t >= 822 && t <= 923)
    {
      s = " virgo";
    }
    else if (t >= 924 && t <= 1023)
    {
      s = " libra";
    }
    else if (t >= 1024 && t <= 1122)
    {
      s = " scorpio";
    }
    else if (t >= 1123 && t <= 1222)
    {
      s = " sagittarius";
    }
    else if (t >= 1223 || t <= 120)
    {
      s = " capricorn";
    }

    printf("%d %02d/%02d/%d%s\n", i, m, d, y, s.c_str());
  }

  return 0;
}