#include "BigNumber.h"

BigNumber basic(BigNumber in, BigNumber p, BigNumber n) {
  return in.powMod(p,n);
}

BigNumber squareAndMultiply(BigNumber x, BigNumber y, BigNumber n) {
  BigNumber msb;
  BigNumber NUM_BITS = log2(y);
  for(msb = NUM_BITS; (y & (1 << msb)) == 0; msb--);
  BigNumber sum = x;
  for(BigNumber bit = msb-BigNumber("1"); bit >= BigNumber("0"); bit--) {
      sum *= sum;
      if((y & (1 << bit)) != 0) {
          sum *= x;
      }
  }
return (sum % n);
}

 //too memory consuming above

BigNumber jpl(BigNumber in, BigNumber p, BigNumber n) {
 //too memory consuming
  return in.powMod(p,n);
}

BigNumber encrypt(BigNumber n, BigNumber e, BigNumber m) {
  BigNumber c = jpl(m,e,n);
  return c;
}

BigNumber decrypt(BigNumber c, BigNumber d, BigNumber n) {
  BigNumber m = jpl(c,d,n);
  return m;
}
