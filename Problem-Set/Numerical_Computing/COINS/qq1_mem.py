from functools import wraps
import collections
 
class memoize(object):
    def __call__(self,fn):
        fn.results = {}
        @wraps(fn)
        def wrapper(*args):
            args = tuple(args)
            if args in fn.results:
                return fn.results[args]
            result = fn(*args)
            fn.results[args] = result
            return result
        return wrapper
 
class RecursiveProcessor(object):
    def __init__(self,coin):
        self.coin = coin
    @memoize()
    def _process(self,coin):
        if coin < 12:
            return coin
        return self._process(coin/2)+self._process(coin/3)+self._process(coin/4)
 
if __name__ == "__main__":
    rp = RecursiveProcessor(0)
    while True:
        try:
            print rp._process(int(raw_input()))
        except (EOFError,ValueError):
            break 