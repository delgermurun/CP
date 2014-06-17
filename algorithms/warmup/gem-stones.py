n = input()

s = raw_input();
gem_element = set(s)

for i in range(1, n):
    s = raw_input();
    gem_element = gem_element & set(s)

print len(gem_element)
