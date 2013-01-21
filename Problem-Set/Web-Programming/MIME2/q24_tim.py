#!/usr/bin/python
## Internet Media Types (April Cook-Off Challenge)


n, q = map(int, raw_input().split()) ## nb media type, nb file names

## ext - media type
tab = [raw_input().split() for _ in xrange(n)]
t_ext = [tab[i][0] for i in xrange(n)] ## list of ext

## file names
for p in xrange(q):
	nfile = str(raw_input().strip())[::-1] # a lenvers
	pb = 1 ## pas d inconnue par defaut
	ind = 0
	
	if nfile.find(".") != -1:
		ind = nfile.index(".")
		nf_ext = nfile[:ind][::-1] ## ext a lenvers
		if nf_ext in t_ext:
			print tab[t_ext.index(nf_ext)][1]
			pb = 0
	
	if pb == 1:
		print "unknown"