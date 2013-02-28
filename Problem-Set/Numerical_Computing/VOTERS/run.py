# filename : run.py

import time
start = (time.time()) * 1000000
import qq19_tim
end = (time.time()) * 1000000
f = open('/home/Rahul/Desktop/Thesis/Scripts/cyth_time', 'a')
f.write(str(end-start))
f.write('\n')
f.close