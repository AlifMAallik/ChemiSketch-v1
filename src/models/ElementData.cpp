#include "ElementData.h"

ElementData *ElementData::s_instance = nullptr;

ElementData::ElementData(QObject *parent)
    : QObject(parent)
{
    s_instance = this;
    initializeElements();
}

ElementData *ElementData::instance()
{
    if (!s_instance) {
        s_instance = new ElementData();
    }
    return s_instance;
}

void ElementData::initializeElements()
{
    // Common organic + inorganic elements with valence data
    // Format: symbol, name, atomicNumber, atomicWeight, maxValence, commonValences, color, category

    auto add = [this](const QString &sym, const QString &name, int num, double weight,
                      int maxVal, QVector<int> valences, QColor color, const QString &cat) {
        m_elements[sym] = {sym, name, num, weight, maxVal, valences, color, cat};
    };

    // Non-metals
    add("H",  "Hydrogen",    1,   1.008,  1, {1},       QColor(255,255,255), "non_metal");
    add("He", "Helium",      2,   4.003,  0, {0},       QColor(217,255,255), "noble_gas");
    add("C",  "Carbon",      6,  12.011,  4, {4},       QColor(144,144,144), "non_metal");
    add("N",  "Nitrogen",    7,  14.007,  3, {3},       QColor(48,80,248),   "non_metal");
    add("O",  "Oxygen",      8,  15.999,  2, {2},       QColor(255,13,13),   "non_metal");
    add("F",  "Fluorine",    9,  18.998,  1, {1},       QColor(144,224,80),  "non_metal");
    add("Ne", "Neon",       10,  20.180,  0, {0},       QColor(179,227,245), "noble_gas");
    add("P",  "Phosphorus", 15,  30.974,  5, {3,5},     QColor(255,128,0),   "non_metal");
    add("S",  "Sulfur",     16,  32.065,  6, {2,4,6},   QColor(255,255,48),  "non_metal");
    add("Cl", "Chlorine",   17,  35.453,  7, {1,3,5,7}, QColor(31,240,31),   "non_metal");
    add("Ar", "Argon",      18,  39.948,  0, {0},       QColor(128,209,227), "noble_gas");
    add("Se", "Selenium",   34,  78.971,  6, {2,4,6},   QColor(255,161,0),   "non_metal");
    add("Br", "Bromine",    35,  79.904,  7, {1,3,5,7}, QColor(166,41,41),   "non_metal");
    add("I",  "Iodine",     53, 126.904,  7, {1,3,5,7}, QColor(148,0,148),   "non_metal");

    // Metalloids
    add("B",  "Boron",       5,  10.811,  3, {3},       QColor(255,181,181), "metalloid");
    add("Si", "Silicon",    14,  28.086,  4, {4},       QColor(240,200,160), "metalloid");
    add("Ge", "Germanium",  32,  72.630,  4, {2,4},     QColor(102,143,143), "metalloid");
    add("As", "Arsenic",    33,  74.922,  5, {3,5},     QColor(189,128,227), "metalloid");
    add("Sb", "Antimony",   51, 121.760,  5, {3,5},     QColor(158,99,181),  "metalloid");
    add("Te", "Tellurium",  52, 127.600,  6, {2,4,6},   QColor(212,122,0),   "metalloid");
    add("Po", "Polonium",   84, 208.982,  6, {2,4,6},   QColor(171,92,0),    "metalloid");

    // Common metals
    add("Li", "Lithium",     3,   6.941,  1, {1},       QColor(204,128,255), "metal");
    add("Be", "Beryllium",   4,   9.012,  2, {2},       QColor(194,255,0),   "metal");
    add("Na", "Sodium",     11,  22.990,  1, {1},       QColor(171,92,242),  "metal");
    add("Mg", "Magnesium",  12,  24.305,  2, {2},       QColor(138,255,0),   "metal");
    add("Al", "Aluminum",   13,  26.982,  3, {3},       QColor(191,166,166), "metal");
    add("K",  "Potassium",  19,  39.098,  1, {1},       QColor(143,64,212),  "metal");
    add("Ca", "Calcium",    20,  40.078,  2, {2},       QColor(61,255,0),    "metal");
    add("Ti", "Titanium",   22,  47.867,  4, {2,3,4},   QColor(191,194,199), "metal");
    add("Cr", "Chromium",   24,  51.996,  6, {2,3,6},   QColor(138,153,199), "metal");
    add("Mn", "Manganese",  25,  54.938,  7, {2,4,7},   QColor(156,122,199), "metal");
    add("Fe", "Iron",       26,  55.845,  6, {2,3,6},   QColor(224,102,51),  "metal");
    add("Co", "Cobalt",     27,  58.933,  4, {2,3},     QColor(240,144,160), "metal");
    add("Ni", "Nickel",     28,  58.693,  4, {2,3},     QColor(80,208,80),   "metal");
    add("Cu", "Copper",     29,  63.546,  2, {1,2},     QColor(200,128,51),  "metal");
    add("Zn", "Zinc",       30,  65.380,  2, {2},       QColor(125,128,176), "metal");
    add("Ag", "Silver",     47, 107.868,  1, {1},       QColor(192,192,192), "metal");
    add("Sn", "Tin",        50, 118.710,  4, {2,4},     QColor(102,128,128), "metal");
    add("Au", "Gold",       79, 196.967,  3, {1,3},     QColor(255,209,35),  "metal");
    add("Pt", "Platinum",   78, 195.084,  4, {2,4},     QColor(208,208,224), "metal");
    add("Pb", "Lead",       82, 207.200,  4, {2,4},     QColor(87,89,97),    "metal");
    add("Hg", "Mercury",    80, 200.592,  2, {1,2},     QColor(184,184,208), "metal");
}

int ElementData::maxValence(const QString &symbol) const
{
    auto it = m_elements.find(symbol);
    return (it != m_elements.end()) ? it->maxValence : 4; // default to carbon-like
}

QVector<int> ElementData::commonValences(const QString &symbol) const
{
    auto it = m_elements.find(symbol);
    return (it != m_elements.end()) ? it->commonValences : QVector<int>{4};
}

QString ElementData::elementName(const QString &symbol) const
{
    auto it = m_elements.find(symbol);
    return (it != m_elements.end()) ? it->name : QString();
}

int ElementData::atomicNumber(const QString &symbol) const
{
    auto it = m_elements.find(symbol);
    return (it != m_elements.end()) ? it->atomicNumber : 0;
}

double ElementData::atomicWeight(const QString &symbol) const
{
    auto it = m_elements.find(symbol);
    return (it != m_elements.end()) ? it->atomicWeight : 0.0;
}

QColor ElementData::elementColor(const QString &symbol) const
{
    auto it = m_elements.find(symbol);
    return (it != m_elements.end()) ? it->color : QColor(200, 200, 200);
}

QString ElementData::classify(const QString &symbol) const
{
    auto it = m_elements.find(symbol);
    return (it != m_elements.end()) ? it->category : "unknown";
}

bool ElementData::isValidElement(const QString &symbol) const
{
    return m_elements.contains(symbol);
}

QStringList ElementData::allSymbols() const
{
    return m_elements.keys();
}
