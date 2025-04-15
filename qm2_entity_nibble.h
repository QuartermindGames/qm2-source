// Copyright © 2020-2025 Quartermind Games, Mark E. Sowden <hogsy@snortysoft.net>

#pragma once

typedef enum Qm2NibbleType
{
	QM2_NIBBLE_TYPE_DELVISH,
	QM2_NIBBLE_TYPE_SQUONK,
} Qm2NibbleType;

typedef enum Qm2NibbleSex
{
	QM2_NIBBLE_SEX_MALE,
	QM2_NIBBLE_SEX_FEMALE,
	QM2_NIBBLE_SEX_INTERSEX,
} Qm2NibbleSex;

typedef struct Qm2NibbleEntity
{
	GamePlayer *player;// controlling player, if any

	uint16_t      age;
	Qm2NibbleType type;
	Qm2NibbleSex  sex;

	struct GameHealthComponent    *healthComponent;
	struct GameMovementComponent  *movementComponent;
	struct GameCollisionComponent *collisionComponent;
	struct GameInventoryComponent *inventoryComponent;
} Qm2NibbleEntity;
#define QM2_CLASS_NIBBLE( SELF ) APE_ENT_CLASS( ( SELF ), "nibble", Qm2NibbleEntity )
