#include "GeometryUtils.h"
#include <QtMath>

namespace GeometryUtils {

QVector<QPointF> regularPolygon(const QPointF &center, double radius, int sides)
{
    QVector<QPointF> points;
    points.reserve(sides);

    // Offset so polygon has a flat bottom edge
    double angleOffset = -M_PI / 2.0;

    for (int i = 0; i < sides; ++i) {
        double angle = angleOffset + (2.0 * M_PI * i) / sides;
        double x = center.x() + radius * std::cos(angle);
        double y = center.y() + radius * std::sin(angle);
        points.append(QPointF(x, y));
    }

    return points;
}

double distance(const QPointF &a, const QPointF &b)
{
    double dx = b.x() - a.x();
    double dy = b.y() - a.y();
    return std::sqrt(dx * dx + dy * dy);
}

QPair<QPointF, QPointF> perpendicularOffsets(const QPointF &start, const QPointF &end,
                                              double offset)
{
    QPointF normal = unitNormal(start, end);
    return {
        QPointF(normal.x() * offset, normal.y() * offset),
        QPointF(-normal.x() * offset, -normal.y() * offset)
    };
}

QPointF unitNormal(const QPointF &start, const QPointF &end)
{
    double dx = end.x() - start.x();
    double dy = end.y() - start.y();
    double len = std::sqrt(dx * dx + dy * dy);
    if (len < 1e-9) return QPointF(0, 0);
    // Normal is perpendicular: rotate 90 degrees
    return QPointF(-dy / len, dx / len);
}

QPointF lerp(const QPointF &start, const QPointF &end, double t)
{
    return QPointF(start.x() + t * (end.x() - start.x()),
                   start.y() + t * (end.y() - start.y()));
}

double angleBetween(const QPointF &start, const QPointF &end)
{
    return std::atan2(end.y() - start.y(), end.x() - start.x());
}

} // namespace GeometryUtils
