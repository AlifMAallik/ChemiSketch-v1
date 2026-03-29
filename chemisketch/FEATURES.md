# ChemiSketch — Feature Roadmap & Plugin Registry

> **How to add a new feature:**
> 1. Find the correct section below
> 2. Add a new row to the table with Name, Description, and Status
> 3. Use the Status Key at the bottom
> 4. Future automation will auto-wire it into the sidebar/toolbar/menu

---

## 🖊️ Sketch Area Features
| Feature | Description | Status |
|---|---|---|
| Atom Tool | Place atoms on canvas | ✅ Done |
| Bond Tool | Draw single/double/triple bonds | ✅ Done |
| Ring Templates | Benzene, cyclohexane, cyclopentane presets | 🔄 In Progress |
| Charge Tool | Add +/- charges to atoms | 📋 Planned |
| Eraser Tool | Remove atoms and bonds | 📋 Planned |
| Undo / Redo | Full history stack (Ctrl+Z / Ctrl+Y) | 📋 Planned |
| Lasso Select | Select a region of the molecule | 📋 Planned |
| Move Tool | Drag atoms and fragments | 📋 Planned |
| Auto Clean | Auto-arrange and normalize molecule layout | 💡 Idea |
| Stereo Bonds | Wedge and dash stereo bond drawing | 💡 Idea |
| Atom Labels | Custom text labels on atoms | 💡 Idea |
| Copy / Paste | Duplicate molecular fragments | 💡 Idea |
| Snap to Grid | Align atoms to invisible grid | 💡 Idea |

---

## 🔬 3D View Features
| Feature | Description | Status |
|---|---|---|
| Ball & Stick | Classic 3D ball and stick render mode | 📋 Planned |
| Space Fill (CPK) | CPK sphere model showing van der Waals radii | 📋 Planned |
| Wireframe | Lightweight wireframe render mode | 📋 Planned |
| Stick Only | Bonds only, no atom spheres | 📋 Planned |
| Mouse Rotation | Click and drag to rotate molecule | 📋 Planned |
| Scroll Zoom | Scroll wheel to zoom in/out | 📋 Planned |
| Auto Rotate | Slow continuous spin animation | 📋 Planned |
| Lighting Presets | Studio / Lab / Dark environment lighting | 💡 Idea |
| Atom Color Scheme | CPK colors, monochrome, custom | 💡 Idea |
| Export 3D | Save as .obj / .stl / .pdb file | 💡 Idea |
| Measurement Tool | Show bond lengths and angles in 3D | 💡 Idea |
| Surface Render | Electron density / solvent surface | 💡 Idea |

---

## 🔍 Search Molecule Features
| Feature | Description | Status |
|---|---|---|
| Search by Name | IUPAC and common name lookup | 📋 Planned |
| Search by Formula | e.g. C6H6, H2O | 📋 Planned |
| Search by SMILES | Paste a SMILES string to load | 📋 Planned |
| PubChem Integration | Pull structure data from PubChem API | 📋 Planned |
| Recent Molecules | History list of recently viewed molecules | 📋 Planned |
| Favorites | Star and save molecules to a personal list | 💡 Idea |
| Similarity Search | Find structurally similar molecules | 💡 Idea |
| Substructure Search | Search molecules containing a fragment | 💡 Idea |
| ChemSpider Integration | Additional database lookup | 💡 Idea |

---

## 📊 Properties Panel Features
| Feature | Description | Status |
|---|---|---|
| Molecular Weight | Auto-calculate MW from structure | 📋 Planned |
| Molecular Formula | Display formula e.g. C6H6 | 📋 Planned |
| SMILES Export | Export structure as SMILES string | 📋 Planned |
| InChI / InChIKey | Generate standard InChI identifier | 📋 Planned |
| Atom Count | Total atom and bond count display | 📋 Planned |
| Exact Mass | Monoisotopic exact mass calculation | 💡 Idea |
| LogP | Estimated lipophilicity value | 💡 Idea |
| H-Bond Donors/Acceptors | Lipinski rule-of-five properties | 💡 Idea |
| Rotatable Bonds | Count of rotatable bonds | 💡 Idea |

