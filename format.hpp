#pragma once
#include <vector>
#include <string>
#include "cmdParser.hpp"
enum GlyphType {
	character_s,
	character_a,
	pronoun,
	article,
	ditto,
};
enum Placement {
	TopRight,
	TopLeft,
	BottomRight,
	BottomLeft,
	Center,
};

struct Glyph {
	std::string subfolder;
	std::string name;
	GlyphType type;
};

struct Square_G : Glyph{
	Square_G* nextSquareGlyph;
	//direction of nextSquareGlyph
	//direction of prevSquareGlyph
};
struct Auxillary_G : Glyph{};
struct Character_S : Square_G{
	GlyphType const type = character_s;
	Character_S* innerGlyph;
};
struct Base_CS : Character_S{
	std::vector<Auxillary_G*> top;
	std::vector<Auxillary_G*> right;
	std::vector<Auxillary_G*> bottom;
	std::vector<Auxillary_G*> left;
};
struct Character_A : Auxillary_G{
	GlyphType const type = character_a;
	Character_A* nextCharAuxGlyph;
};
struct Pronoun_S : Square_G{
	GlyphType const type = pronoun;
};
struct Article_A : Auxillary_G{
	GlyphType const type = article;
};

struct GlyphSet {
	Square_G* base;
};
typedef std::vector<GlyphSet> GlyphSets;
int getGlyphSets (Info &info,GlyphSets &glyphSets);
