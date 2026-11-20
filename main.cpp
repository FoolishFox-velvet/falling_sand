#include <cstring>
#include <raylib.h>
#include <utility>

constexpr int window_width{1500};
constexpr int window_height{900};
constexpr int cellsize{10};
constexpr int num_rows{window_height/cellsize};
constexpr int num_cols{window_width/cellsize};

float grid[num_rows][num_cols];
float empty_grid[num_rows][num_cols];
float hueval = 0.01;
int range = 1;

void Reset(){
    std::memcpy(grid,empty_grid,sizeof(empty_grid));
}


void Update(){
    float new_grid[num_rows][num_cols]{};
    

    for(int r{0}; r < num_rows;r++){
        for(int c{0}; c < num_cols;c++){

            int dir = 1;
            int x = GetRandomValue(0, 1);
            if(x == 0)dir=-1;

            if(grid[r][c]>0){
                if (r + 1 >= num_rows) {
                    new_grid[r][c] = grid[r][c];
                    continue;
                }
                
                if(grid[r+1][c] == 0){
                    new_grid[r+1][c]= grid[r][c];
                }
                else if(grid[r+1][c+dir]==0 && (c + dir < num_cols && c + dir > 0)){
                    new_grid[r+1][c+dir]= grid[r][c];
                }
                else if(grid[r+1][c-dir]==0 && (c - dir < num_cols && c - dir > 0)){
                    new_grid[r+1][c-dir]= grid[r][c];
                }
                else{
                    new_grid[r][c]=grid[r][c];
                }
                
                
            }
        }
    }
    std::swap(grid, new_grid);

    hueval+=0.01;
    if(hueval>=1)hueval=0.01;
}
 
int main(){
	InitWindow(window_width, window_height, "t");
	SetTargetFPS(60);
    
    for(int r{0}; r < num_rows;r++){
        for(int c{0}; c < num_cols;c++){
            empty_grid[r][c]=0;
        }
    }

    Reset();
    
	while(!WindowShouldClose()){    

        Vector2 mousepos = GetMousePosition();
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            if(mousepos.x >= 0 && mousepos.x <= window_width && mousepos.y > 0 && mousepos.y <= window_height){
            int x = int(mousepos.x / cellsize);
            int y = int(mousepos.y / cellsize);
            
           
            for(int dy{-range}; dy <= range; dy+=range){
                for(int dx{-range}; dx <= range; dx+=range){
                    if(y > range-1)
                    grid[y+dy][x+dx]=hueval;
                }
            }

            }
        }

        if(IsKeyPressed(KEY_RIGHT) && range < 5)range++;
        if(IsKeyPressed(KEY_LEFT) && range > 1)range--;
        if(IsKeyPressed(KEY_R))Reset();

        Update();

		BeginDrawing();
		ClearBackground(BLACK);

        
        for(int r{0}; r < num_rows;r++){
            for(int c{0}; c < num_cols;c++){
                if(grid[r][c]>0){
                    Color col{static_cast<unsigned char>(grid[r][c]*255/2),static_cast<unsigned char>(grid[r][c]*255),static_cast<unsigned char>(grid[r][c]*255),255};
                    DrawRectangle(c * cellsize, r * cellsize, cellsize, cellsize, col);
                }
        }
        }

        DrawText(TextFormat("Range: %i", range), 25, 25, 25, WHITE);
		EndDrawing();

    }
	CloseWindow();
	return 0;

}
