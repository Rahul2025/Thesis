# filename : run.py

import time
f = open('/home/Rahul/Desktop/Thesis/Scripts/cyth_time', 'a')
start = time.time()
import qq130_mem
f.write(str(time.time() - start))
f.close