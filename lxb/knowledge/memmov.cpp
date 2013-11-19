void *memmove(void *src, void *dst, size_t n)
{
  if (n == 0 || src == dst) return;

  char *cs = src;
  char *cd = dst;

  if (cd < cs) { 
       while (n--) {
          *cd = *cs;
           cd ++;
           cs ++;
       }
  } else {
     cd += n;
     cs += n;
     while (n--) {
        *cd = *cs;
         cd --;
         cs --;
     }
  }

  return dst;
}
