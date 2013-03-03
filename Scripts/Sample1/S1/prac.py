from timeit import Timer
from functools import partial

def get_execution_time(function, numberOfExecTime, *args, **kwargs):
    """Return the execution time of a function in seconds."""
    return round(Timer(partial(function, *args, **kwargs))
                 .timeit(numberOfExecTime), 5)

def foo():
    import test

r = get_execution_time(foo, 1)
print r