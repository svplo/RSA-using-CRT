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
  BigNumber A = BigNumber("1");
  std::vector<BigNumber> table;
  BigNumber ONE = BigNumber("1");
   table.push_back(ONE);
  for (BigNumber i = BigNumber("1"); i <= log2(p) - 1; ++i){
    table.push_back(table.at(i-BigNumber("1")) * in);
  }

  Serial.printf("%s\n", "log");
  Serial.printf("%f\n", log2(p));
  Serial.printf("%s\n", "back");
  Serial.printf("%d\n",table.back().toString());
/*
  A = table.back();
  for(BigNumber i = log2(p); i >= 0; --i){
    A = A.powMod(2,n);
    A = A * table.at(i) % n;
  }
  */
  return A;
}

BigNumber crt(BigNumber p, BigNumber q, BigNumber n, BigNumber d, BigNumber c, BigNumber dp, BigNumber cp, BigNumber dq, BigNumber cq) {
  BigNumber xp = c % p;
  BigNumber xq = c % q;
  BigNumber yp = xp.powMod(dp, p);
  BigNumber yq = xq.powMod(dq, q);
  return (q * cp * yp + p * cq * yq) % n;
}


BigNumber encrypt(BigNumber n, BigNumber e, BigNumber m) {
  BigNumber c = jpl(m,e,n);
  return c;
}

BigNumber decrypt(BigNumber c, BigNumber d, BigNumber n) {
  BigNumber m = jpl(c,d,n);
  return m;
}
