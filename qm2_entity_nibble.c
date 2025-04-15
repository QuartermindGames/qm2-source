// Copyright © 2020-2025 Quartermind Games, Mark E. Sowden <hogsy@snortysoft.net>
// Purpose: Nibbles are generic living things in the world.
// Author:  Mark E. Sowden

#include "../shared/game_private.h"
#include "../shared/components/component_movement.h"

#include "qm2_entity_nibble.h"

static void *create_nibble( ApeEntity *self, AcmBranch *properties )
{
	return PL_NEW( Qm2NibbleEntity );
}

static void destroy_nibble( ApeEntity *self )
{
	Qm2NibbleEntity *nibble = QM2_CLASS_NIBBLE( self );
	assert( nibble != nullptr );

	PL_DELETE( nibble );
}

static void spawn_nibble( ApeEntity *self )
{
	Qm2NibbleEntity *nibble = QM2_CLASS_NIBBLE( self );
	assert( nibble != nullptr );

	nibble->healthComponent    = ape_entity_add_component( self, "health" );
	nibble->movementComponent  = ape_entity_add_component( self, "movement" );
	nibble->collisionComponent = ape_entity_add_component( self, "collision" );
	nibble->inventoryComponent = ape_entity_add_component( self, "inventory" );
}

static void tick_nibble( ApeEntity *self, double delta )
{
	delta = game_get_time_delta_( delta );

	Qm2NibbleEntity *nibble = QM2_CLASS_NIBBLE( self );
	assert( nibble != nullptr );

	game_component_movement_tick_( nibble->movementComponent, self, delta );
}

ApeEntityClassDefinition qm2_nibbleEntityClass = {
        .name        = "nibble",
        .description = "Intelligent agent. Do not place manually, these will be spawned in procedurally!",

        //.cacheFunction   = cache_nibble,
        .createFunction  = create_nibble,
        .destroyFunction = destroy_nibble,
        .spawnFunction   = spawn_nibble,
        .tickFunction    = tick_nibble,
};
