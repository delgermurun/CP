import re

public_class_regex = re.compile('[\s]*public[\s]*class[\s]*([a-zA-Z\d_$]+).*')
class_regex = re.compile('.*[\s]*class[\s]*([a-zA-Z\d_$]+).*')
main_function_regex = re.compile('.*[\s]*main[\s]*\(.*\).*')
class_name = ''
pre_class_name = ''

while True:
    try:
        s = raw_input()
    except EOFError:
        break

    if class_name:
        continue

    m = public_class_regex.match(s)
    if m:
        class_name = m.groups()[0]
        continue

    m = class_regex.match(s)
    if m:
        pre_class_name = m.groups()[0]
        continue

    m = main_function_regex.match(s)
    if m:
        class_name = pre_class_name

print class_name
