# if statements
if 1 > 2:
    print("1 is greater than 2")
elif 2 > 1:
    print("2 is greater than 1")
else:
    print("1 is equal to 2")

# for loops
words = ["hello", "world", "!"]
for word in words:
    print(word)

# range function
for i in range(1, 10):
    print(i)

# while loops
i = 0
while i < 10:
    print(i)
    i += 1

# break and continue statements
for i in range(1, 10):
    if i == 3:
        continue
    if i == 5:
        break
    print(i)

# functions
def func1():
    print("hello world")

func1()
