#pragma once
#include "Vector2.h"

// What members would a sprite class need?
// Texture, Material, UV coordinates

struct Color
{
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 0;
};

struct Texture 
{
	Color pixels[64][64]; // Defining a texture with a size of 64x64
};

// For sake of demonstration purposes
struct Material {};

class Sprite
{
public:
	Texture texture;
	// I think it'd be better to force users to get the material through a function, so you can handle
	// things whenever it's changed.
	Material GetMaterial();
	Material SetMaterial();

private:
	Material material;
	Vector2 uvs;
};