---

## ⚗️ Reactions Features
| Feature | Description | Status |
|---|---|---|
| Reaction Arrow Tool | Draw single and double-headed reaction arrows | 💡 Idea |
| Reaction Builder | Set up A + B → C on canvas | 💡 Idea |
| Reagent Labels | Add text above/below reaction arrows | 💡 Idea |
| Mechanism Viewer | Step-through electron-pushing mechanism | 💡 Idea |
| Equilibrium Arrow | Draw reversible reaction arrows | 💡 Idea |
| Retrosynthesis Mode | Draw retrosynthetic disconnections | 💡 Idea |

---

## 📁 File & Export Features
| Feature | Description | Status |
|---|---|---|
| Save Project | Save as native .csk project file | 📋 Planned |
| Open Project | Load existing .csk file | 📋 Planned |
| Export PNG | Export canvas as PNG image | 📋 Planned |
| Export SVG | Export as scalable vector graphic | 📋 Planned |
| Export PDF | Export as PDF document | 📋 Planned |
| Export MOL | Export as .mol / .sdf structure file | 💡 Idea |
| Export PDB | Export as .pdb for 3D tools | 💡 Idea |
| Import MOL/SDF | Load structures from .mol/.sdf files | 💡 Idea |
| Import PDB | Load 3D structure from .pdb file | 💡 Idea |
| Auto-save | Periodic background save | 💡 Idea |

---

## 🎨 UI / UX Features
| Feature | Description | Status |
|---|---|---|
| Dark Theme | Default deep navy dark mode | ✅ Done |
| Bottom Tab Bar | Animated switcher between Sketch/3D/Search/etc. | 🔄 In Progress |
| Glassmorphism Panels | Frosted glass sidebar and floating panels | 🔄 In Progress |
| Top Menu Bar | File, Edit, View, Window, Help | 🔄 In Progress |
| Smooth Animations | Spring animations on tab and panel transitions | 📋 Planned |
| Collapsible Sidebar | Expand/collapse sidebar sections | 📋 Planned |
| Keyboard Shortcuts | Full shortcut map for all tools | 📋 Planned |
| Tooltips | Hover tooltips on all toolbar icons | 📋 Planned |
| Light Theme | Optional light mode | 💡 Idea |
| Custom Accent Color | User-selectable accent color | 💡 Idea |
| Zoom In/Out Canvas | Canvas zoom controls | 💡 Idea |
| Full Screen Mode | Distraction-free full screen | 💡 Idea |
| Split View | Side-by-side Sketch and 3D view | 💡 Idea |

---

## ⌨️ Keyboard Shortcuts (Planned)
| Shortcut | Action |
|---|---|
| `Ctrl + Z` | Undo |
| `Ctrl + Y` | Redo |
| `Ctrl + S` | Save |
| `Ctrl + N` | New file |
| `Ctrl + O` | Open file |
| `Ctrl + E` | Export |
| `1` | Select atom tool |
| `2` | Select bond tool |
| `3` | Eraser tool |
| `Space` | Pan canvas |
| `F` | Fit molecule to screen |
| `Tab` | Switch to next bottom tab |

---

## 🔌 Future Plugin / Extension Ideas
| Plugin | Description |
|---|---|
| AI Molecule Generator | Type a description, generate a molecule |
| Spectroscopy Viewer | Simulated IR / NMR spectra |
| Docking Preview | Basic protein-ligand docking visualization |
| Periodic Table Panel | Interactive element picker |
| Batch Processing | Process multiple molecules at once |
| Collaboration Mode | Real-time multi-user sketching |

---

## Status Key
| Symbol | Meaning |
|---|---|
| ✅ Done | Fully implemented and working |
| 🔄 In Progress | Currently being built |
| 📋 Planned | Confirmed for development |
| 💡 Idea | Proposed, not yet committed |
| ❌ Dropped | Decided against, kept for history |

---

*Last updated: 2026-03-28*
*To suggest a feature, add a row with status 💡 Idea*
