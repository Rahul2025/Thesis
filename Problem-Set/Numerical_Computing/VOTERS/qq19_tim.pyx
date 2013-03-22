#!/usr/bin/python
import sys,math
try:
	import psyco
	psyco.full()
except ImportError:
	pass

#this solution has problems, since the final result is not sorted.
#best approach will be to iterate over all numbers and create a priority q only #for the duplicates, and the get them in order.
def main():
	from sys import stdin,stdout
	lines = map(int,sys.stdin.read().split())
	n1 = lines[0]
	n2 = lines[1]
	n3 = lines[2]
	list1 = lines[3:3+n1]
	list2 = lines[3+n1:3+n1+n2]
	list3 = lines[3+n1+n2:3+n1+n2+n3]
	#stdout.write(str(n1)+","+str(n2)+","+str(n3)+"\n")
	#stdout.write(','.join(map(str,list1))+"\n")
	#stdout.write(','.join(map(str,list2))+"\n")
	#stdout.write(','.join(map(str,list3))+"\n")
	dupList = []
	dupMap = {}	
	mergeDups(mergeDups(list1,list2,dupList,dupMap),list3,dupList,dupMap)
	stdout.write(str(len(dupList))+"\n")
	if len(dupList)>0:
		stdout.write("\n".join(map(str,sorted(dupList)))+"\n")

def merge(left,right):
	result = []
	i, j = 0, 0
	while i < len(left) and j < len(right):
		if(left[i] <= right[j]):
			result.append(left[i])
			i+=1
		else:
			result.append(right[j])
			j+=1
	result+=left[i:]
	result+=right[j:]
	return result

def mergeDups(left,right,dupList,dupMap):
	result = []
	i, j = 0, 0
	while i < len(left) and j < len(right):
		if(left[i] < right[j]):
			result.append(left[i])
			i+=1
		elif(left[i] == right[j]):
			if(left[i] in dupMap):
				pass
			else:
				dupMap[left[i]] = 1
				dupList.append(left[i])
			result.append(left[i])
			result.append(right[j])
			i += 1
			j += 1
		
		else:
			result.append(right[j])
			j+=1
	result+=left[i:]
	result+=right[j:]
	return result
		

if __name__ == "__main__":
	main()