#include "../include/Game.h"

Game::Game() :
    m_gameIsRunning{ false }
{
    screen = SDL_CreateWindow("Patterns",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640, 480,
            0);
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE);
    //factories.push_back(new ClayFactory());
    //factories.push_back(new LegoFactory());
    //factories.push_back(new ConcreteFactory());
    //factories.push_back(new TimberFactory());
    

    //for(BricksFactory*factory:factories)
    //{
    //    std::vector<Bricks*>newbricks=factory->getBricks(3);//makes that amount of bricks
     //   for (Bricks*bricks:newbricks)
     //   {
     //       m_bricks.push_back(bricks);
      //  }
   // }
}
    
Game::~Game()
{
    cleanUp();
}
   
   
    

void Game::run()
{
   

    m_gameIsRunning = true;
    SDL_Event event;
    while (m_gameIsRunning)
    {
        proccesevents(event);
        update();
        render();    
    }
}    

void Game::proccesevents(SDL_Event event)
{
    while (SDL_PollEvent(&event)!=0)
    {
        if(event.type==SDL_QUIT)
        {
            m_gameIsRunning = false;//CLOSES GAME LOOP :)
        }
   
        if(event.type==SDL_KEYDOWN)
        {
             m_gameIsRunning = false;//done
        }
        if( event.type == SDL_MOUSEBUTTONDOWN)
        {
        //Get the mouse offsets
        x = event.motion.x;
        y = event.motion.y;
         check_click_in_rect(x,y,r);
        }       
    }
    
}
void Game::update()
{
   
}

/* Function to check if a coordinate (x, y) is inside a rectangle */


void Game::render()
{
   
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 ); // Set color to solid white for sqaure 
   
    
  //squares LEGO     
    r[0].x = 50;
    r[0].y = 25;
    r[0].h = 75;
    r[0].w = 120;

    SDL_RenderFillRect( renderer, &r[0] ); // Draw a filled rectangle

//Sqaure CLAY
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 ); // Set color to solid white for sqaure 2 
    r[1].x = 50;
    r[1].y = 200;
    r[1].h = 75;
    r[1].w = 120;

    SDL_RenderFillRect( renderer, &r[1] ); // Draw a filled rectangle
    

    //Sqaure MUD
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 ); // Set color to solid white for sqaure 2 
    r[1].x = 300;
    r[1].y = 25;
    r[1].h = 75;
    r[1].w = 120;

    SDL_RenderFillRect( renderer, &r[1] ); // Draw a filled rectangle
  

  SDL_Color color = { 0, 0, 0 };



    SDL_RenderPresent(renderer);

//draws them all :) 
    for(Bricks*bricks:m_bricks)
    {
        bricks->render();
    }
}
int  Game::check_click_in_rect(int x, int y,  SDL_Rect rect[4])//main buttons 
{
    
        if (x >= rect[0].x && x < (rect[0].x + rect[0].w))
        {
    
        /* Check Y coordinate is within rectangle range */
        if (y >= rect[0].y && y < (rect[0].y + rect[0].h))
        {
         
        /* X and Y is inside the rectangle */
         std::cout<<"Clicked the Rectangle ";
            return 1;
        }
       }

    if (x >= rect[1].x && x < (rect[1].x + rect[1].w)){

   /* Check Y coordinate is within rectangle range */
        if (y >= rect[1].y && y < (rect[1].y + rect[1].h))
        {
        
    /* X and Y is inside the rectangle */
        std::cout<<"Clicked the 2nd Rectangle ";
        return 1;
        }
    } 

    if (x >= rect[2].x && x < (rect[2].x + rect[2].w)){
/* Check Y coordinate is within rectangle range */
    if (y >= rect[2].y && y < (rect[2].y + rect[2].h))
    {
    
/* X and Y is inside the rectangle */
    std::cout<<"Clicked the 3rd Rectangle ";
    return 1;
    }
    }
    return 0;
}

void Game::cleanUp()
{
    SDL_DestroyWindow(screen);
    SDL_DestroyRenderer(renderer);
    std::cout << "Cleaning up" << std::endl;
}
