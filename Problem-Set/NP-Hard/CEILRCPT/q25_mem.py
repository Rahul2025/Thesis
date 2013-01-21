input()
try:
    while True:
        number = bin(input())
        if len(number) >= 12:
            result = int(number[:-12]+'0',2)
            number = number[-12:]
        else:
            result = 0
        print result+number.count('1')
except:
    pass