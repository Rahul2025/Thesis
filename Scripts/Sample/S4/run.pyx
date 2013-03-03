# filename : run.py

import time
start = (time.time()) * 1000000
import setup
end = (time.time()) * 1000000
f = open('cyth_time', 'a')
f.write(str(end-start))
f.write('\n')
f.close