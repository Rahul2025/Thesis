# filename : run.py

import time
f = open('/home/Rahul/Desktop/Thesis/Scripts/cyth_time', 'a')
start = time.time()
import qq59_mem
f.write(str(time.time() - start))
f.write('\n')
f.close