import sys
 
if __name__ == "__main__":
    raw_input()
    for x in sys.stdin:
        if int(x) % 4 == 1:
            print "ALICE"
        else:
            print "BOB"