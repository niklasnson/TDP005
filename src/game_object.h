#ifndef GAME_OBJECT_h 
#define GAME_OBJECT_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "point.h"
#include <string>

#include "sprite.h"

class Game_object 
{
public:
  /*!
	 * Constructor for GameObject.
	 * @param texture an SDL_Texture pointer.
   * @param point a Point object. 
   * @param renderer a SDL_Renderer pointer.
   * @param sprite_width a int argument.
   * @param sprite_height a int argument.
   * @param sprite_speed a int argument. 
	 */

	Game_object(SDL_Texture* texture, Point point, SDL_Renderer* renderer, int const& sprite_width, int const& sprite_height, int const& sprite_speed);

	virtual ~Game_object();
  //! update object.
	virtual void update() = 0;
	void draw(double const&);
	void draw();
	void set_point(Point const&);
	Point get_point() const; 
	void set_renderer(SDL_Renderer*); 
	SDL_Renderer* get_renderer() const;
	bool is_destroyed() const;
	void destroy();

protected: 
  //std::string img;
	Point cords; /**< Cords as a point object. */
	SDL_Renderer* renderer; /**< Renderer to use. */
	bool destroyed; /**< Bool value. */
	Sprite sprite; /**< Sprite object. */
};
#endif
