using Point = pair<double, double>;
Point operator+(Point &A, Point &B) { return Point(A.X+B.X, A.Y+B.Y); }
Point operator-(Point &A, Point &B) { return Point(A.X-B.X, A.Y-B.Y); }
Point operator*(double a, Point A) { return Point(a*A.X, a*A.Y); }
Point operator*(Point A, double a) { return a*A; }
double Dot(Point A, Point B) { return A.X*B.X + A.Y*B.Y; }
double Cross(Point A, Point B) { return A.X*B.Y - A.Y * B.X; }
double Distance(Point A, Point B) { return sqrt(Dot(A-B, A-B)); }

bool Circle(Point A, Point B, Point C, Point &cir) {
    double a1 = 2*(B.X - A.X), b1 = 2*(B.Y - A.Y), c1 = Dot(B, B) - Dot(A, A);
    double a2 = 2*(C.X - A.X), b2 = 2*(C.Y - A.Y), c2 = Dot(C, C) - Dot(A, A);
    // a1*x + b1*x = c1
    // a2*x + b2*x = c2
    double D = a1 * b2 - a2 * b1;
    if (dcmp(D) == 0) return false;
    cir = Point(c1 * b2 - c2 * b1, a1 * c2 - a2 * c1) * (1 / D);
    return true;
}

struct Line {
    Point A, B;
    double rad;
    Line(Point A=MK(0, 0), Point B=MK(0, 0)): A(A), B(B) { rad = getAngle(); }
    double getAngle() { return atan2((B-A).Y, (B-A).X); }
    Point getdir() { return B-A; }
    bool operator<(const Line &op) const {
        return dcmp(rad-op.rad) < 0;
    }
};

bool onLeft(Line l, Point p) { return dcmp(Cross(l.getdir(), p-l.A)) >= 0; }

bool intersect(Line l1, Line l2, Point &res) {
    double a1 = l1.getdir().X, b1 = -l2.getdir().X, c1 = l2.A.X - l1.A.X;
    double a2 = l1.getdir().Y, b2 = -l2.getdir().Y, c2 = l2.A.Y - l1.A.Y;
    double D = a1 * b2 - a2 * b1;
    if (dcmp(D) == 0) return false;
    double t1 = (c1 * b2 - c2 * b1) / D;
    res = l1.A + l1.getdir()*t1;
    return true;
}