// Copyright © 2020-2025 Quartermind Games, Mark E. Sowden <hogsy@snortysoft.net>

#pragma once

#include "../shared/game_private.h"

#define QM2_PROTOCOL_VERSION ( GAME_NET_PROTOCOL_VERSION + 2 )

typedef struct Qm2GameState
{
	AcmBranch *config;

	ApeCamera *camera;
} Qm2GameState;
extern Qm2GameState qm2_gameState;
