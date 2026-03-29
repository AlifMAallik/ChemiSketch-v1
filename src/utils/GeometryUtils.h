#ifndef GEOMETRYUTILS_H
#define GEOMETRYUTILS_H

#include <QPointF>
#include <QVector>
#include <QLineF>

namespace GeometryUtils {

// Generate vertices of a regular polygon centered at `center` with flat bottom.
QVector<QPointF> regularPolygon(const QPointF &center, double radius, int sides);

// Distance between two points.
double distance(const QPointF &a, const QPointF &b);

// Compute perpendicular offset points for parallel lines (used for double/triple bonds).
QPair<QPointF, QPointF> perpendicularOffsets(const QPointF &start, const QPointF &end,
                                              double offset);

// Unit normal to a line segment.
QPointF unitNormal(const QPointF &start, const QPointF &end);

// Point along line at parametric t (0 = start, 1 = end).
QPointF lerp(const QPointF &start, const QPointF &end, double t);

// Angle in radians from start to end.
double angleBetween(const QPointF &start, const QPointF &end);

} // namespace GeometryUtils

#endif // GEOMETRYUTILS_H
