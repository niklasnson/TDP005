#include <iostream>
#include <string> 
#include "text.h"
#include "point.h" 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std; 

Text::Text(string t, Point p, SDL_Renderer* r):stext{t},position{p}, renderer{r}
{
}


void Text::update() 
{
	SDL_Rect dstrect;
	TTF_Font *font;
	SDL_Texture* text_texture;
	font = TTF_OpenFont("fonts/slkscre.ttf", 16);
	SDL_Color text_color{0, 0, 0, 255}; // will be an option;
	string s{"tokfint"};

	SDL_Surface* text = TTF_RenderText_Solid(font, stext.c_str(), text_color);
	if (text == NULL)
	{
		cout << "unable to load surface!" << endl;
	}
	
	text_texture = SDL_CreateTextureFromSurface(renderer, text);
	if (text_texture == NULL) 
	{
		cout << "unable to create texture!" << endl; 
	}
	
	SDL_FreeSurface(text);

	SDL_QueryTexture(text_texture, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = position.x; 
	dstrect.y = position.y;

	//SDL_RenderClear(renderer); 
	SDL_RenderCopy(renderer, text_texture, NULL, &dstrect);
	//SDL_RenderPresent(renderer);
	TTF_CloseFont(font);
}


