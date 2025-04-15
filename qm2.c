// Copyright © 2020-2025 Quartermind Games, Mark E. Sowden <hogsy@snortysoft.net>

#include "qm2.h"

#include "../shared/game_server.h"
#include "../shared/game_client.h"

Qm2GameState qm2_gameState;

//TODO: we need to migrate all the QM1 menu logic into shared!!!
bool game_menu_is_open() { return false; }

static bool initialize_game()
{
	PL_ZERO_( qm2_gameState );

	qm2_gameState.config = com_get_config( "qm2" );

	game_register_standard_entity_components_();

	qm2_gameState.camera = ape_create_camera( nullptr, nullptr, &pl_vecOrigin3, &pl_vecOrigin3, APE_CAMERA_MODE_PERSPECTIVE, APE_CAMERA_DRAW_MODE_SHADED );
	if ( qm2_gameState.camera == nullptr )
	{
		game_error_( "Failed to create default camera!\n" );
		return false;
	}

	return true;
}

static void spawn_world( ApeRoom *room )
{
}

static void server_tick( double delta )
{
}

static void client_tick( double delta )
{
	ape_audio_clear_listener();

	PLVector3 cpos = ape_camera_get_position( qm2_gameState.camera );
	PLVector3 cang = ape_camera_get_angles( qm2_gameState.camera );

	ape_audio_update_listener( &cpos, &cang, &pl_vecOrigin3 );
}

static bool request_handler( ApeGameInterfaceRequest request, void *user )
{
	switch ( request )
	{
		default:
			break;
		case APE_GAME_INTERFACE_REQUEST_INITIALIZE:
			return initialize_game();
	}

	return false;
}

const ApeGameInterfaceImport *ape_game_get_interface()
{
	static ApeGameInterfaceImport gameMode = {
	        .version         = APE_GAME_INTERFACE_VERSION,
	        .protocolVersion = QM2_PROTOCOL_VERSION,
	        .identifier      = "qm2",

	        .requestCallbackMethod = request_handler,

	        .spawnWorld = spawn_world,

	        .serverClientValidate     = game_server_client_validate_,
	        .serverClientConnected    = game_server_client_connected_,
	        .serverClientDisconnected = game_server_client_disconnected_,
	        .serverProcessMessage     = game_server_process_message_,
	        .serverTick               = server_tick,

	        .clientConnect        = game_client_connected_,
	        .clientDisconnect     = game_client_disconnected_,
	        .clientProcessMessage = game_client_process_message_,
	        .clientTick           = client_tick,
	};
	return &gameMode;
}
