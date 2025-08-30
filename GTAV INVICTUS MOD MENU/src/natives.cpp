#include "natives.h"

// Déclaré dans main.cpp
extern NativeCall nativeCall;

// Hashes pour GTA V 1.53
#define HASH_PLAYER_PED_ID        0x12E82C
#define HASH_SET_ENTITY_INVINCIBLE 0x3BAE0C
#define HASH_SET_PLAYER_INVINCIBLE 0x2395FC
#define HASH_GET_ENTITY_HEALTH     0x3B8558
#define HASH_SET_ENTITY_HEALTH     0x3BA164

// === Helpers pour appels natifs ===
template<typename R>
R invoke(uint64_t hash) {
    NativeArg args = []() -> void* { return nullptr; };
    return (R)(uintptr_t)nativeCall(hash, args);
}

template<typename R, typename T1>
R invoke(uint64_t hash, T1 p1) {
    NativeArg args = [p1]() -> void* {
        static uint64_t data[] = { (uint64_t)p1 };
        return data;
        };
    return (R)(uintptr_t)nativeCall(hash, args);
}

template<typename R, typename T1, typename T2>
R invoke(uint64_t hash, T1 p1, T2 p2) {
    NativeArg args = [p1, p2]() -> void* {
        static uint64_t data[] = { (uint64_t)p1, (uint64_t)p2 };
        return data;
        };
    return (R)(uintptr_t)nativeCall(hash, args);
}

// === Implémentations natives ===
namespace Natives {
    int PLAYER_PED_ID() {
        return invoke<int>(HASH_PLAYER_PED_ID);
    }

    void SET_ENTITY_INVINCIBLE(int entity, bool toggle) {
        invoke<void>(HASH_SET_ENTITY_INVINCIBLE, entity, toggle);
    }

    void SET_PLAYER_INVINCIBLE(int player, bool toggle) {
        invoke<void>(HASH_SET_PLAYER_INVINCIBLE, player, toggle);
    }

    int GET_ENTITY_HEALTH(int entity) {
        return invoke<int>(HASH_GET_ENTITY_HEALTH, entity);
    }

    void SET_ENTITY_HEALTH(int entity, int health) {
        invoke<void>(HASH_SET_ENTITY_HEALTH, entity, health);
    }
}
