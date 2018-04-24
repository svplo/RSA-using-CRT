#include <Arduino.h>
#include <rsa.h>
void setup() {
  Serial.begin (9600);
  bc_init_numbers ();  // initialize library
}

void loop() {
    BigNumber p = BigNumber("221102400398035299023528202047696432939");
    BigNumber q = BigNumber("313109253626953103148951688045552192811");

    BigNumber n = BigNumber("69229207563756571188118786364132105617154621697450696600015683963634259401529");
    BigNumber phin = BigNumber("69229207563756571188118786364132105616620410043425708197843204073541010775780");
    BigNumber e = BigNumber("3");
    BigNumber d = BigNumber("46152805042504380792079190909421403744413606695617138798562136049027340517187");
    BigNumber m = BigNumber("1345");

    BigNumber c;
    BigNumber mm = BigNumber("2433");

   c = encrypt(m,e,n);
    // signing by decrypting message
  //  mm = decrypt(m,d,n);

    Serial.printf("%s\n", "encrypted message");
    Serial.printf("%s\n", c.toString());
//    Serial.printf("%s\n", "decrypted message");
//    Serial.printf("%s\n", mm.toString());

    delay(5000);
}
