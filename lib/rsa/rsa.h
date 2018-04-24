#include "BigNumber.h"

BigNumber jpl(BigNumber in, BigNumber p, BigNumber n) {
 BigNumber res = BigNumber("1");
  for(BigNumber i = BigNumber("0"); i < p; i++){
    res = (in*res)%n;
  }
 return res;
}

BigNumber encrypt(BigNumber n, BigNumber e, BigNumber m) {
  BigNumber c = jpl(m,e,n);
  return c;
}

BigNumber decrypt(BigNumber c, BigNumber d, BigNumber n) {
  BigNumber m = jpl(c,d,n);
  return m;
}
