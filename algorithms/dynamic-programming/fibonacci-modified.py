s = raw_input();
a = map(lambda i: int(i), s.split(' '))

b = a[1];
n = a[-1];
a = a[0];

for i in range(2, n):
  c = b * b + a;
  a = b;
  b = c;

print c
