x = a1 mod m1
x = a2 mod m2

find x mod m1m2 ?
  
x = (a1 * m2 * q + a2 * m1 * p ) mod m1m2

where , 
      m1 * p + m2 * q = 1 
      solve this with egcd to find out p and q.

For multiple equation find this one by one.
x = a1 mod m1
x = a2 mod m2
x = a3 mod m3
.
.
.
x = an mod mn

