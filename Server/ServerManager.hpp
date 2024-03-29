#ifndef SERVER_MANAGER_HPP
#define SERVER_MANAGER_HPP

#include <iostream>
#include "Model.hpp"
#include "ServerSocket.hpp"
#include "../Interfaces.hpp"
#include "../json.hpp"
#include "Physics.hpp"
#include <stdlib.h>     /* srand, rand */
#include "RacingController.hpp"


class ServerManager: public System_Control_Interface, public Input_Handler_Interface
{
public:
	void start();
	bool is_running();
	void receiving_handler(int id, string buffer);
	std::string get_the_updated_model(int player_id);
	void new_player_connected(int player_id);
	void player_desconnected(int player_id);
	bool is_socket_active();

private:
	Model model;
	Physics physics;
	RacingController racing_controller;
	GameState game_state;
	bool is_running_flag;
	float finish_line;

	// Ignore commands from users
	bool is_input_blocked;
	void create_the_map();
};

#endif