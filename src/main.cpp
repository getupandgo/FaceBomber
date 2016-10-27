#include "faceBomber.h"

int main() {
    FaceBomber *bomber = new FaceBomber();
    std::string imgPath("/home/getupandgo/projects/FaceBomber/imagesToBomb/example.jpeg");
//    bomber->addFaceForBombing("harold", "/home/getupandgo/projects/FaceBomber/facesForBombing/harold.jpg");
    std::vector<std::string> newFaces;
    newFaces.push_back("/home/getupandgo/projects/FaceBomber/facesForBombing/harold.jpg");
    bomber->doUglyFaceBomb(imgPath, newFaces);

    delete bomber;
}