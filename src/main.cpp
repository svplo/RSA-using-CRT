#include <Arduino.h>
#include <rsa.h>
void setup() {
  Serial.begin (9600);
  bc_init_numbers ();  // initialize library
}

void loop() {
  /*
    BigNumber p = BigNumber("221102400398035299023528202047696432939");
    BigNumber q = BigNumber("313109253626953103148951688045552192811");

    BigNumber n = BigNumber("69229207563756571188118786364132105617154621697450696600015683963634259401529");
    BigNumber phin = BigNumber("69229207563756571188118786364132105616620410043425708197843204073541010775780");
    BigNumber e = BigNumber("3");
    BigNumber d = BigNumber("46152805042504380792079190909421403744413606695617138798562136049027340517187");
    BigNumber m = BigNumber("10");

    BigNumber c;
    BigNumber mm = BigNumber("2433");

   c = encrypt(m,e,n);

   BigNumber p = BigNumber("7");
   BigNumber q = BigNumber("19");
   BigNumber ONE = BigNumber("1");
   BigNumber n = p * q;
   BigNumber phin = (p-ONE) * (q -ONE);
   BigNumber e = BigNumber("5");
   BigNumber d = BigNumber("65");
   BigNumber m = BigNumber("117");
   BigNumber dp = BigNumber("5");
   BigNumber dq = BigNumber("11");
   BigNumber cp = BigNumber("3");
   BigNumber cq = BigNumber("11");
   */
   BigNumber p = BigNumber("221102400398035299023528202047696432939");
   BigNumber q = BigNumber("313109253626953103148951688045552192811");

   BigNumber n = BigNumber("69229207563756571188118786364132105617154621697450696600015683963634259401529");
   BigNumber phin = BigNumber("69229207563756571188118786364132105616620410043425708197843204073541010775780");
   BigNumber e = BigNumber("3");
   BigNumber d = BigNumber("46152805042504380792079190909421403744413606695617138798562136049027340517187");
   BigNumber m = BigNumber("57896044618658097711785492504343953926634992332820282019728792003956564819968");

   BigNumber dp = BigNumber("147401600265356866015685468031797621959");
   BigNumber dq = BigNumber("208739502417968735432634458697034795207");
   BigNumber cp = BigNumber("31517523594815955005281873335558419960");
   BigNumber cq = BigNumber("268476412594122788603504099537575362230");
    // signing by decrypting message
    BigNumber mm = crt(p, q, n,d,m, dp, cp, dq, cq);

    Serial.printf("%s\n", "decrypted message");
    Serial.printf("%s\n", mm.toString());
//    Serial.printf("%s\n", "decrypted message");
//    Serial.printf("%s\n", mm.toString());

    delay(5000);
}
