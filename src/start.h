#ifndef START_h
#define START_h

#include "game_state.h"
#include "game_object.h"
#include "missile.h"
#include <vector>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

/*! Start */
class Start: public Game_state
{
public:
  /*! Constructor for Start.
   * @param renderer, a SDL_Renderer pointer.
   * @param level, a int argument. 
   * @param quit, a bool argument. 
	 */

  Start(SDL_Renderer*, int, bool &);
  /// Initialize Start
	void init();

private:
	std::map<int, std::vector<Game_object*>> m;
};
#endif
