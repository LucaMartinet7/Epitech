#!/usr/bin/python3
import math
import sys

if len(sys.argv) != 8:
        sys.stderr.write("Bad numbers of argument.\n")
        exit (84)

try :
    Ax = float(sys.argv[1])
    Ay = float(sys.argv[2])
    Az = float(sys.argv[3])
    Bx = float(sys.argv[4])
    By = float(sys.argv[5])
    Bz = float(sys.argv[6])
    n = int(sys.argv[7])

except ValueError:
    sys.stderr.write("ERROR\n")
    exit (84)

if int(sys.argv[7]) < 0:
    sys.stderr.write("time shift cannot be negative.\n")
    exit (84)

x = Bx - Ax
y = By - Ay
z = Bz - Az
print("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)" %(x, y ,z))

xn = Bx + (x * n)
yn = By + (y * n)
zn = Bz + (z * n)
print("At time t +", n," ball coordinates will be:\n(%.2f, %.2f, %.2f)" %(xn, yn ,zn))

check_norme = math.sqrt((x**2 + y**2 + z**2))
if check_norme != 0:
    norme = check_norme
    radians = math.asin(math.sqrt(z**2) / norme)
    angle = math.degrees(radians)

else:
    norme = 0

if ((Bz >= 0 and z < 0) or (Bz <= 0 and z > 0)):
    print("The incidence angle is:\n", "%.2f"%angle, "degrees")
else:
    print("The ball won't reach the paddle.")
exit (0)