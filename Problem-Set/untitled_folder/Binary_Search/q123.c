typedef int Object;
 
int cmpObject(Object* pa, Object *pb) 
{
  Object a = *pa;
  Object b = *pb;
  if (a < b) return -1;
  if (a == b) return 0;
  if (a > b) return 1;
  assert(0);
}
 
int bsearch(Object Array[], int n, Object *KeyPtr,
	    int (*cmp)(Object *, Object *), 
            int NotFound) 
{
  unsigned left = 1, right = n; /* `unsigned' to avoid overflow in `(left + right)/2' */
 
  if ( ! (Array && n > 0 && KeyPtr && cmp)) 
    return NotFound; /* invalid input or empty array */
 
  while (left < right)
  {
    /* invariant: a[left] <= *KeyPtr <= a[right] or *KeyPtr not in Array */
    unsigned m = (left  +  right) / 2; /*NOTE: *intentionally* truncate for odd sum */
 
    if (cmp(Array + m, KeyPtr) < 0) 
      left = m + 1;       /* a[m] < *KeyPtr <= a[right] or *KeyPtr not in Array */
    else 
      /* assert(right != m) or infinite loop possible */
      right = m;          /* a[left] <= *KeyPtr <= a[m] or *KeyPtr not in Array */
  }
  /* assert(left == right) */
  return (cmp(Array + right, KeyPtr) == 0) ? right : NotFound;
}#define  DUMMY -1 /* dummy element of array (to adjust indexing from 1..n) */
 
int main(void) 
{
  Object a[] = {DUMMY, 0, 1, 1, 2, 5}; /* allowed indices from 1 to n including */
  int n = sizeof(a)/sizeof(*a) - 1;
  const int NotFound = -1;
 
  /* key not in Array */
  Object key = 4;
  assert(NotFound == bsearch(a, n, &key, cmpObject, NotFound));
  key = DUMMY;
  assert(NotFound == bsearch(a, n, &key, cmpObject, NotFound));
  key = 7;
  assert(NotFound == bsearch(a, n, &key, cmpObject, NotFound));
 
  /* all possible `n' and `k' for `a' array */
  int k;
  key = 10; /* not in `a` array */
  for (n = 0; n <= sizeof(a)/sizeof(*a) - 1; ++n)
    for (k = n; k>=1; --k) {
      int index = bsearch(a, n, &a[k], cmpObject, NotFound);
      assert(index == k || (k==3 && index == 2) || n == 0); /* for equal `1's */
      assert(NotFound == bsearch(a, n, &key, cmpObject, NotFound));
    }
  n = sizeof(a)/sizeof(*a) - 1;
 
  /* NULL array */
  assert(NotFound == bsearch(NULL, n, &key, cmpObject, NotFound));
  /* NULL &key */
  assert(NotFound == bsearch(a, n, NULL, cmpObject, NotFound));
  /* NULL cmpObject */
  assert(1 == bsearch(a, n, &a[1], cmpObject, NotFound));
  assert(NotFound  == bsearch(a, n, &a[1], NULL, NotFound));
 
  printf("OK\n");
  return 0;
}