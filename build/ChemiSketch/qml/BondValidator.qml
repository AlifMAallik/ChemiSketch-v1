import QtQuick
import ChemiSketch 1.0

QtObject {
    id: root

    required property ChemController controller

    // Check if a bond of the given type can be created between two atoms.
    // Returns an object: { valid: bool, reason: string }
    function canCreateBond(atom1Id, atom2Id, bondType) {
        if (!controller) return { valid: false, reason: "No controller" }

        var valence = bondValenceForType(bondType)

        var remaining1 = controller.remainingValence(atom1Id)
        var remaining2 = controller.remainingValence(atom2Id)

        if (remaining1 < valence) {
            return {
                valid: false,
                reason: "Atom 1 exceeds max valence (remaining: " + remaining1 + ")",
                rejectedAtomId: atom1Id
            }
        }
        if (remaining2 < valence) {
            return {
                valid: false,
                reason: "Atom 2 exceeds max valence (remaining: " + remaining2 + ")",
                rejectedAtomId: atom2Id
            }
        }

        return { valid: true, reason: "" }
    }

    // Check if a single atom can accept any more bonds at all.
    function canAtomBond(atomId) {
        if (!controller) return false
        return controller.remainingValence(atomId) >= 1.0
    }

    function bondValenceForType(bondType) {
        switch (bondType) {
        case "single_bond":
        case "single":
        case "wedge":
        case "hash":
        case "dashed":
            return 1.0
        case "double_bond":
        case "double":
            return 2.0
        case "triple_bond":
        case "triple":
            return 3.0
        case "aromatic":
            return 1.5
        case "arrow":
            return 0.0
        default:
            return 1.0
        }
    }
}
