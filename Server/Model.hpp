#ifndef MODEL_HPP
#define MODEL_HPP

#include "../json.hpp"
#include "../Interfaces.hpp"

using namespace std;

using json = nlohmann::json;

struct Player
{
	int player_id;
	int place;
	PlayerState player_state;
	string name;
	string ship_model;
	Coordinate position;
	Coordinate speed;
};

struct Planet
{	
	string type;
	Coordinate position;
	bool can_collide;
	float radius;
};

class Model
{
private:
	//map current_map;
	vector<Player> players_data;
	vector<Planet> game_map;
	std::vector<string> results;

	// Private functions
	void player_to_json( Player player, json& j_player);

	void planet_to_json(Planet planet, json& j_planet);
	
public:
	
	void add_planet(Planet planet);
		
	void add_player(Player player);

	void remove_player(int player_id);

	string serialize_model(int player_id, json& j);
	Player get_player(int player_id);
	void update_player(int player_id, Player player);

	std::vector<Player> get_players();
	std::vector<Planet> get_planets();

	void activate_players();
	void update_results(std::vector<string> results);
	std::vector<string> get_results();
};

#endif