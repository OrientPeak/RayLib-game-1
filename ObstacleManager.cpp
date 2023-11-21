#include "ObstacleManager.h"

//Main method for grabbing values from main
ObstacleManager::ObstacleManager(Image image, float speed, Vector2 defaultLocation, int spaceLength) {
    mImage = image;
    mSpeed = speed;
    mSpaceLength = spaceLength;
    mDefaultLocation = defaultLocation;
}

ObstacleManager::~ObstacleManager(){

}
//speed setter
void ObstacleManager::setSpeed(float speed) {
    mSpeed = speed;
}
//image setter
void ObstacleManager::setImage(Image image){
    mImage = image;
}
//length setter
void ObstacleManager::setSpaceLength(int spaceLength){
    mSpaceLength = spaceLength;
}
//location setter
void ObstacleManager::setDefaultLocation(Vector2 defaultLocation){
    mDefaultLocation = defaultLocation;
}
//speed getter
float ObstacleManager::getSpeed() {
    return mSpeed;
}
//length getter
int ObstacleManager::getSpaceLength() {
    return mSpaceLength;
}
//obstacles getter
std::vector< Obstacle > ObstacleManager::getObstacles() {
    return mObstacles;
}
//creates obstacles at set position and height
Obstacle ObstacleManager::createObstacle(int position, float height) {
    Obstacle o;
    //make obstacles random height
    if(height < 0)
        height = (rand()%10) * 30;
     //set obstacle parameters
    o.height = height;
    o.width = (float)mImage.width;
    o.location.x = mDefaultLocation.x;
    o.location.y = mDefaultLocation.y - o.height;
    o.position = position;
    //take the immage and copy and rotate for the upside down obstacles
    Image currentImage = ImageCopy(mImage);
    if(position <= 0){
        o.location.y = -o.height - 100;
        ImageRotateCW(&currentImage);
        ImageRotateCW(&currentImage);
        //if not leave right side up
    }else{
        ImageCrop(&currentImage, (Rectangle){0, 0, o.width, o.height});
    }
    //load texture
    o.texture = LoadTextureFromImage(currentImage);
    //unload
    UnloadImage(currentImage);
    //add new element at the end of vector
    mObstacles.push_back(o);
    return o;
}
//removes obstacle at a set index
void ObstacleManager::removeObstacleAtIndex(int index) {
    //get index of obstacle
    Obstacle obstacle = mObstacles.at(index);
    //unload
    UnloadTexture(obstacle.texture);
    //add new element at the end of vector
    mObstacles.push_back(obstacle);
    UnloadTexture(mObstacles.begin().base()->texture);
    mObstacles.erase(mObstacles.begin());
}
//removes obstacle
void ObstacleManager::removeObstacle(Obstacle obstacle) {
    //unload
    UnloadTexture(obstacle.texture);
    //add new element at the end of vector
    mObstacles.push_back(obstacle);
    UnloadTexture(mObstacles.begin().base()->texture);
    mObstacles.erase(mObstacles.begin());
}
//removes first obstacle 
void ObstacleManager::removeFirstObstacle() {
    //check vector size
    if(mObstacles.size() > 0){
        if(mObstacles.begin().base()->location.x < -100){
            UnloadTexture(mObstacles.begin().base()->texture);
            mObstacles.erase(mObstacles.begin());
            UnloadTexture(mObstacles.begin().base()->texture);
            mObstacles.erase(mObstacles.begin());
        }
    }
}
//draw obstacles
void ObstacleManager::drawObstacles() {
    //loop for all obstacles
    for(Obstacle& o : mObstacles){
        //check x location starts off screen
        o.location.x -= mSpeed;
        if(o.position <= 0)
        //draw
            DrawTextureRec(o.texture, (Rectangle){0, 0, o.width, (float)o.texture.height}, o.location, RAYWHITE);
        else
            DrawTextureRec(o.texture, (Rectangle){0, 0, o.width, o.height}, o.location, RAYWHITE);
    }
    removeFirstObstacle();
}
//generates a new obstacle
void ObstacleManager::generateObstacle(float currentPosition) {
    if((int)currentPosition % mSpaceLength == 0 && GetFPS() > 0){
        Obstacle o  = this->createObstacle(1, -1);
        this->createObstacle(0, o.height);
    }
}