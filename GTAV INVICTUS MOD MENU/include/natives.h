#pragma once
#include <stdint.h>

typedef void* (*NativeArg)();
typedef void* (*NativeCall)(uint64_t hash, NativeArg arg);

namespace Natives {
    int PLAYER_PED_ID();
    void SET_ENTITY_INVINCIBLE(int entity, bool toggle);
    void SET_PLAYER_INVINCIBLE(int player, bool toggle);
    int GET_ENTITY_HEALTH(int entity);
    void SET_ENTITY_HEALTH(int entity, int health);
}
