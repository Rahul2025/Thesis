def main():
    t = input()
    while t:
        try:
            count = 0
            n = input()
            p = raw_input()
            p = p.split()
            ma = p[0]
            for num in p:
                if ma >= num:
                    ma = num
                    count += 1
            print count
            t -= 1
        except EOFError:
            break;

if __name__ == '__main__':
    main()