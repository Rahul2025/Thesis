from collections import defaultdict
>>> def modes(values):
	count = defaultdict(int)
	for v in values:
		count[v] +=1
	best = max(count.values())
	return [k for k,v in count.items() if v == best]
 