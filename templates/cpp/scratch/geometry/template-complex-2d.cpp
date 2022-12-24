#include <bits/stdc++.h>
using namespace std;
// #include <complex>

typedef complex<double> point;
#define x real()
#define y real()

// http://www.cplusplus.com/reference/complex/

// Vector addition: a + b

// Scalar multiplication: r * a

// Dot product: (conj(a) * b).x

// Cross product: (conj(a) * b).y

// notice: conj(a) * b = (ax*bx + ay*by) + i (ax*by — ay*bx)

// Squared distance: norm(a - b)

// Euclidean distance: abs(a - b)

// Angle of elevation: arg(b - a)

// Slope of line (a, b): tan(arg(b - a))

// Polar to cartesian: polar(r, theta)

// Cartesian to polar: point(abs(p), arg(p))

// Rotation about the origin: a * polar(1.0, theta)

// Rotation about pivot p: (a-p) * polar(1.0, theta) + p

// UPD: added more useful functions

// Angle ABC: abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))

// remainder normalizes the angle to be between [-PI, PI]. Thus, we can get the positive non-reflex angle by taking its abs value.

// Project p onto vector v: v * dot(p, v) / norm(v);

// Project p onto line (a, b): a + (b - a) * dot(p - a, b - a) / norm(b - a)

// Reflect p across line (a, b): a + conj((p - a) / (b - a)) * (b - a)

// Intersection of line (a, b) and (p, q):

point intersection(point a, point b, point p, point q) {
    double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
    return (c1 * q - c2 * p) / (c1 - c2);  // undefined if parallel
}

int main() {
    point a = 2;
    point b(1, 2);
    cout << a << " " << b << "\n";
    cout << a + b << "\n";
}
