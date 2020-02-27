# include "vis.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1940;
const int SCREEN_HEIGHT = 1080;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void	terminate();

SDL_Texture *room_texture = NULL;
SDL_Texture *background_texture = NULL;
SDL_Texture *ant_texture = NULL;

SDL_Renderer *renderer = NULL;
SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;

SDL_Surface *background = NULL;
SDL_Surface *rooms = NULL;
SDL_Surface *ant = NULL;


bool	init_sdl_images()
{
	boolean_t success;

	success = true;
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		printf( "Could not initialize SDL_image! SDL_Error: %s\n", IMG_GetError() );
		success = false;
	}
	return success;
}

bool	init()
{
	bool	success;

	success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
	  	}
	}
	if (!init_sdl_images())
		success = false;
	return success;
}

void     init_textures(void)
{
	renderer = SDL_CreateRenderer(gWindow, -1, 0);
	room_texture = SDL_CreateTextureFromSurface(renderer, rooms);
	background_texture = SDL_CreateTextureFromSurface(renderer, background);
	ant_texture = SDL_CreateTextureFromSurface(renderer, ant);
}

bool	loadMedia()
{
	boolean_t	success;

	success = true;
	background = IMG_Load("/Users/mcanhand/Downloads/space.jpg");
	rooms = IMG_Load("/Users/mcanhand/Downloads/room.png");
	ant = IMG_Load("/Users/mcanhand/Downloads/ant.png");
	if (rooms == NULL)
	{
	    printf("Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError());
	    success = false;
	}
	if (background == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError());
		success = false;
	}
	init_textures();
	return success;
}

