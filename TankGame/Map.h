#pragma 
#include "GameObject.h"
#include "Vector.h"
#include "Tile.h"
#include <vector>

class Map : public GameObject
{
private:
	std::vector<Tile*> tiles;
	Platform *platform;
public:
	Map();
	void Update() override;
	void Draw() override;
	void Init(Platform *platform) override;
	std::vector<Tile*> *GetTiles();

	~Map();
};

