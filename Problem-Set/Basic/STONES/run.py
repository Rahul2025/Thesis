# filename : run.py

import time
f = open('/home/Rahul/Desktop/Thesis/Scripts/cyth_time', 'a')
start = time.time()
import qq66_tim
f.write(str(time.time() - start))
f.close