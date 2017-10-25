const double EPS = 1.0e-6;

struct Vector3 {
  double x, y, z;

  Vector3 operator+(const Vector3& other) const {
    return {x + other.x, y + other.y, z + other.z};
  }

  Vector3 operator-(const Vector3& other) const {
    return {x - other.x, y - other.y, z - other.z};
  }

  double Dot(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
  }

  // Cross product of two vectors is a normal to a plane spanned by them.
  // Cross product of collinear vectors is 0.
  Vector3 Cross(const Vector3& other) const {
    return {
      y * other.z - z * other.y,
      z * other.x - x * other.z,
      x * other.y - y * other.x
    };
  }
};

Vector3 operator-(const Vector3& v) {
  return {-v.x, -v.y, -v.z};
}

struct Plane {
  // Ax + By + Cz + D = 0
  double a, b, c, d;

  bool Contains(const Vector3& point) const {
    return abs(a * point.x + b * point.y + c * point.z + d) <= EPS;
  }

  // Assumes that the points are not collinear.
  static Plane FromPoints(const Vector3& a, const Vector3& b, const Vector3& c) {
    Vector3 normal = (b - a).Cross(c - a);
    double A = normal.x, B = normal.y, C = normal.z;
    double D = -normal.Dot(a);

    return {A,B,C,D};
  }
};
