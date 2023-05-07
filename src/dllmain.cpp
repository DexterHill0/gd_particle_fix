#include "includes.h"

// the scale of particles are set in `setVisible`
// rob's logic is weird man
int GameObject_setVisible(gd::GameObject* self, bool isVisible) {
    int unk = matdash::orig<&GameObject_setVisible>(self, isVisible);

    // scale the particles
    if (self->m_bUnkParticleSystem && self->m_pParticleSystem) {
        self->m_pParticleSystem->setScale(self->m_fScale);
    }

    return unk;
}

void mod_main(HMODULE) {
    matdash::add_hook<&GameObject_setVisible>(gd::base + 0x000E57C0);
}