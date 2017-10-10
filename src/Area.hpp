#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
#include <string>

using namespace std;

/** An Area instance should only contain a single description that
 *  a room in a map could have. Each possible description should be
 *  loaded in Game.init() in the areas vector.
 */
class Area
{
public:
    Area(const string& description) : description(description) {}

private:

    const string description;
};
#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_AREA_HPP
