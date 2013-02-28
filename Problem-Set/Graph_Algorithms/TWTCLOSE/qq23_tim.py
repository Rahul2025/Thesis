import sys

def closethetweets():
  fstline = sys.stdin.readline()
  lengths = fstline.split()
  N = int(lengths[0])
  tweets = [0] * N
  opened = 0
  for a in sys.stdin:
    if a.startswith("CLICK"):
      tweetId = int(a[6:])
      if tweets[tweetId-1]:
        opened = opened-1
      else:
        opened = opened+1
      tweets[tweetId-1] = 1 - tweets[tweetId-1]
    else:
      opened = 0
      tweets = [0] * N
    print opened
  pass

if __name__=="__main__":
  closethetweets()