void	terminate()
{
	SDL_FreeSurface(background);
	background = NULL;
	SDL_FreeSurface(rooms);
	rooms = NULL;
	SDL_DestroyTexture(room_texture);
	SDL_DestroyTexture(ant_texture);
	SDL_DestroyTexture(background_texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

//int main (int ac, char **av)
//{
//	bool		quit;
//	SDL_Event	e;
//	t_vis_tools	vs;
//
//	if (!init())
//		error_found(ERR_INIT_SDL);
//	else
//	{
//		if (!loadMedia())
//			printf( "Failed to load media!\n" );
//		else
//		{
//			quit = 0;
//			while (!quit)
//			{
//	            while (SDL_PollEvent(&e) != 0)
//	                if (e.type == SDL_QUIT)
//						quit = 1;
////	            vs.renderer;
//				SDL_Rect room_dstrect = { 150, 105, 250, 200 };
//				SDL_Rect ant_dstrect = { 150 + 80, 105 + 50, 70, 100 };
//				SDL_RenderCopy(renderer, background_texture, NULL, NULL);
//
//				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
//				SDL_RenderDrawLine(renderer, 620, 800, 300, 240);
//				SDL_RenderDrawLine(renderer, 620 + 1, 800 + 1, 300 + 1, 240 + 1);
//				SDL_RenderDrawLine(renderer, 620 + 2, 800 + 2, 300 + 2, 240 + 2);
//
//				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//				SDL_RenderCopy(renderer, room_texture, NULL, &room_dstrect);
//				SDL_RenderCopy(renderer, ant_texture, NULL, &ant_dstrect);
//				SDL_RenderPresent(renderer);
//			}
//	    }
//	 }
//	 //Free resources and close SDL
//	 terminate();
//
//	 return 1;
//}

//include_directories(~/Library/Frameworks/SDL2.framework/Headers)
//include_directories(~/Library/Frameworks/SDL2_image.framework/Headers)
//include_directories(~/Library/Frameworks/SDL2_ttf.framework/Headers)
//
//target_link_libraries(visualize_new "-framework SDL2")
//target_link_libraries(visualize_new "-framework SDL2_image")
//target_link_libraries(visualize_new "-framework SDL2_ttf")
//set_target_properties(visualize_new PROPERTIES LINK_FLAGS "-F /Users/$ENV{USER}/Library/Frameworks")



5
##start
		start 0 1
##end
		end 1 0
0 0 0
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
8 8 8
9 9 9
10 10 10
11 11 11
12 12 12
13 13 13
14 14 14
15 15 15
16 16 16
17 17 17
18 18 18
19 19 19
20 20 20
21 21 21
22 22 22
23 23 23
24 24 24
25 25 25
26 26 26
27 27 27
28 28 28
29 29 29
30 30 30
31 31 31
32 32 32
33 33 33
34 34 34
35 35 35
36 36 36
37 37 37
38 38 38
39 39 39
40 40 40
41 41 41
42 42 42
43 43 43
44 44 44
45 45 45
46 46 46
47 47 47
48 48 48
49 49 49
50 50 50
51 51 51
52 52 52
53 53 53
54 54 54
55 55 55
56 56 56
57 57 57
58 58 58
59 59 59
60 60 60
61 61 61
62 62 62
63 63 63
64 64 64
65 65 65
66 66 66
67 67 67
68 68 68
69 69 69
70 70 70
71 71 71
72 72 72
73 73 73
74 74 74
75 75 75
76 76 76
77 77 77
78 78 78
79 79 79
80 80 80
81 81 81
82 82 82
83 83 83
84 84 84
85 85 85
86 86 86
87 87 87
88 88 88
89 89 89
90 90 90
91 91 91
92 92 92
93 93 93
94 94 94
95 95 95
96 96 96
97 97 97
98 98 98
99 99 99
0-93
0-55
1-10
1-75
2-38
3-22
4-61
4-13
4-1
5-53
5-42
6-69
6-80
7-13
7-25
7-41
7-57
8-63
9-97
10-73
11-50
12-20
13-28
14-41
14-2
15-10
16-74
16-22
17-31
17-45
17-36
18-9
19-12
19-6
20-51
20-68
20-95
20-61
21-34
21-41
21-19
22-41
22-93
22-62
22-51
22-67
22-83
22-87
22-91
23-98
24-0
25-49
26-49
27-22
27-46
27-35
27-64
28-77
28-78
29-40
29-62
29-87
29-47
29-19
30-67
30-63
31-51
31-98
31-99
32-58
33-69
33-10
34-23
35-75
36-48
37-5
37-94
37-93
37-50
38-82
38-89
39-28
40-51
40-18
41-58
41-9
42-99
43-61
44-29
45-18
46-34
47-7
48-28
49-84
50-69
50-94
51-98
51-35
52-38
53-46
54-97
54-86
54-43
55-36
56-4
56-45
57-50
57-98
57-5
58-64
59-98
60-40
61-90
62-14
62-97
63-34
63-20
64-62
65-33
66-64
67-0
67-2
68-59
68-55
68-43
68-91
68-32
68-69
68-28
69-39
69-52
70-67
71-24
72-5
73-58
73-56
74-82
75-71
75-36
75-95
75-34
75-87
76-13
76-90
77-62
78-68
78-26
79-89
79-46
80-8
80-3
81-88
81-71
81-61
81-36
82-58
83-84
83-0
84-71
85-79
85-72
86-7
87-50
87-63
87-69
87-93
88-78
89-23
90-25
90-73
90-56
91-72
92-14
92-90
92-15
92-55
93-59
94-89
95-53
96-53
97-43
97-24
98-69
99-48
start-21
start-96
end-16
end-82

L1-21 L2-96
L1-41 L2-53 L3-21
L1-58 L2-46 L3-41 L4-21
L1-82 L2-27 L3-58 L4-41 L5-21
L1-end L2-22 L3-82 L4-58 L5-41
L2-16 L3-end L4-82 L5-58
L2-end L3-end L4-end L5-82
L5-end


//Сделать валидацию--муравей не должен ходить не по ссылкам!
//Сделать вывод количества муравьев в комнате!
//Сделать скейлинг шрифта для названий комнат


