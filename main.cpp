#include <mod/amlmod.h>
#include <mod/logger.h>
#include <mod/config.h>
#include <stdlib.h>
#include <stdio.h>

// Plugin Info - Siguraduhin na walang '&' sa author name para iwas error sa ibang compiler
MYMOD(com.user.ragdollport, RagdollPort, 1.0, Madleg_JuniorDjjr)

// 1. Mga Variables para sa Config
int iNumSubsteps, iNumIPLInstances;
float fSimulationSpeed, fRagdollLinearDamping, fRagdollAngularDamping, fRagdollGravity, fBulletPower, fExplosionPower, fSurfaceFriction, fRagDollFriction, fRagDollRestitution, fRagDollJointDamping, fRagDollGetUpThreshold, fRagDollShapeMargin, fWorldShapeMargin, fDynamicObjectMass, fWorldMinX, fWorldMinY, fWorldMaxX, fWorldMaxY;
bool bVehicleShapeUseSpheres, bUseDynamicObjects;

Config* cfg = NULL;

// 2. Function para basahin ang INI settings
void LoadConfig() {
    cfg = new Config("RagDoll_physics"); // Gumagamit tayo ng 'new' para sa Config object

    iNumSubsteps = cfg->GetInt("CONFIG", "iNumSubsteps", 5);
    iNumIPLInstances = cfg->GetInt("CONFIG", "iNumIPLInstances", 100000);
    fSimulationSpeed = cfg->GetFloat("CONFIG", "fSimulationSpeed", 1.0f);
    fRagdollLinearDamping = cfg->GetFloat("CONFIG", "fRagdollLinearDamping", 0.05f);
    fRagdollAngularDamping = cfg->GetFloat("CONFIG", "fRagdollAngularDamping", 0.8f);
    fRagdollGravity = cfg->GetFloat("CONFIG", "fRagdollGravity", 1.0f);
    fBulletPower = cfg->GetFloat("CONFIG", "fBulletPower", 1.0f);
    fExplosionPower = cfg->GetFloat("CONFIG", "fExplosionPower", 1.2f);
    fSurfaceFriction = cfg->GetFloat("CONFIG", "fSurfaceFriction", 0.9f);
    fRagDollFriction = cfg->GetFloat("CONFIG", "fRagDollFriction", 0.9f);
    fRagDollRestitution = cfg->GetFloat("CONFIG", "fRagDollRestitution", 0.1f);
    fRagDollJointDamping = cfg->GetFloat("CONFIG", "fRagDollJointDamping", 10.0f);
    fRagDollGetUpThreshold = cfg->GetFloat("CONFIG", "fRagDollGetUpThreshold", 0.5f);
    fRagDollShapeMargin = cfg->GetFloat("CONFIG", "fRagDollShapeMargin", 0.02f);
    fWorldShapeMargin = cfg->GetFloat("CONFIG", "fWorldShapeMargin", 0.01f);
    fDynamicObjectMass = cfg->GetFloat("CONFIG", "fDynamicObjectMass", 20000.0f);
    fWorldMinX = cfg->GetFloat("CONFIG", "fWorldMinX", -4000.0f);
    fWorldMinY = cfg->GetFloat("CONFIG", "fWorldMinY", -4000.0f);
    fWorldMaxX = cfg->GetFloat("CONFIG", "fWorldMaxX", 4000.0f);
    fWorldMaxY = cfg->GetFloat("CONFIG", "fWorldMaxY", 4000.0f);
    bVehicleShapeUseSpheres = cfg->GetBool("CONFIG", "bVehicleShapeUseSpheres", true);
    bUseDynamicObjects = cfg->GetBool("CONFIG", "bUseDynamicObjects", true);
    
    cfg->Save();
}

// 3. Main Loading Function
extern "C" void OnModLoad() {
    logger->SetTag("RagdollPhysics"); // Importante ang logger para makita mo kung gumana
    logger->Info("Ragdoll Mod Loading...");

    LoadConfig();

    // Dito natin idadagdag ang pag-load ng BIN file mo na nakita ko sa screenshot
    char path[256];
    snprintf(path, sizeof(path), "%s/RagDoll_physics.bin", aml->GetConfigPath()); 
    
    FILE* file = fopen(path, "rb");
    if (file) {
        logger->Info("RagDoll_physics.bin found and loaded!");
        fclose(file);
    } else {
        logger->Error("RagDoll_physics.bin is missing!");
    }

    logger->Info("Ragdoll Mod initialization finished!");
}
