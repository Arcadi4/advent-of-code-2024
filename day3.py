import re

pattern = re.compile(r'mul\([0-9]*,[0-9]*\)|do\(\)|don\'t\(\)')

with open('./day3.in.txt', 'r') as file:
    memory = file.read()
    
commands = pattern.findall(memory)
sum = 0
enabled = True

for command in commands:
    if command == 'do()':
        enabled = True
    elif command == 'don\'t()':
        enabled = False
    elif enabled:
        a, b = map(int, command[4:-1].split(','))
        sum += a * b

print(sum)
