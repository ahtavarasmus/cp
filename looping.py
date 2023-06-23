# here is different looping method in python
# 1. for loop
print("for loop")
for i in range(10):
    print(i)

# 2. while loop
print("while loop")
i = 0
while i < 10:
    print(i)
    i += 1

# 3. do while loop
print("do while loop")
i = 0
while True:
    print(i)
    i += 1
    if i >= 10:
        break
