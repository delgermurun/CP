t = input()
for _ in xrange(t):
    n = input()
    nums = map(int, raw_input().split())
    flag = "NO"
    s = sum(nums)
    cur = 0
    for i in xrange(n):
        if i > 0:
            cur += nums[i-1]
        if cur *2 == s-nums[i]:
            flag = "YES"
            break
    print flag
