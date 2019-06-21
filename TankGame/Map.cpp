#include "Map.h"

Map::Map()
{
	float r = 2;
	for (int i = 0; i < 27; i++) 
	{
		tiles.push_back(new Tile(Vector(i*32, 0), r));
		tiles.push_back(new Tile(Vector(i * 32, 608), r));
	}
	for (int i = 1; i < 19; i++)
	{
		tiles.push_back(new Tile(Vector(0, i * 32), r));
		tiles.push_back(new Tile(Vector( 832, i * 32), r));
	}

	tiles.push_back(new Tile(Vector(4* 32, 4* 32), r));
	tiles.push_back(new Tile(Vector(4 * 32, 5 * 32), r));
	tiles.push_back(new Tile(Vector(4 * 32, 14 * 32), r));
	tiles.push_back(new Tile(Vector(4 * 32, 15 * 32), r));

	tiles.push_back(new Tile(Vector(5 * 32, 4 * 32), r));
	tiles.push_back(new Tile(Vector(5 * 32, 5 * 32), r));
	tiles.push_back(new Tile(Vector(5 * 32, 6 * 32), r));
	tiles.push_back(new Tile(Vector(5 * 32, 13 * 32), r));
	tiles.push_back(new Tile(Vector(5 * 32, 14 * 32), r));
	tiles.push_back(new Tile(Vector(5 * 32, 15 * 32), r));

	tiles.push_back(new Tile(Vector(6 * 32, 5 * 32), r));
	tiles.push_back(new Tile(Vector(6 * 32, 6 * 32), r));
	tiles.push_back(new Tile(Vector(6 * 32, 7 * 32), r));
	tiles.push_back(new Tile(Vector(6 * 32, 8 * 32), r));
	tiles.push_back(new Tile(Vector(6 * 32, 9 * 32), r));
	tiles.push_back(new Tile(Vector(6 * 32, 13 * 32), r));
	tiles.push_back(new Tile(Vector(6 * 32, 14 * 32), r));

	tiles.push_back(new Tile(Vector(7*32, 13*32), r));
	tiles.push_back(new Tile(Vector(8*32, 13*32), r));
	tiles.push_back(new Tile(Vector(9*32, 13*32), r));
	tiles.push_back(new Tile(Vector(10*32, 13*32), r));

	tiles.push_back(new Tile(Vector(12*32, 4*32), r));
	tiles.push_back(new Tile(Vector(12*32, 5*32), r));
	tiles.push_back(new Tile(Vector(12*32, 6*32), r));
	tiles.push_back(new Tile(Vector(12*32, 7*32), r));

	tiles.push_back(new Tile(Vector(14*32, 12*32), r));
	tiles.push_back(new Tile(Vector(14*32, 13*32), r));
	tiles.push_back(new Tile(Vector(14*32, 14*32), r));
	tiles.push_back(new Tile(Vector(14*32, 15*32), r));

	tiles.push_back(new Tile(Vector(20*32, 5*32), r));
	tiles.push_back(new Tile(Vector(20*32, 6*32), r));
	tiles.push_back(new Tile(Vector(20*32, 10*32), r));
	tiles.push_back(new Tile(Vector(20*32, 11*32), r));
	tiles.push_back(new Tile(Vector(20*32, 12*32), r));
	tiles.push_back(new Tile(Vector(20*32, 13*32), r));
	tiles.push_back(new Tile(Vector(20*32, 14*32), r));

	tiles.push_back(new Tile(Vector(16*32, 6*32), r));
	tiles.push_back(new Tile(Vector(17*32, 6*32), r));
	tiles.push_back(new Tile(Vector(18*32, 6*32), r));
	tiles.push_back(new Tile(Vector(19*32, 6*32), r));

	tiles.push_back(new Tile(Vector(21*32, 4*32), r));
	tiles.push_back(new Tile(Vector(21*32, 5*32), r));
	tiles.push_back(new Tile(Vector(21*32, 6*32), r));
	tiles.push_back(new Tile(Vector(21*32, 13*32), r));
	tiles.push_back(new Tile(Vector(21*32, 14*32), r));
	tiles.push_back(new Tile(Vector(21*32, 15*32), r));

	tiles.push_back(new Tile(Vector(22*32, 4*32), r));
	tiles.push_back(new Tile(Vector(22*32, 5*32), r));
	tiles.push_back(new Tile(Vector(22*32, 14*32), r));
	tiles.push_back(new Tile(Vector(22*32, 15*32), r));

}

void Map::Draw()
{
	for (auto tile : tiles)
	{
		tile->Draw();
	}
}

void Map::Init(Platform *platform)
{
	this->platform = platform;
	for (auto tile : tiles)
	{
		tile->Init(platform);
	}
}

std::vector<Tile *> *Map::GetTiles()
{
	return &tiles;
}

void Map::Update() 
{

}

Map::~Map()
{
}
