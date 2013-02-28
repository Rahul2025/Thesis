import sys
#import exceptions
#import string
def main():
    #try:
        num = int(input())
        lst = list((raw_input()).split())
        #del(lst[1::2])
        #lst = int(lst)
        #print num , lst
        i = 1
        real = []
        while i<= num:
                if(real.count(i) > 0): 
                        i+=1
                        continue
                loop = []
                #loop.append(i)
                l = i
                j = 0
                while j < num:
                        loop.append(l)
                        l = int(lst[l-1])
                        if(l== loop[0]): 
                                loop.append(l)
                                #print loop
                                break
                        j+=1
                real.extend(loop)
                i+=1
        #print real
        i = 1
        k = 0
        while i<= num:
                if real.count(i)==2: k+=1
                                
                i+=1
        print k
        i = 1
        l = real[0]
        flag = 0
        print l ,
        while i< len(real):
                if flag : 
                        l = real[i]
                        print l,
                        i+=1
                        flag = 0
                if real[i] == l : 
                        print real[i] 
                        #print "\n"
                        flag = 1
                        #continue
                else :  print real[i] ,
                i+=1
        sys.exit(0)        
    #except exceptions: print "exeption found" + exceptions
if(__name__=="__main__"):
        main()